#include "min_add_make_valid_paren.hpp"


namespace problems::string::min_add_make_valid_paren {

    int MinAddToMakeValidParen::minAddToMakeValid(std::string s) {
        if (s.empty()) {
            return 0;
        }

        int unmatchedLeftParentheses{};
        int numberOfParenthesesToAdd{};

        for (auto ch : s) {
            if (ch == '(') {
                ++unmatchedLeftParentheses;
            } else {  // encountered ')'
                if (unmatchedLeftParentheses == 0) {
                    ++numberOfParenthesesToAdd;
                } else {
                    --unmatchedLeftParentheses;
                }
            }
        }

        return numberOfParenthesesToAdd + unmatchedLeftParentheses;
    }

}