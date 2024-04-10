#ifndef TESTNOTPASSEDEXCEPTION_H
#define TESTNOTPASSEDEXCEPTION_H
#include <exception>
#include <string>


class TestNotPassedException : public std::exception
{
private:
    std::string description;
public:
    TestNotPassedException(const std::string& description);

    const char* what() const noexcept override;
};

#endif // TESTNOTPASSEDEXCEPTION_H
