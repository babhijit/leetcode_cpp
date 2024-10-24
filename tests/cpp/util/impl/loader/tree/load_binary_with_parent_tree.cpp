#include "loader/tree/load_binary_with_parent_tree.hpp"

#include "loader/base_loader.hpp"

#include <boost/algorithm/string.hpp>

#include <queue>
#include <utility>

using namespace ds::tree;

namespace tests::utils {

    TreeParentNode *LoadBinaryWithParentTree::operator()(const std::filesystem::path &file_name) {
        BaseLoader loader;
        auto input = loader.loadFile(file_name);

        return loadBinaryTree(std::move(input));
    }

    TreeParentNode *LoadBinaryWithParentTree::loadBinaryTree(std::string input,
                                             std::map<int, TreeParentNode *> &uniqueNodes) {
        boost::trim(input);
        if (input.empty()) {
            return nullptr;
        }

        std::vector<std::string> values;
        boost::split(values, input, boost::is_any_of(","));

        return loadBinaryTree(values, uniqueNodes);
    }

    TreeParentNode *LoadBinaryWithParentTree::loadBinaryTree(std::string input) {
        std::map<int, TreeParentNode *> uniqueNodes;
        return loadBinaryTree(std::move(input), uniqueNodes);
    }

    void updateUniqueNodes(TreeParentNode* node, std::map<int, TreeParentNode *> &uniqueNodes) {
        if (uniqueNodes.empty()) {
            return;
        }

        auto it = uniqueNodes.find(node->val);
        if (it != uniqueNodes.end()) {
            it->second = node;
        }
    }

    TreeParentNode *LoadBinaryWithParentTree::loadBinaryTree(const std::vector<std::string> &values,
                                             std::map<int, TreeParentNode *> &uniqueNodes) {
        if (values.empty()) {
            return nullptr;
        }

        TreeParentNode *root = create(values[0]);

        int index = 0;
        std::queue<TreeParentNode *> q;
        q.push(root);

        updateUniqueNodes(root, uniqueNodes);

        const auto N = values.size();
        while (!q.empty() && (index < N)) {
            auto node = q.front();
            q.pop();

            auto left = index + 1;
            if ((left < N) && (values[left] != "null")) {
                node->left = create(values[left], node);
                q.push(node->left);
                updateUniqueNodes(node->left, uniqueNodes);
            }

            auto right = 2 + index;
            if ((right < N) && (values[right] != "null")) {
                node->right = create(values[right], node);
                updateUniqueNodes(node->right, uniqueNodes);
                q.push(node->right);
            }

            index = right;
        }

        return root;
    }

    TreeParentNode *LoadBinaryWithParentTree::loadBinaryTree(const std::vector<std::string> &values) {
        std::map<int, TreeParentNode *> lookupNodes;
        return loadBinaryTree(values, lookupNodes);
    }

    TreeParentNode *LoadBinaryWithParentTree::create(const std::string &value, TreeParentNode* parent) {
        if (value == "null") return nullptr;

        auto intValue = std::stoi(value);
        return new TreeParentNode(intValue, parent);
    }
}
