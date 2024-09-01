#include "loader/list/load_int_dlist.hpp"

#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>

#include <algorithm>
#include <memory>


namespace tests::utils {

    using namespace ds::list;

    void linkNodes(DListNode* prev, DListNode* next) {
        prev->next = next;
        next->prev = prev;
    }

    DListNode* LoadIntDList::operator()(std::string input) {
        boost::trim(input);

        std::vector<std::string> values;
        boost::split(values, input, boost::is_any_of(","));

        std::vector<int> integers;
        std::transform(std::begin(values), std::end(values),
                       std::back_inserter(integers),
                       [](std::string s) {return boost::lexical_cast<int>(s);});

        return loadDlist(std::move(integers));
    }

    DListNode *LoadIntDList::loadDlist(std::vector<int> values) {
        auto root = std::make_unique<DListNode>(0);
        DListNode* node = root.get();

        for(auto value: values) {
            auto newNode = new DListNode(value);
            linkNodes(node, newNode);
            node = node->next;
        }

        auto head = root->next;
        return head;
    }

    DListNode *LoadIntDList::operator()(boost::json::array &jsonArray) {
        std::vector<int> integers;
        std::transform(std::begin(jsonArray), std::end(jsonArray),
                       std::back_inserter(integers),
                       [](auto& element) { return static_cast<int>(element.get_int64()); });

        return loadDlist(std::move(integers));
    }
} // utils