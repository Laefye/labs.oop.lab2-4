#ifndef INCORRECTINDEXEXCEPTION_H
#define INCORRECTINDEXEXCEPTION_H
#include <exception>


class IncorrectIndexException : public std::exception
{
public:
    IncorrectIndexException();

    const char* what() const noexcept override;
};

#endif // INCORRECTINDEXEXCEPTION_H
