#ifndef VEC_H
#define VEC_H
#include <initializer_list>
#include <cstddef>
#include <iostream>
#include "exceptions/incorrectindexexception.h"
#include "exceptions/diffirentsizeexception.h"


template <typename T>
class Vector
{
private:
    T* array;
    size_t length;
public:
    Vector(size_t length);
    Vector(const Vector<T>& vector);
    Vector(Vector<T>&& vector);
    explicit Vector(std::initializer_list<T> list);
    ~Vector();

    size_t getLength() const;
    void setElem(size_t index, const T& elem);
    T& getElem(size_t index) const;
    T* toArray();
    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    template <typename _T>
    friend std::ostream& operator<<(std::ostream& os, const Vector<_T>& vector);

    Vector<T>& operator+=(const Vector<T>& vec);
    Vector<T>& operator-=(const Vector<T>& vec);
    Vector<T>& operator*=(const T& elem);
    Vector<T>& operator/=(const T& elem);

    template <typename _T>
    friend Vector<_T> operator+(const Vector<_T>& veca, const Vector<_T>& vecb);
    template <typename _T>
    friend Vector<_T> operator-(const Vector<_T>& veca, const Vector<_T>& vecb);
    template <typename _T>
    friend Vector<_T> operator*(const Vector<_T>& vec, const _T& elem);
    template <typename _T>
    friend Vector<_T> operator/(const Vector<_T>& vec, const _T& elem);
};

#include "vec_imp.h"

#endif // VEC_H
