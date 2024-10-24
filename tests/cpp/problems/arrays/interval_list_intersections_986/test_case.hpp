#pragma once

#include <loader/json_loader.hpp>
#include <loader/arrays/load_int_matrix.hpp>

#include <boost/json.hpp>

#include <filesystem>
#include <vector>

namespace interval_intersection_tests {

    class TestCase {
    private:
        std::vector<std::vector<int>> firstList_;
        std::vector<std::vector<int>> secondList_;
        std::vector<std::vector<int>> expected_;

    public:
        explicit TestCase(std::filesystem::path const &filePath) {
            tests::utils::JsonLoader loader;
            auto json = loader(filePath);
            firstList_ = loadMatrix(json.at("firstList").as_array());
            secondList_ = loadMatrix(json.at("secondList").as_array());
            expected_ = loadMatrix(json.at("expected").as_array());
        }

        [[nodiscard]] std::vector<std::vector<int>> getFirstList() {
            return firstList_;
        }

        [[nodiscard]] std::vector<std::vector<int>> getSecondList() {
            return secondList_;
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