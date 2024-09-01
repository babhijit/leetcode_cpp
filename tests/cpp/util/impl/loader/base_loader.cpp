#include "loader/base_loader.hpp"

#include <fstream>

namespace tests::utils {

    std::string BaseLoader::loadFile(const std::filesystem::path &file_name) {
        std::ifstream in(file_name);
        if (!in.is_open()) {
            throw std::runtime_error(file_name.string() + std::string(" could not be opened"));
        }

        const auto sz = std::filesystem::file_size(file_name);
        std::string result(sz, '\0');
        in.read(result.data(), sz);

        return result;
    }

    std::string BaseLoader::operator()(const std::filesystem::path &file_name) {
        return loadFile(file_name);
    }

}