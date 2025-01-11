#include <iostream>
#include <stdexcept>

template<typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;

        Node(const T& data) : data(data), next(nullptr), prev(nullptr) {}
    };

    Node* front; // Указатель на первый элемент очереди
    Node* back;  // Указатель на последний элемент очереди
    size_t count; // Количество элементов в очереди

public:
    Queue() : front(nullptr), back(nullptr), count(0) {}

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    // Добавление элемента в конец очереди
    void enqueue(const T& element) {
        Node* newNode = new Node(element);
        if (isEmpty()) {
            front = back = newNode;
        } else {
            back->next = newNode;
            newNode->prev = back;
            back = newNode;
        }
        count++;
    }

    // Удаление элемента из начала очереди
    void dequeue() {
        if (isEmpty()) {
            throw std::out_of_range("Queue is empty");
        }
        Node* temp = front;
        front = front->next;
        if (front) {
            front->prev = nullptr;
        } else {
            back = nullptr; // Если очередь стала пустой
        }
        delete temp;
        count--;
    }

    // Получение первого элемента очереди
    T frontElement() const {
        if (isEmpty()) {
            throw std::out_of_range("Queue is empty");
        }
        return front->data;
    }

    // Проверка, пуста ли очередь
    bool isEmpty() const {
        return count == 0;
    }

    // Получение размера очереди
    size_t size() const {
        return count;
    }
};
