#include <exceptions/not_implemented.hpp>

namespace exceptions {

        NotImplemented::NotImplemented() : std::logic_error("Not Implemented!") {}

}
