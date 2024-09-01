#pragma once

#include <queue>
#include <vector>

#include "tree/tree_node.hpp"
#include "res/json/mapper/mapper.hpp"

namespace dsa::tests::utils {

    using namespace boost::json;

    std::vector<std::string> tag_invoke(value_to_tag<std::vector<std::string>>, value const& jv) {
        object const& obj = jv.as_object();
        return value_to<std::vector<std::string>>(obj.at("root"));
    }

    template<>
    class Mapper<dsa::ds::tree::TreeNode*> {
        using TreeNode = dsa::ds::tree::TreeNode;
    public:

        TreeNode* create(const std::vector<std::string>& tree_elements) {
            if (tree_elements.empty()) {
                return nullptr;
            }

            TreeNode* root = create(tree_elements[0]);

            int index = 0;
            std::queue<TreeNode*> q;
            q.push(root);

            const auto N =  tree_elements.size();
            while(!q.empty() && (index < N)) {
                auto node = q.front();
                q.pop();

                auto left = index + 1;
                if ((left < N) && (tree_elements[left] != "null")) {
                    node->left = create(tree_elements[left]);
                    q.push(node->left);
                }

                auto right = index + 2;
                if ((right < N) && (tree_elements[right] != "null")) {
                    node->right = create(tree_elements[right]);
                    q.push(node->right);
                }

                index = right;
            }

            return root;
        }

        TreeNode* create(const std::string& value) {
            if (value == "null")    return nullptr;

            auto int_value = std::stoi(value);
            return new TreeNode(int_value);
        }
    };
}

