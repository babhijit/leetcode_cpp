#pragma once

#include <vector>

/**
 * m = len(arr1)
 * n = len(arr2)
 * O(d) = time to insert a single digit into trie
 * TimeComplexity: O(m*d + n*d) => O(m + n)
 * Space Complexity: O(m*d) => O(m)
 */

namespace problems::arrays::longest_common_prefix {

    struct TrieNode {
        TrieNode *children[10] = {};
    };

    class Trie {
    public:
        void insert(int n) {
            insert(std::to_string(n), &root);
        }

        int findLongestPrefix(int n) {
            return findLongestPrefix(
                    std::to_string(n),
                    &root
            );
        }

    private:
        static int toInteger(char digit) {
            return digit - '0';
        }

        void insert(std::string number, TrieNode *node) {
            for (auto digit: number) {
                auto idx = toInteger(digit);;
                if (not node->children[idx]) {
                    node->children[idx] = new TrieNode;
                }
                // this takes to the next level
                node = node->children[idx];
            }
        }

        int findLongestPrefix(std::string number, TrieNode *node) {
            auto prefixLength = 0;

            for (char digit: number) {
                auto idx = toInteger(digit);
                if (not node->children[idx]) {
                    break;
                }

                ++prefixLength;
                node = node->children[idx];
            }

            return prefixLength;
        }

    private:
        TrieNode root;
    };

    class LCPTrie {
    public:
        int longestCommonPrefix(std::vector<int> &arr1, std::vector<int> &arr2) {
            Trie trie;

            for (auto val: arr1) {
                trie.insert(val);
            }

            int longestPrefix{};
            for (auto val: arr2) {
                auto prefixLength = trie.findLongestPrefix(val);
                longestPrefix = std::max(longestPrefix, prefixLength);
            }

            return longestPrefix;
        }

    };

}
