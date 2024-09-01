#pragma once

#include <filesystem>
#include <string>
#include <vector>

#include <list/list_node.hpp>


namespace tests::utils {

    class LoadIntList {
        using ListNode = ds::list::ListNode;
    public:
        ListNode* operator()(std::string input);

        ListNode* loadList(std::vector<int> values);
    };

} // utils

