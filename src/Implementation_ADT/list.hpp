#ifndef LIST_HPP
#define LIST_HPP
#pragma once

#include <cstddef>
#include <stdexcept>


template<typename T>
class List {
private:
    struct Node ;

    Node* head; // Указатель на первый элемент списка
    size_t count; // Количество элементов в списке

public:
    List() : head(nullptr), count(0) {}

    ~List() ;
    // Добавление элемента в конец списка
    void append(const T& element) ;

    // Удаление первого элемента списка
    void removeFirst() ;

    // Получение первого элемента списка
    T getFirst() const ;

    // Проверка, пуст ли список
    bool isEmpty() const ;

    // Получение размера списка
    size_t size() const ;

    // Очистка списка
    void clear() ;

    // Вывод элементов списка
    void print() const ;
};



#include "list.cpp" // Включаем реализацию в конце

#endif // LIST_HPP