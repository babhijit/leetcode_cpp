#include "loader/arrays/load_str_array.hpp"

#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>

#include <algorithm>

namespace tests::utils {

    std::vector<std::string> LoadStrArray::operator()(std::string input) {
        boost::trim(input);

        std::vector<std::string> strings;
        boost::split(strings, input, boost::is_any_of(","));

        std::for_each(strings.begin(), strings.end(), [](std::string& str) {
            boost::trim(str);
        });

        return strings;
    }

    std::vector<std::string> LoadStrArray::operator()(boost::json::array &jsonArray) {
        std::vector<std::string> strings;

        for (auto& jsonElement: jsonArray) {
            std::string value = jsonElement.as_string().c_str();
            boost::trim(value);
            strings.push_back(value);
        }

        return strings;

    }

}