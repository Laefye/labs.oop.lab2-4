#include "vector.h"
#include "exceptions/testnotpassedexception.h"
#include "exceptions/incorrectindexexception.h"
#include "exceptions/diffirentsizeexception.h"
#include <iostream>
#include <sstream>
#include <iterator.h>

bool checkThreeValues(const Vector<int>& vector, int a, int b, int c) {
    return vector[0] == a && vector[1] == b && vector[2] == c;
}

bool checkThreeValues(int* array, int a, int b, int c) {
    return array[0] == a && array[1] == b && array[2] == c;
}

void testBaseFunctionalVector() {
    Vector<int> a(3);
    if (a.getLength() != 3) {
        throw TestNotPassedException("testBaseFunctionalVector: Incorrect length");
    }
    a[0] = 2;
    a[1] = 4;
    a[2] = -1;
    if (!checkThreeValues(a, 2, 4, -1)) {
        throw TestNotPassedException("testBaseFunctionalVector: Incorrect saved values");
    }
    int* array = a.toArray();
    if (!checkThreeValues(array, 2, 4, -1)) {
        throw TestNotPassedException("testBaseFunctionalVector: Incorrect saved values in created array");
    }
    delete[] array;

    Vector<int> d{1, 0, 3};
    if (!checkThreeValues(d, 1, 0, 3)) {
        throw TestNotPassedException("testBaseFunctionalVector: Constructor by list don't file correctly");
    }

    Vector<int> copy(d);
    copy[0] = 2;
    if (!checkThreeValues(copy, 2, 0, 3)) {
        throw TestNotPassedException("testBaseFunctionalVector: Copied vector has incorrect values");
    }
    if (!checkThreeValues(copy, 2, 0, 3) || !checkThreeValues(d, 1, 0, 3)) {
        throw TestNotPassedException("testBaseFunctionalVector: Copied vector has same array with original");
    }
    Vector<int> moved = std::move(copy);
    if (!checkThreeValues(moved, 2, 0, 3)) {
        throw TestNotPassedException("testBaseFunctionalVector: Vector didn't moved properly");
    }
    std::stringstream str;
    str << moved;
    if (str.str() != "2 0 3") {
        throw TestNotPassedException("testBaseFunctionalVector: Output in stream don't work");
    }
}

void testVectorMathOperations() {
    Vector<int> a{1,2,3};
    Vector<int> b{3,2,1};
    a+=b;
    a*=2;
    if (!checkThreeValues(a, 8, 8, 8)) {
        throw TestNotPassedException("testVectorMathOperations: Sum and multiplication of vectors are incorrect");
    }
    Vector<int> c = a + b;
    if (!checkThreeValues(c, 11, 10, 9)) {
        throw TestNotPassedException("testVectorMathOperations: Sum of vectors are incorrect (using other operator)");
    }
}

void testVectorExceptions() {
    Vector<int> a(1);
    bool isPassed = false;
    try {
        a[2] = 3;
    } catch (IncorrectIndexException& exception) {
        isPassed = true;
    }
    if (!isPassed) {
        throw TestNotPassedException("testVectorExceptions: There's not exception when set incorrect index");
    }
    isPassed = false;
    try {
        a += Vector<int>{3, 4};
    } catch (DiffirentSizeException& exception) {
        isPassed = true;
    }
    if (!isPassed) {
        throw TestNotPassedException("testVectorExceptions: There's not exception when sum diffirent size vectors");
    }
}

void testIterator() {
    Vector<int> numbers{3,2,1};
    Iterator<int> iter = numbers.begin();
    int i = 0;
    while (iter != numbers.end()) {
        if (numbers[i] != *iter) {
            throw TestNotPassedException("testIterator: Incorrect values");
        }
        i++;
        ++iter;
    }
}

void testVector() {
    try {
        testBaseFunctionalVector();
        testVectorExceptions();
        testVectorMathOperations();
        testIterator();
        std::cout << "Tests passed" << std::endl;
    }  catch (std::exception& exception) {
        std::cout << "Error: " << exception.what() << std::endl;
    }
}

int main(int argc, char *argv[])
{
    testVector();
}
