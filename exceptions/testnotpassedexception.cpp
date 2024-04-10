#include "testnotpassedexception.h"

TestNotPassedException::TestNotPassedException(const std::string& description) {
    this->description = "Test not passed (" + description + ")";
}

const char* TestNotPassedException::what() const noexcept {
    return description.c_str();
}
