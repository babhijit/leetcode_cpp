#include "loader/arrays/load_int_array.hpp"

#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>

#include <algorithm>

namespace tests::utils {

    template<typename Container, typename UnaryFunction>
    std::vector<int> getIntVector(Container& container, UnaryFunction func) {
        std::vector<int> integers;

        std::transform(std::begin(container), std::end(container), std::back_inserter(integers), [&func](auto& element) { return func(element); });

        return integers;
    }

    std::vector<int> LoadIntArray::operator()(std::string input) {
        boost::trim(input);

        std::vector<std::string> values;
        boost::split(values, input, boost::is_any_of(","));

        auto transformer = [](auto& s) {
            return boost::lexical_cast<int>(s);
        };

        return getIntVector(values, std::move(transformer));
    }

    std::vector<int> LoadIntArray::operator()(boost::json::array &json_array) {
        auto transformer = [](auto& element) {
            return static_cast<int>(element.get_int64());
        };

        return getIntVector(json_array, std::move(transformer));
    }

}