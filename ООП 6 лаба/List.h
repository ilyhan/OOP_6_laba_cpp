#pragma once
#include "Node.h"
#include "iterator.h"
template <typename T>
class List {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    List() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    ~List() {
        clear();
    }

    void clear() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    bool isEmpty() const {
        return size == 0;
    }

    int getSize() const {
        return size;
    }

    void append(const T& value) {
        Node<T>* node = new Node<T>(value);
        if (isEmpty()) {
            head = node;
            tail = node;
        }
        else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
        size++;
    }

    template <class Iterator>
    void insert(const T& value, Iterator& it) {
        if (it.current == nullptr) {
            append(value);
        }
        else {
            Node<T>* node = new Node<T>(value);
            node->next = it.current;
            node->prev = it.current->prev;
            if (it.current->prev != nullptr) {
                it.current->prev->next = node;
            }
            it.current->prev = node;
            if (it.current == head) {
                head = node;
            }
        }
        size++;
    }

    template <class Iterator>
    void remove(Iterator& it) {
        if (it.current != nullptr) {
            Node<T>* prev = it.current->prev;
            Node<T>* next = it.current->next;
            if (prev != nullptr) {
                prev->next = next;
            }
            if (next != nullptr) {
                next->prev = prev;
            }
            if (it.current == head) {
                head = next;
            }
            if (it.current == tail) {
                tail = prev;
            }
            delete it.current;
            it.current = next;
            size--;
        }
    }

    void merge(List<T>& other) {
        iterator<T> it = nullptr;
        iterator<T> otherIt = other.begin();

        while (otherIt != nullptr) {
            insert(*otherIt, it);
            otherIt++;
        }
    }

    void mergeOrdered(List<T>& other) {
        merge(other);
        iterator<T> i = begin();
        while (i != nullptr) {
            iterator<T> j = begin();
            while (j != nullptr) {
                if (*i < *j) {
                    T tmp = *i;
                    *i = *j;
                    *j = tmp;
                }
                j++;
            }
            i++;
        }
    }

    Node<T>* begin() {
        return head;
    }
    
    Node<T>* end() {
        return tail;
    }

    friend std::ostream& operator<<(std::ostream& os, List<T>& list) {
        Node<T>* node = list.head;
        while (node) {
            std::cout << node->value << "  ";
            node = node->next;
        }
        std::cout << "\n";
        return os;
    }
};