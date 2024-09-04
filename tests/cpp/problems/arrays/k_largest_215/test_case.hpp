#pragma once

#include <loader/json_loader.hpp>
#include <loader/arrays/load_int_array.hpp>

#include <boost/json.hpp>

#include <filesystem>
#include <vector>

namespace k_largest_tests {

    class TestCase {
    private:
        std::vector<int> nums_;
        int k_;
        int expected_;

    public:
        explicit TestCase(std::filesystem::path const &filePath) {
            tests::utils::JsonLoader loader;
            auto json = loader(filePath);
            nums_ = loadVector(json.at("nums").as_array());
            k_ = static_cast<std::int32_t>(json.at("k").as_int64());
            expected_ = static_cast<std::int32_t>(json.at("expected").as_int64());
        }

        std::vector<int> getNums() {
            return nums_;
        }

        [[nodiscard]] int getK() {
            return k_;
        }

        [[nodiscard]] int getExpected() {
            return expected_;
        }


    private:
        static std::vector<int> loadVector(boost::json::array jsonArray) {
            tests::utils::LoadIntArray arrayLoader;
            return arrayLoader(jsonArray);
        }
    };

}