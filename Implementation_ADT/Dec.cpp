#include <iostream>
#include <stdexcept>

template<typename T>
class Dec {
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;

        Node(const T& data) : data(data), next(nullptr), prev(nullptr) {}
    };

    Node* head; // Указатель на первый элемент дека
    Node* tail; // Указатель на последний элемент дека
    size_t count; // Количество элементов в деке

public:
    Dec() : head(nullptr), tail(nullptr), count(0) {}

    ~Dec() {
        clear();
    }

    // Добавление элемента в начало дека
    void pushFront(const T& element) {
        Node* newNode = new Node(element);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        count++;
    }

    // Добавление элемента в конец дека
    void pushBack(const T& element) {
        Node* newNode = new Node(element);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        count++;
    }

    // Удаление первого элемента дека
    void popFront() {
        if (isEmpty()) {
            throw std::out_of_range("Deque is empty");
        }
        Node* temp = head;
        head = head->next;
        if (head) {
            head->prev = nullptr;
        } else {
            tail = nullptr; // Если дек стал пустым
        }
        delete temp;
        count--;
    }

    // Удаление последнего элемента дека
    void popBack() {
        if (isEmpty()) {
            throw std::out_of_range("Deque is empty");
        }
        Node* temp = tail;
        tail = tail->prev;
        if (tail) {
            tail->next = nullptr;
        } else {
            head = nullptr; // Если дек стал пустым
        }
        delete temp;
        count--;
    }

    // Получение первого элемента дека
    T front() const {
        if (isEmpty()) {
            throw std::out_of_range("Deque is empty");
        }
        return head->data;
    }

    // Получение последнего элемента дека
    T back() const {
        if (isEmpty()) {
            throw std::out_of_range("Deque is empty");
        }
        return tail->data;
    }

    // Проверка, пуст ли дек
    bool isEmpty() const {
        return count == 0;
    }

    // Получение размера дека
    size_t size() const {
        return count;
    }

    // Очистка дека
    void clear() {
        while (!isEmpty()) {
            popFront();
        }
    }

    // Вывод элементов дека
    void print() const {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};
