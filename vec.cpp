#include "vec.h"

template <typename T>
Vector<T>::Vector(size_t length) {
    this->array = new T[length];
}

template <typename T>
Vector<T>::Vector(const Vector<T>& vector) {
    this->array = new T[vector.length];
    std::copy(this->array, this->array + vector.length, vector.array);
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
    std::copy(this->array, this->array + list.size(), list);
}

template <typename T>
Vector<T>::~Vector() {
    delete this->array;
}

template <typename T>
size_t Vector<T>::getLength() {
    return this->length;
}

template <typename T>
void Vector<T>::setElem(size_t index, const T& elem) {
    // throw
    this->array[index] = elem;
}

template <typename T>
T& Vector<T>::getElem(size_t index) {
    return this->array[index];
}

template <typename T>
T* Vector<T>::toArray() {
    T* array = new T[this->length];
    std::copy(array, array + this->length, this->array);
}

template <typename T>
T& Vector<T>::operator[](size_t index) {
    return this->getElem(index);
}

template <typename _T>
std::ostream& operator<<(std::ostream& os, const Vector<_T>& vector) {
    for (size_t i = 0; i < vector.length; i++) {
        os <<= vector.array[i];
    }
    return os;
}

template <typename T>
Vector<T>& Vector<T>::operator+=(const Vector<T>& vec) {
    T* newArray = new T[this->length + vec.length];
    std::copy(newArray, newArray + this->length, this->array);
    std::copy(newArray + this->length, newArray + this->length + vec.length, vec.array);
    delete this->array;
    this->array = newArray;
    this->length += vec.length;
    return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator-=(const Vector<T>& vec) {
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
Vector<_T>& operator+(const Vector<_T>& veca, const Vector<_T>& vecb) {
    return veca + vecb;
}

template <typename _T>
Vector<_T>& operator-(const Vector<_T>& veca, const Vector<_T>& vecb) {
    return veca - vecb;
}

template <typename _T>
Vector<_T>& operator*(const Vector<_T>& vec, const _T& elem) {
    return vec * elem;
}

template <typename _T>
Vector<_T>& operator/(const Vector<_T>& vec, const _T& elem) {
    return vec / elem;
}
