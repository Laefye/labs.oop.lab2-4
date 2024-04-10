#ifndef DIFFIRENTSIZEEXCEPTION_H
#define DIFFIRENTSIZEEXCEPTION_H
#include <exception>


class DiffirentSizeException : std::exception
{
public:
    DiffirentSizeException();

    const char* what() const noexcept override;
};

#endif // DIFFIRENTSIZEEXCEPTION_H
