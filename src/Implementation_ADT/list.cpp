#include <iostream>
#include <stdexcept>

template<typename T>
class List {
private:
    struct Node {
        T data;
        Node* next;

        Node(const T& data) : data(data), next(nullptr) {}
    };

    Node* head; // Указатель на первый элемент списка
    size_t count; // Количество элементов в списке

public:
    List() : head(nullptr), count(0) {}

    ~List() {
        clear();
    }

    // Добавление элемента в конец списка
    void append(const T& element) {
        Node* newNode = new Node(element);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
        count++;
    }

    // Удаление первого элемента списка
    void removeFirst() {
        if (head == nullptr) {
            throw std::out_of_range("List is empty");
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        count--;
    }

    // Получение первого элемента списка
    T getFirst() const {
        if (head == nullptr) {
            throw std::out_of_range("List is empty");
        }
        return head->data;
    }

    // Проверка, пуст ли список
    bool isEmpty() const {
        return count == 0;
    }

    // Получение размера списка
    size_t size() const {
        return count;
    }

    // Очистка списка
    void clear() {
        while (!isEmpty()) {
            removeFirst();
        }
    }

    // Вывод элементов списка
    void print() const {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};
