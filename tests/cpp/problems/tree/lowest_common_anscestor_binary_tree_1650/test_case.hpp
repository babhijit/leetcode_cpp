#pragma once

#include "loader/json_loader.hpp"
#include "loader/arrays/load_int_matrix.hpp"
#include "loader/tree/load_binary_with_parent_tree.hpp"

#include <boost/json.hpp>

#include <map>
#include <string>
#include <utility>
#include <vector>

using namespace ds::tree;
using namespace tests::utils;

class TestCase {
private:
    TreeParentNode *p;
    TreeParentNode *q;
    int expected;

public:
    explicit TestCase(std::filesystem::path const &file) {
        auto json = getJson(file);

        auto [pNode, qNode] = loadBinaryTree(json.at("root"),
                                             static_cast<int>(json.at("p").as_int64()),
                                             static_cast<int>(json.at("q").as_int64()));

        p = pNode;
        q = qNode;
        expected = static_cast<int>(json.at("expected").as_int64());
    }

    [[nodiscard]] int getExpected() const {
        return expected;
    }

    [[nodiscard]] TreeParentNode *getP() {
        return p;
    }

    [[nodiscard]] TreeParentNode *getQ() {
        return q;
    }

private:
    static boost::json::value getJson(std::filesystem::path const &file) {
        JsonLoader loader;
        return loader.loadJson(file);
    }

    static std::pair<TreeParentNode *, TreeParentNode *> loadBinaryTree(boost::json::value &json, int pVal, int qVal) {
        auto binaryTreeRoot = json.as_string().c_str();
        return loadBinaryTree(binaryTreeRoot, pVal, qVal);
    }

public:
    static std::pair<TreeParentNode *, TreeParentNode *> loadBinaryTree(std::string const &binaryTreeRoot,
                                                            int p,
                                                            int q) {
        LoadBinaryWithParentTree bstLoader;

        std::map<int, TreeParentNode *> uniqueNodes{{p, nullptr}, {q, nullptr}};
        bstLoader.loadBinaryTree(binaryTreeRoot, uniqueNodes);
        return {uniqueNodes[p], uniqueNodes[q]};
    }
};
