#pragma once

#include <loader/json_loader.hpp>
#include <loader/arrays/load_str_array.hpp>

#include <boost/json.hpp>

#include <filesystem>
#include <set>
#include <string>

namespace min_add_make_valid_param_tests {

    class TestCase {
    private:
        std::string s_;
        int expected_;

    public:
        explicit TestCase(std::filesystem::path const &filePath) {
            tests::utils::JsonLoader loader;
            auto json = loader(filePath);
            s_ = json.at("s").as_string();
            expected_ = static_cast<int>(json.at("expected").as_int64());
        }

        [[nodiscard]] std::string getS() const {
            return s_;
        }

        [[nodiscard]] int getExpected() const {
            return expected_;
        }
    };

}