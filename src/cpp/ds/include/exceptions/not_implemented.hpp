#pragma once

#include <stdexcept>

namespace exceptions {

    class NotImplemented : public std::logic_error {
    public:
        NotImplemented();
    };

}
