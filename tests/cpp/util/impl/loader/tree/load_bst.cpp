#include "loader/tree/load_bst.hpp"

#include "loader/base_loader.hpp"

#include <boost/algorithm/string.hpp>

#include <queue>

using namespace ds::tree;

namespace tests::utils {

    TreeNode *LoadBst::operator()(const std::filesystem::path &file_name) {
        BaseLoader loader;
        auto input = loader.loadFile(file_name);

        return loadBst(std::move(input));
    }

    TreeNode *LoadBst::loadBst(std::string input) {
        boost::trim(input);
        if (input.empty()) {
            return nullptr;
        }

        std::vector<std::string> values;
        boost::split(values, input, boost::is_any_of(","));

        return loadBst(values);
    }

    TreeNode *LoadBst::loadBst(const std::vector<std::string> &values) {
        if (values.empty()) {
            return nullptr;
        }

        TreeNode *root = create(values[0]);

        int index = 0;
        std::queue<TreeNode *> q;
        q.push(root);

        const auto N = values.size();
        while (!q.empty() && (index < N)) {
            auto node = q.front();
            q.pop();

            auto left = index + 1;
            if ((left < N) && (values[left] != "null")) {
                node->left = create(values[left]);
                q.push(node->left);
            }

            auto right = 2 + index;
            if ((right < N) && (values[right] != "null")) {
                node->right = create(values[right]);
                q.push(node->right);
            }

            index = right;
        }

        return root;
    }

    TreeNode *LoadBst::create(const std::string &value) {
        if (value == "null") return nullptr;

        auto int_value = std::stoi(value);
        return new TreeNode(int_value);
    }
}
