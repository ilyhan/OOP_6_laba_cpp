#pragma once
#include "Node.h"
template <typename T>
class iterator {
public:
    Node<T>* current;

    iterator(Node<T>* current) {
        this->current = current;
    }

    T& operator*() const {
        return current->value;
    }

    iterator& operator++() {
        if (current != nullptr) {
            current = current->next;
        }
        return *this;
    }

    iterator operator++(int) {
        iterator prev = *this;
        if (current != nullptr) {
            current = current->next;
        }
        return prev;
    }

    iterator& operator--() {
        if (current != nullptr) {
            current = current->prev;
        }
        return *this;
    }

    iterator operator--(int) {
        iterator next = *this;
        if (current != nullptr) {
            current = current->prev;
        }
        return next;
    }

    iterator operator+(int a) {
        int k = 1;
        while (current && k <= a) {
            ++* this;
            k++;
        }
        return *this;
    }

    iterator operator-(int a) {
        int k = 1;
        while (current && k <= a) {
            --* this;
            k++;
        }
        return *this;
    }

    bool operator==(const iterator& other) const {
        return current == other.current;
    }

    bool operator!=(const iterator& other) const {
        return current != other.current;
    }

};