#pragma once

#include "load_int_array.hpp"

#include <boost/json.hpp>

#include <filesystem>
#include <string>
#include <vector>


namespace tests::utils {
    using IntMatrix = std::vector<std::vector<int>>;

    class LoadIntMatrix {
    public:
        IntMatrix operator()(boost::json::array& jsonArray);
    };
}

