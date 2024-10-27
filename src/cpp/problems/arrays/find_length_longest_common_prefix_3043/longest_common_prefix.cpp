#include "longest_common_prefix.hpp"

#ifdef UNORDERED_MAP
#include "lcp_unordered_set.hpp"
#else
#include "lcp_trie.hpp"
#endif

namespace problems::arrays::longest_common_prefix {


    int LongestCommonPrefix::longestCommonPrefix(std::vector<int> &arr1, std::vector<int> &arr2) {
#ifdef UNORDERED_MAP
        LCPUnorderedSet lcp;
#else
        LCPTrie lcp;
#endif
        return lcp.longestCommonPrefix(arr1, arr2);
    }

}