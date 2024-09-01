#pragma once

#include <boost/json.hpp>

#include <filesystem>
#include <string>
#include <vector>

namespace tests::utils {

    class LoadIntArray {
    public:
        std::vector<int> operator()(std::string input);
        std::vector<int> operator()(boost::json::array& jsonArray);
    };
}
