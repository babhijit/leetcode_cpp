#pragma once

#include <loader/json_loader.hpp>
#include <loader/arrays/load_int_array.hpp>

#include <boost/json.hpp>

#include <filesystem>
#include <vector>

namespace length_longest_common_prefix_tests {

    class TestCase {
    private:
        std::vector<int> arr1_;
        std::vector<int> arr2_;
        int expected_;

    public:
        explicit TestCase(std::filesystem::path const &filePath) {
            tests::utils::JsonLoader loader;
            auto json = loader(filePath);
            arr1_ = loadVector(json.at("arr1").as_array());
            arr2_ = loadVector(json.at("arr2").as_array());
            expected_ = static_cast<std::int32_t>(json.at("expected").as_int64());
        }

        std::vector<int> getArr1() {
            return arr1_;
        }

        std::vector<int> getArr2() {
            return arr2_;
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