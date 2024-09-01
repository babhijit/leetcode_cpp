#include "loader/list/load_int_list.hpp"

#include <list/list_node.hpp>

#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>

#include <algorithm>
#include <memory>


namespace tests::utils {

    using namespace ds::list;

    ListNode *LoadIntList::operator()(std::string input) {
        boost::trim(input);

        std::vector<std::string> values;
        boost::split(values, input, boost::is_any_of(","));

        std::vector<int> integers;
        std::transform(std::begin(values), std::end(values),
                       std::back_inserter(integers),
                       [](std::string const &s) { return boost::lexical_cast<int>(s); });

        return loadList(std::move(integers));
    }

    ListNode *LoadIntList::loadList(std::vector<int> values) {
        auto root = std::make_unique<ListNode>(0);
        ListNode *node = root.get();

        for (auto value: values) {
            node->next = new ListNode(value);
            node = node->next;
        }

        auto head = root->next;
        return head;
    }
} // utils