#pragma once

#include <filesystem>
#include <string>
#include <vector>

#include <boost/json.hpp>

namespace tests::utils {

    class BaseLoader {

    public:
        std::string loadFile(const std::filesystem::path &file_name);

        std::string operator()(const std::filesystem::path &file_name);
    };

}