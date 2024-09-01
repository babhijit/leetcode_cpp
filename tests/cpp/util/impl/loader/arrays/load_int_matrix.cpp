#include "loader/arrays/load_int_matrix.hpp"
#include "loader/arrays/load_int_array.hpp"

namespace tests::utils {

    IntMatrix LoadIntMatrix::operator()(boost::json::array &json_array) {
        LoadIntArray intArrayLoader;

        std::vector<std::vector<int>> result;
        for (auto &element: json_array) {
            result.push_back(intArrayLoader(element.as_array()));
        }
        return result;
    }

}