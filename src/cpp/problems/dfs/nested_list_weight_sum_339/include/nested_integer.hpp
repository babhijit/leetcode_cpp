#pragma once

#include <optional>
#include <stdexcept>
#include <utility>
#include <vector>

namespace problems::dfs::nested_sum {

    class NestedInteger {
        enum class UnderlyingType {
            INTEGER,
            NESTED_INTEGER,
            NONE
        };

    public:
        NestedInteger() = default;

        explicit NestedInteger(int value) {
            setInteger(value);
        }

        explicit NestedInteger(std::vector<NestedInteger> nestedIntegers) : nestedIntegers_(std::move(nestedIntegers)) {}

        [[nodiscard]] bool isInteger() const {
            return underlyingType_ == UnderlyingType::INTEGER;
        }

        [[nodiscard]] int getInteger() const {
            throwIfNestedTypeMismatches(UnderlyingType::INTEGER);
            return integer_;
        }

        void setInteger(int value) {
            nestedIntegers_.clear();
            underlyingType_ = UnderlyingType::INTEGER;
            integer_ = value;
        }

        void add(const NestedInteger &ni) {
            setUnderlyingType(UnderlyingType::NESTED_INTEGER);
            nestedIntegers_.push_back(ni);
        }

        [[nodiscard]] const std::vector<NestedInteger> &getList() const {
            throwIfNestedTypeMismatches(UnderlyingType::NESTED_INTEGER);
            return nestedIntegers_;
        }

    private:
        void throwIfNestedTypeMismatches(UnderlyingType expectedType) const {
            if (expectedType != underlyingType_) {
                throw std::runtime_error("Type Mismatch of this operation");
            }
        }

        void setUnderlyingType(UnderlyingType type) {
            if (underlyingType_ == UnderlyingType::NONE) {
                underlyingType_ = type;
                return;
            }

            throwIfNestedTypeMismatches(type);
        }

    private:
        std::vector<NestedInteger> nestedIntegers_;
        int integer_{};
        UnderlyingType underlyingType_{UnderlyingType::NONE};
    };

}
