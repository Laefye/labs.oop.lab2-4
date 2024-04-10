#ifndef VEC_IMPL_H
#define VEC_IMPL_H
#include "vec.h"

template <typename T>
Vector<T>::Vector(size_t length) {
    this->array = new T[length];
    this->length = length;
}

template <typename T>
Vector<T>::Vector(const Vector<T>& vector) {
    this->array = new T[vector.length];
    std::copy(vector.array, vector.array + vector.length, this->array);
    this->length = vector.length;
}

template <typename T>
Vector<T>::Vector(Vector<T>&& vector) {
    this->array = vector.array;
    this->length = vector.length;
    vector.array = 0;
    vector.length = 0;
}

template <typename T>
Vector<T>::Vector(std::initializer_list<T> list) {
    this->array = new T[list.size()];
    std::copy(list.begin(), list.end(), this->array);
    this->length = list.size();
}

template <typename T>
Vector<T>::~Vector() {
    delete this->array;
}

template <typename T>
size_t Vector<T>::getLength() const {
    return this->length;
}

template <typename T>
void Vector<T>::setElem(size_t index, const T& elem) {
    if (index >= this->length) {
        throw IncorrectIndexException();
    }
    this->array[index] = elem;
}

template <typename T>
T& Vector<T>::getElem(size_t index) const {
    if (index >= this->length) {
        throw IncorrectIndexException();
    }
    return this->array[index];
}

template <typename T>
T* Vector<T>::toArray() {
    T* array = new T[this->length];
    std::copy(this->array, this->array + this->length, array);
    return array;
}

template <typename T>
T& Vector<T>::operator[](size_t index) {
    return this->getElem(index);
}

template <typename T>
const T& Vector<T>::operator[](size_t index) const {
    return this->getElem(index);
}

template <typename _T>
std::ostream& operator<<(std::ostream& os, const Vector<_T>& vector) {
    for (size_t i = 0; i < vector.length; i++) {
        if (i > 0) {
            os << " ";
        }
        os << vector.array[i];
    }
    return os;
}

template <typename T>
Vector<T>& Vector<T>::operator+=(const Vector<T>& vec) {
    if (this->length != vec.length) {
        throw DiffirentSizeException();
    }
    for (size_t i = 0; i < this->length; i++) {
        this->array[i] += vec.array[i];
    }
    return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator-=(const Vector<T>& vec) {
    if (this->length != vec.length) {
        throw DiffirentSizeException();
    }
    for (size_t i = 0; i < this->length; i++) {
        this->array[i] -= vec.array[i];
    }
    return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator*=(const T& elem) {
    for (size_t i = 0; i < this->length; i++) {
        this->array[i] *= elem;
    }
    return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator/=(const T& elem) {
    for (size_t i = 0; i < this->length; i++) {
        this->array[i] /= elem;
    }
    return *this;
}

template <typename _T>
Vector<_T> operator+(const Vector<_T>& veca, const Vector<_T>& vecb) {
    return Vector<_T>(veca) += vecb;
}

template <typename _T>
Vector<_T> operator-(const Vector<_T>& veca, const Vector<_T>& vecb) {
    return Vector<_T>(veca) -= vecb;
}

template <typename _T>
Vector<_T> operator*(const Vector<_T>& vec, const _T& elem) {
    return Vector<_T>(vec) *= elem;
}

template <typename _T>
Vector<_T> operator/(const Vector<_T>& vec, const _T& elem) {
    return Vector<_T>(vec) /= elem;
}

#endif
