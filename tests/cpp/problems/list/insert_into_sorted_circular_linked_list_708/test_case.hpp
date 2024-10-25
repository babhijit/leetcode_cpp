#pragma once

#include <loader/json_loader.hpp>
#include <loader/arrays/load_int_array.hpp>
#include <loader/list/load_int_list.hpp>

#include <list/list_node.hpp>

#include <boost/json.hpp>

#include <filesystem>
#include <vector>

using namespace ds::list;

namespace insert_into_sorted_clist_tests {

    class TestCase {
    private:
        ListNode *head_;
        int insertVal_;
        ListNode *expected_;

    public:
        explicit TestCase(std::filesystem::path const &filePath) {
            tests::utils::JsonLoader loader;
            auto json = loader(filePath);
            head_ = loadCircularList(json.at("head").as_array());
            insertVal_ = static_cast<int>(json.at("insertVal").as_int64());
            expected_ = loadCircularList(json.at("expected").as_array());;
        }

        ListNode *getHead() {
            return head_;
        }

        [[nodiscard]] int getInsertVal() const {
            return insertVal_;
        }

        ListNode *getExpected() {
            return expected_;
        }

    private:
        static ListNode *loadCircularList(boost::json::array jsonArray) {
            tests::utils::LoadIntArray intArrayLoader;
            auto intValues = intArrayLoader(jsonArray);

            tests::utils::LoadIntList intListLoader;
            auto head = intListLoader.loadList(std::move(intValues));

            if (not head) {
                return nullptr;
            }

            // make it circular
            auto it = head;
            while (it->next) {
                it = it->next;
            }
            it->next = head;
            return head;
        }
    };

}