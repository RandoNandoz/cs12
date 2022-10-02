//
// Created by Randy on 2022-01-22.
//

#ifndef LINKED_LISTS_NODE_H
#define LINKED_LISTS_NODE_H

template<typename T>
class node {
private:
    T data;
    node<T> *next;
public:
    //<editor-fold desc="Constructors">
    node(T &data, node<T> *next) : data(data), next(next) {}

    explicit node(T &data) : data(data) {
        this->next = nullptr;
    }

    node() {
        this->next = nullptr;
    }
    //</editor-fold>

    //<editor-fold desc="Getters and setters">
    T getData() const {
        return data;
    }

    void setData(const T &d) {
        node::data = d;
    }

    node<T> *getNext() const {
        return next;
    }

    void setNext(node<T> *ptr) {
        node::next = ptr;
    }
    //</editor-fold>
};


#endif //LINKED_LISTS_NODE_H
