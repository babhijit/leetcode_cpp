#pragma once

#include "loader/json_loader.hpp"
#include "loader/arrays/load_int_matrix.hpp"
#include "loader/tree/load_binary_tree.hpp"

#include <tree/tree_node.hpp>

#include <boost/json.hpp>

#include <map>
#include <string>
#include <utility>
#include <vector>

using namespace ds::tree;
using namespace tests::utils;

namespace even_odd_tree_tests {

    class TestCase {
    private:
        TreeNode *root;
        bool expected;

    public:
        explicit TestCase(std::filesystem::path const &file) {
            auto json = getJson(file);

            root = loadBinaryTree(json.at("root"));

            expected = json.at("expected").as_bool();
        }

        [[nodiscard]] bool getExpected() const {
            return expected;
        }

        [[nodiscard]] TreeNode *getRoot() {
            return root;
        }

    private:
        static boost::json::value getJson(std::filesystem::path const &file) {
            JsonLoader loader;
            return loader.loadJson(file);
        }

        TreeNode *loadBinaryTree(boost::json::value &json) {
            auto binaryTreeRoot = json.as_string().c_str();
            return loadBinaryTree(binaryTreeRoot);
        }

    public:
        static TreeNode *loadBinaryTree(std::string const &binaryTreeRoot) {
            LoadBinaryTree bstLoader;
            return bstLoader.loadBinaryTree(binaryTreeRoot);
        }
    };

}