#include <iostream>
#include <vector>
#include <stdexcept>

template<typename T>
class Stack {
private:
    std::vector<T> elements; // Вектор для хранения элементов стека

public:
    // Добавление элемента в стек
    void push(const T& element) {
        elements.push_back(element);
    }

    // Удаление верхнего элемента из стека
    void pop() {
        if (isEmpty()) {
            throw std::out_of_range("Stack is empty");
        }
        elements.pop_back();
    }

    // Получение верхнего элемента стека
    T top() const {
        if (isEmpty()) {
            throw std::out_of_range("Stack is empty");
        }
        return elements.back();
    }

    // Проверка, пустой ли стек
    bool isEmpty() const {
        return elements.empty();
    }

    // Получение размера стека
    size_t size() const {
        return elements.size();
    }
};

