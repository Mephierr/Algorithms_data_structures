#ifndef VECTOR_HPP
#define VECTOR_HPP
#pragma once

#include <cstddef>
#include <stdexcept>

template <typename T>
class Vector {
private:
    T* data;          // Указатель на массив данных
    size_t capacity;  // Вместимость вектора
    size_t size;      // Текущий размер вектора

    void resize(size_t new_capacity);

public:
    Vector();
    ~Vector();

    void push_back(const T& value);
    void pop_back();
    
    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    size_t get_size() const;
    size_t get_capacity() const;
    bool empty() const;
};

#include "vector.cpp" // Включаем реализацию в конце

#endif // VECTOR_HPP