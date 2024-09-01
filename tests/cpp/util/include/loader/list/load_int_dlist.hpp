#pragma once

#include <filesystem>
#include <string>
#include <vector>

#include <list/dlist_node.hpp>

#include <boost/json.hpp>

namespace tests::utils {

    class LoadIntDList {
        using DListNode = ds::list::DListNode;
    public:
        DListNode* operator()(std::string input);
        DListNode* operator()(boost::json::array& array);

        DListNode* loadDlist(std::vector<int> values);
    };

} // utils

