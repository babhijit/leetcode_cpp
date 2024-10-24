#include "loader/tree/load_binary_tree.hpp"

#include "loader/base_loader.hpp"

#include <boost/algorithm/string.hpp>

#include <queue>
#include <utility>

using namespace ds::tree;

namespace tests::utils {

    TreeNode *LoadBinaryTree::operator()(const std::filesystem::path &file_name) {
        BaseLoader loader;
        auto input = loader.loadFile(file_name);

        return loadBinaryTree(std::move(input));
    }

    TreeNode *LoadBinaryTree::loadBinaryTree(std::string input,
                                             std::map<int, TreeNode *> &uniqueNodes) {
        boost::trim(input);
        if (input.empty()) {
            return nullptr;
        }

        std::vector<std::string> values;
        boost::split(values, input, boost::is_any_of(","));

        return loadBinaryTree(values, uniqueNodes);
    }

    TreeNode *LoadBinaryTree::loadBinaryTree(std::string input) {
        std::map<int, TreeNode *> uniqueNodes;
        return loadBinaryTree(std::move(input), uniqueNodes);
    }

    void updateUniqueNodes(TreeNode* node, std::map<int, TreeNode *> &uniqueNodes) {
        if (uniqueNodes.empty()) {
            return;
        }

        auto it = uniqueNodes.find(node->val);
        if (it != uniqueNodes.end()) {
            it->second = node;
        }
    }

    TreeNode *LoadBinaryTree::loadBinaryTree(const std::vector<std::string> &values,
                                             std::map<int, TreeNode *> &uniqueNodes) {
        if (values.empty()) {
            return nullptr;
        }

        TreeNode *root = create(values[0]);

        int index = 0;
        std::queue<TreeNode *> q;
        q.push(root);

        updateUniqueNodes(root, uniqueNodes);

        const auto N = values.size();
        while (!q.empty() && (index < N)) {
            auto node = q.front();
            q.pop();

            auto left = index + 1;
            if ((left < N) && (values[left] != "null")) {
                node->left = create(values[left]);
                q.push(node->left);
                updateUniqueNodes(node->left, uniqueNodes);
            }

            auto right = 2 + index;
            if ((right < N) && (values[right] != "null")) {
                node->right = create(values[right]);
                updateUniqueNodes(node->right, uniqueNodes);
                q.push(node->right);
            }

            index = right;
        }

        return root;
    }

    TreeNode *LoadBinaryTree::loadBinaryTree(const std::vector<std::string> &values) {
        std::map<int, TreeNode *> lookupNodes;
        return loadBinaryTree(values, lookupNodes);
    }

    TreeNode *LoadBinaryTree::create(const std::string &value) {
        if (value == "null") return nullptr;

        auto int_value = std::stoi(value);
        return new TreeNode(int_value);
    }
}
