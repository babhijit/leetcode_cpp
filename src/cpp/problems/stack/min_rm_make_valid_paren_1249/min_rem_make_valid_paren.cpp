#include "min_rem_make_valid_paren.hpp"

#include <sstream>
#include <stack>
#include <unordered_set>

/**
 * Space Complexity: O(n)
 * Time Complexity: O(n)
 */

namespace problems::stack::min_rm_valid_paren {

    std::string MinRemMakeValidParen::minRemoveToMakeValid(std::string s) {
        std::unordered_set<int> indicesToRemove;
        std::stack<int> stack;

        for(int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                stack.push(i);
            } else if (s[i] == ')') {
                if (stack.empty()) {
                    indicesToRemove.insert(i);
                } else {
                    stack.pop();
                }
            }
        }

        // Put any unmatched indices to be removed
        while (not stack.empty()) {
            indicesToRemove.insert(stack.top());
            stack.pop();
        }

        std::ostringstream oss;
        for (int i = 0; i < s.size(); ++i) {
            if (not indicesToRemove.contains(i)) {
                oss << s[i];
            }
        }

        return oss.str();
    }
}