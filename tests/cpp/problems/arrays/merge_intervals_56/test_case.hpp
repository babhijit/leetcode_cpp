#pragma once

#include <loader/json_loader.hpp>
#include <loader/arrays/load_int_matrix.hpp>

#include <boost/json.hpp>

#include <filesystem>
#include <vector>

namespace merge_intervals_tests {

    class TestCase {
    private:
        std::vector<std::vector<int>> intervals_;
        std::vector<std::vector<int>> expected_;

    public:
        explicit TestCase(std::filesystem::path const &filePath) {
            tests::utils::JsonLoader loader;
            auto json = loader(filePath);
            intervals_ = loadMatrix(json.at("intervals").as_array());
            expected_ = loadMatrix(json.at("expected").as_array());
        }

        [[nodiscard]] std::vector<std::vector<int>> getNums() {
            return intervals_;
        }

        [[nodiscard]] std::vector<std::vector<int>> getExpected() {
            return expected_;
        }


    private:
        static std::vector<std::vector<int>> loadMatrix(boost::json::array jsonArray) {
            tests::utils::LoadIntMatrix matrixLoader;
            return matrixLoader(jsonArray);
        }
    };

}