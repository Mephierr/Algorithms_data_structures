#ifndef QUEUE_HPP
#define QUEUE_HPP
#pragma once

#include <cstddef>
#include <stdexcept>

template<typename T>
class Queue {
private:
    struct Node ;

    Node* front; // Указатель на первый элемент очереди
    Node* back;  // Указатель на последний элемент очереди
    size_t count; // Количество элементов в очереди

public:
    Queue() : front(nullptr), back(nullptr), count(0) {}

    ~Queue() 

    // Добавление элемента в конец очереди
    void enqueue(const T& element) ;

    // Удаление элемента из начала очереди
    void dequeue() ;

    // Получение первого элемента очереди
    T frontElement() const ;

    // Проверка, пуста ли очередь
    bool isEmpty() const ;

    // Получение размера очереди
    size_t size() const ;
};



#include "queue.cpp" // Включаем реализацию в конце

#endif // QUEUE_HPP