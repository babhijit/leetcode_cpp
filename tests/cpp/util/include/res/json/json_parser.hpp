#ifndef ALGO_CPP_JSON_PARSER_HPP
#define ALGO_CPP_JSON_PARSER_HPP

#include <boost/json.hpp>

#include <filesystem>
#include <fstream>

#include "res/json/mapper/mapper.hpp"

namespace dsa::tests::utils {

    template<typename T>
    class JsonParser {
    private:
        Mapper<T> mapper_;
        const std::filesystem::path filename_;

    public:
        explicit JsonParser(std::filesystem::path filename, Mapper<T> mapper) :
                filename_(std::move(filename)),
                mapper_(std::move(mapper)) {}

        T parse() const {
            using namespace boost::json;
        }

    };

}

#endif //ALGO_CPP_JSON_PARSER_HPP
