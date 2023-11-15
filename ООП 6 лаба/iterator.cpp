#include <iostream>
#include "iterator.h"
#include "Node.h"

template <typename T>
    iterator::iterator(Node<T>* current) {
        this->current = current;
    }
    template <typename T>
    T& iterator::operator*()  {
        return current->value;
    }
    template <typename T>
    iterator& iterator::operator++() {
        if (current != nullptr) {
            current = current->next;
        }
        return *this;
    }
    template <typename T>
    iterator iterator::operator++(int) {
        iterator prev = *this;
        if (current != nullptr) {
            current = current->next;
        }
        return prev;
    }
    template <typename T>
    iterator& iterator::operator--() {
        if (current != nullptr) {
            current = current->prev;
        }
        return *this;
    }
    template <typename T>
    iterator iterator::operator--(int) {
        iterator next = *this;
        if (current != nullptr) {
            current = current->prev;
        }
        return next;
    }
    template <typename T>
    iterator iterator::operator+(int a) {
        int k = 1;
        while (current && k <= a) {
            ++* this;
            k++;
        }
        return *this;
    }
    template <typename T>
    iterator iterator::operator-(int a) {
        int k = 1;
        while (current && k <= a) {
            --* this;
            k++;
        }
        return *this;
    }
    template <typename T>
    bool iterator::operator==(const iterator& other)  {
        return current == other.current;
    }
    template <typename T>
    bool iterator::operator!=(const iterator& other)  {
        return current != other.current;
    }
