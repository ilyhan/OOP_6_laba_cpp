#pragma once
template <typename T>
class Node {
public:
    T value;
    Node<T>* prev;
    Node<T>* next;

    Node(const T& value) {
        this->value = value;
        prev = nullptr;
        next = nullptr;
    }
};