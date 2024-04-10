#include "diffirentsizeexception.h"

DiffirentSizeException::DiffirentSizeException()
{

}

const char* DiffirentSizeException::what() const noexcept {
    return "Diffirent size";
}
