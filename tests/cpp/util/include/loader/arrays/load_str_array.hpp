#pragma once

#include <boost/json.hpp>

#include <filesystem>
#include <string>
#include <vector>

namespace tests::utils {

    class LoadStrArray {
    public:
        std::vector<std::string> operator()(std::string input);
        std::vector<std::string> operator()(boost::json::array& jsonArray);
    };

}