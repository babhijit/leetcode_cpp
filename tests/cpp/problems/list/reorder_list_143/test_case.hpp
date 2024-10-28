#pragma once

#include <loader/json_loader.hpp>
#include <loader/arrays/load_int_array.hpp>
#include <loader/list/load_int_list.hpp>

#include <list/list_node.hpp>

#include <boost/json.hpp>

#include <filesystem>
#include <vector>

using namespace ds::list;

namespace reorder_list_tests {

    class TestCase {
    private:
        ListNode *head_;
        ListNode *expected_;

    public:
        explicit TestCase(std::filesystem::path const &filePath) {
            tests::utils::JsonLoader loader;
            auto json = loader(filePath);
            head_ = loadList(json.at("head").as_array());
            expected_ = loadList(json.at("expected").as_array());;
        }

        ListNode *getHead() {
            return head_;
        }

        ListNode *getExpected() {
            return expected_;
        }

    private:
        static ListNode *loadList(boost::json::array jsonArray) {
            tests::utils::LoadIntArray intArrayLoader;
            auto intValues = intArrayLoader(jsonArray);

            tests::utils::LoadIntList intListLoader;
            auto head = intListLoader.loadList(std::move(intValues));
            return head;
        }
    };

}