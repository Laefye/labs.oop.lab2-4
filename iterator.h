#ifndef ITERATOR_H
#define ITERATOR_H
#include "vec.h"

template <typename T>
class Iterator
{
private:
    Vector<T>& vector;
    size_t index;
public:
    Iterator(Vector<T>& vector, int index);
    Iterator(const Iterator<T>& iterator);

    Iterator<T> next();
    T& value();
    bool isEnd();

    Iterator<T>& operator++();
    T& operator*();

    bool operator==(const Iterator<T>& b);
    bool operator!=(const Iterator<T>& b);
};

#include "iterator_impl.h"

#endif // ITERATOR_H
