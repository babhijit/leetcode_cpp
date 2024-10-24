#pragma once

#include <filesystem>
#include <string>
#include <vector>
#include <map>

#include <tree/tree_parent_node.hpp>


/**
 * Loads BST Node from resource text file
 */

using namespace ds::tree;

namespace tests::utils {

    class LoadBinaryWithParentTree {
    public:
        TreeParentNode *operator()(const std::filesystem::path &file_name);

        TreeParentNode *loadBinaryTree(std::string input);

        TreeParentNode *loadBinaryTree(std::string input,
                                std::map<int, TreeParentNode *> &uniqueNodes);

        TreeParentNode *loadBinaryTree(const std::vector<std::string> &values);

        TreeParentNode *loadBinaryTree(const std::vector<std::string> &values,
                                 std::map<int, TreeParentNode*>& uniqueNodes);

    private:

        static TreeParentNode *create(const std::string &value, TreeParentNode* parent = nullptr);
    };

}

