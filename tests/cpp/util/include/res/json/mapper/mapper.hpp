#pragma once

#include <boost/json/src.hpp>

#include <vector>

namespace dsa::tests::utils {

    template <typename T>
    class Mapper {
    public:
        T create(const std::vector<std::string>& elements);

        T create(const std::string& value);
    };

}
