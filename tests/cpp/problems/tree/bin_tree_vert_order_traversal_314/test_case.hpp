#pragma once

#include "loader/json_loader.hpp"
#include "loader/arrays/load_int_matrix.hpp"
#include "loader/tree/load_bst.hpp"

#include <boost/json.hpp>

#include <string>
#include <utility>
#include <vector>

using namespace ds::tree;
using namespace tests::utils;

class TestCase {
private:
    TreeNode *input;
    IntMatrix expected;

public:
    explicit TestCase(std::filesystem::path const &file) {
        auto json = getJson(file);
        input = loadBst(json.at("input"));
        expected = loadMatrix(json.at("expected").as_array());
    }

    [[nodiscard]] IntMatrix getExpected() const {
        return expected;
    }

    [[nodiscard]] TreeNode *getInput() {
        return input;
    }

private:
    static boost::json::value getJson(std::filesystem::path const &file) {
        JsonLoader loader;
        return loader.loadJson(file);
    }

    static TreeNode *loadBst(boost::json::value &json) {
        auto bstInput = json.as_string().c_str();
        return loadBst(bstInput);
    }

public:
    static TreeNode *loadBst(std::string const &bstInput) {
        LoadBst bstLoader;
        return bstLoader.loadBst(bstInput);
    }

    static IntMatrix loadMatrix(boost::json::array jsonMatrix) {
        LoadIntMatrix intMatrixLoader;
        return intMatrixLoader(jsonMatrix);
    }
};
