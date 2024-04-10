#include "incorrectindexexception.h"

IncorrectIndexException::IncorrectIndexException()
{

}

const char* IncorrectIndexException::what() const noexcept {
    return "Incorrect index";
}
