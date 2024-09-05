#pragma once

#include <loader/json_loader.hpp>
#include <loader/arrays/load_int_matrix.hpp>

#include <boost/json.hpp>

#include <filesystem>
#include <vector>

namespace k_closest_tests {

    class TestCase {
    private:
        std::vector<std::vector<int>> points_;
        int k_;
        std::vector<std::vector<int>> expected_;

    public:
        explicit TestCase(std::filesystem::path const &filePath) {
            tests::utils::JsonLoader loader;
            auto json = loader(filePath);
            points_ = loadMatrix(json.at("points").as_array());
            k_ = static_cast<std::int32_t>(json.at("k").as_int64());
            expected_ =loadMatrix(json.at("expected").as_array());
        }

        std::vector<std::vector<int>> getPoints() {
            return points_;
        }

        [[nodiscard]] int getK() {
            return k_;
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