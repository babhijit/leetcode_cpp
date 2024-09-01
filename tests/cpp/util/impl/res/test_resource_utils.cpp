#include "res/test_resource_utils.hpp"

#include <filesystem>

namespace tests::utils {

    std::filesystem::path getTestResourcePath() {
        namespace fs = std::filesystem;
        auto path = fs::current_path();

        path /= "resources";

        return path;
    }

}