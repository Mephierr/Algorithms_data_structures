#ifndef DEC_HPP
#define DEC_HPP
#pragma once

#include <cstddef>
#include <stdexcept>


template<typename T>
class Dec {
private:
    struct Node ;

    Node* head; // Указатель на первый элемент дека
    Node* tail; // Указатель на последний элемент дека
    size_t count; // Количество элементов в деке

public:
    Dec() : head(nullptr), tail(nullptr), count(0) {}

    ~Dec() ;

    // Добавление элемента в начало дека
    void pushFront(const T& element) ;

    // Добавление элемента в конец дека
    void pushBack(const T& element) ;

    // Удаление первого элемента дека
    void popFront() ;

    // Удаление последнего элемента дека
    void popBack() ;

    // Получение первого элемента дека
    T front() const ;

    // Получение последнего элемента дека
    T back() const ;

    // Проверка, пуст ли дек
    bool isEmpty() const ;

    // Получение размера дека
    size_t size() const ;

    // Очистка дека
    void clear() ;

    // Вывод элементов дека
    void print() const ;
};




#include "Dec.cpp" // Включаем реализацию в конце

#endif // DEC_HPP