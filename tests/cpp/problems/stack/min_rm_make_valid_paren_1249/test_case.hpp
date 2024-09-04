#pragma once

#include <loader/json_loader.hpp>
#include <loader/arrays/load_str_array.hpp>

#include <boost/json.hpp>

#include <filesystem>
#include <set>
#include <string>

namespace min_rm_make_valid_param_tests {

    class TestCase {
    private:
        std::string s_;
        std::set<std::string> expected_;

    public:
        explicit TestCase(std::filesystem::path const &filePath) {
            tests::utils::JsonLoader loader;
            auto json = loader(filePath);
            s_ = json.at("s").as_string();
            expected_ = getExpected(json.at("expected").as_array());
        }

        [[nodiscard]] std::string getS() const {
            return s_;
        }

        [[nodiscard]] std::set<std::string> getExpected() const {
            return expected_;
        }

    private:
        std::set<std::string> getExpected(boost::json::array &jsonArray) {
            tests::utils::LoadStrArray loadStrArray;
            auto strings = loadStrArray(jsonArray);
            return {strings.begin(), strings.end()};
        }
    };

}