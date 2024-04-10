#ifndef ITERATOR_IMPL_H
#define ITERATOR_IMPL_H
#include "iterator.h"

template <typename T>
Iterator<T>::Iterator(Vector<T>& vector, int index) : vector(vector) {
    this->index = index;
}

template <typename T>
Iterator<T>::Iterator(const Iterator<T>& iterator) : vector(iterator.vector) {
    this->index = iterator.index;
}

template <typename T>
Iterator<T> Iterator<T>::next() {
    Iterator<T> copy(this->vector, this->index + 1);
    return copy;
}

template <typename T>
T& Iterator<T>::value() {
    return this->vector[index];
}

template <typename T>
bool Iterator<T>::isEnd() {
    return this->index >= vector.getLength();
}

template <typename T>
Iterator<T>& Iterator<T>::operator++() {
    this->index++;
    return *this;
}

template <typename T>
T& Iterator<T>::operator*() {
    return value();
}

template <typename T>
bool Iterator<T>::operator==(const Iterator<T>& b) {
    return this->index == b.index && &this->vector == &b.vector;
}

template <typename T>
bool Iterator<T>::operator!=(const Iterator<T>& b) {
    return !(*this == b);
}

#endif // ITERATOR_H
