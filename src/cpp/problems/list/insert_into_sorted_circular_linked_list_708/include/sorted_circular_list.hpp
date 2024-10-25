#pragma once

#include <list/list_node.hpp>

namespace problems::list::insert_into_sorted_clist {

    using namespace ds::list;

    class SortedCircularList {
    public:
        ListNode* insert(ListNode* node, int insertVal);
    };

}