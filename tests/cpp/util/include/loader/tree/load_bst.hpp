#pragma once

#include <filesystem>
#include <string>
#include <vector>

#include <tree/tree_node.hpp>


/**
 * Loads BST Node from resource text file
 */

using namespace ds::tree;

namespace tests::utils {

    class LoadBst {
    public:
        TreeNode *operator()(const std::filesystem::path &file_name);

        TreeNode *loadBst(std::string input);

        TreeNode *loadBst(const std::vector<std::string> &values);

    private:

        TreeNode *create(const std::string &value);
    };

}

