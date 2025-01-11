#ifndef STACK_HPP
#define STACK_HPP
#pragma once

#include <cstddef>
#include <stdexcept>

template<typename T>
class Stack {
private:
    std::vector<T> elements; // Вектор для хранения элементов стека

public:
    // Добавление элемента в стек
    void push(const T& element) ;

    // Удаление верхнего элемента из стека
    void pop() ;

    // Получение верхнего элемента стека
    T top() const ;

    // Проверка, пустой ли стек
    bool isEmpty() const ;

    // Получение размера стека
    size_t size() const ;
};


#include "stack.cpp" // Включаем реализацию в конце

#endif // CTACK_HPP