#ifndef VEC_H
#define VEC_H
#include <initializer_list>
#include <cstddef>
#include <iostream>


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

    size_t getLength();
    void setElem(size_t index, const T& elem);
    T& getElem(size_t index);
    T* toArray();
    T& operator[](size_t index);

    template <typename _T>
    friend std::ostream& operator<<(std::ostream& os, const Vector<_T>& vector);

    Vector<T>& operator+=(const Vector<T>& vec);
    Vector<T>& operator-=(const Vector<T>& vec);
    Vector<T>& operator*=(const T& elem);
    Vector<T>& operator/=(const T& elem);

    template <typename _T>
    friend Vector<_T>& operator+(const Vector<_T>& veca, const Vector<_T>& vecb);
    template <typename _T>
    friend Vector<_T>& operator-(const Vector<_T>& veca, const Vector<_T>& vecb);
    template <typename _T>
    friend Vector<_T>& operator*(const Vector<_T>& vec, const _T& elem);
    template <typename _T>
    friend Vector<_T>& operator/(const Vector<_T>& vec, const _T& elem);
};

template<typename D>
class Meoww {
public:
    Meoww();
    ~Meoww() = default;
};

template<typename D>
Meoww<D>::Meoww() {

}


#endif // VEC_H
