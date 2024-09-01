#pragma once

#include <functional>
#include <filesystem>

namespace tests::utils {

    class TestCaseLoader {
        using TestRunner = std::function<void(const std::filesystem::directory_entry &)>;
    public:
        void operator()(std::filesystem::path &directoryPath, TestRunner testRunner);

    private:
        static void loadTestCase(std::filesystem::path &directoryPath, TestRunner testRunner);
    };

}