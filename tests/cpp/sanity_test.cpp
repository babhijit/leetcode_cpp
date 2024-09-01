#include <gtest/gtest.h>

#include <res/test_resource_utils.hpp>

#include <loader/base_loader.hpp>

#include <boost/json.hpp>

#include <filesystem>

TEST(SanityTest, ResourceAssertions) {
    auto path = tests::utils::getTestResourcePath();
    path /= "dummy.json";

    using namespace tests::utils;
    BaseLoader loader;
    auto jsonStr = loader.loadFile(path);
    auto json = boost::json::parse(jsonStr);

    auto input = json.at("input").as_string();
    auto output = json.at("output").as_string();

    ASSERT_EQ(input, output);
}