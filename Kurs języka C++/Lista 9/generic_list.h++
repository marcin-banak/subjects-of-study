#pragma once

#include "Exceptions.h++"

namespace calc {
    template <typename T>
    class List {
    private:
        class Node {
        public:
            T val;
            Node *next;
            Node(T value) noexcept;
            Node(T value, Node &next_nodes) noexcept;
            ~Node() noexcept;
        };
        Node *first;
    public:
        List() noexcept;
        ~List() noexcept;
        void insert(T val, int index);
        void push_front(T val) noexcept;
        void push_back(T val) noexcept;
        void pop(int index) noexcept;
        void pop_front() noexcept;
        void pop_back() noexcept;
        void remove(T val) noexcept;
        void remove_all(T val) noexcept;
        int find(T val) noexcept;
        int count(T val) noexcept;
        int size() noexcept;
        int isEmpty() noexcept;
    };
}

using namespace calc;

template <typename T>
List<T>::Node::Node(T value) noexcept : Node(value, nullptr) {}

template <typename T>
List<T>::Node::Node(T value, Node &next_nodes) noexcept {
    this->val = value;
    this->next = next_nodes;
}

template <typename T>
List<T>::Node::~Node() noexcept {
    delete next;
}

template <typename T>
List<T>::List() noexcept {
    this->first = nullptr;
}

template <typename T>
List<T>::~List() noexcept {
    delete first;
}

template<typename T>
void List<T>::insert(T val, int index) {
    Node *aux = this->first;

    if (index < 0)
        throw index_out_of_range("Metoda insert(): ujemny indeks!\n");

    if (aux == nullptr) {
        if (index == 0)
            this->first = Node(val);
        else
            throw index_out_of_range("Metoda insert(): lista jest pusta!\n");
    }

    while (index > 0 && aux->next != nullptr) {
        aux = aux->next;
        index--;
    }

    if (index != 0)
        throw index_out_of_range("Metoda insert(): bledny indeks!\n");

    aux->next = Node(val, aux->next);
}

template <typename T>
void List<T>::push_front(T val) noexcept {
    this->first = Node(val, this->first);
}