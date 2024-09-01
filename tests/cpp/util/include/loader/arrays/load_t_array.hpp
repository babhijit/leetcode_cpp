#pragma once

#include "loader/base_loader.hpp"


#include <filesystem>
#include <string>
#include <vector>


namespace dsa::tests::utils {

    template <typename T, typename Transformer>
    class LoadTArray : public BaseLoader {
    private:
        Transformer transformer_;

    public:
        LoadTArray() : transformer_{} {}
        explicit LoadTArray(Transformer transformer) : transformer_(std::move(transformer)) {}

    public:
        std::vector<T> operator()(boost::json::array& json_array) {
            std::vector<T> tVector;

            std::transform(std::begin(json_array), std::end(json_array), std::back_inserter(tVector), [this](auto& element) { return transformer_(element); });

            return tVector;
        }
    };
}
