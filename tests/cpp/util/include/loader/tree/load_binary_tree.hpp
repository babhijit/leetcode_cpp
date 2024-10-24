#pragma once

#include <filesystem>
#include <string>
#include <vector>
#include <map>

#include <tree/tree_node.hpp>


/**
 * Loads BST Node from resource text file
 */

using namespace ds::tree;

namespace tests::utils {

    class LoadBinaryTree {
    public:
        TreeNode *operator()(const std::filesystem::path &file_name);

        TreeNode *loadBinaryTree(std::string input);

        TreeNode *loadBinaryTree(std::string input,
                                std::map<int, TreeNode *> &uniqueNodes);

        TreeNode *loadBinaryTree(const std::vector<std::string> &values);

        TreeNode *loadBinaryTree(const std::vector<std::string> &values,
                                 std::map<int, TreeNode*>& uniqueNodes);

    private:

        TreeNode *create(const std::string &value);
    };

}

