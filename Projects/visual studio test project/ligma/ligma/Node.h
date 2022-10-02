#pragma once
template<typename T>
class Node {
private:
    // a Node has data, and a ptr to another Node after it.
    T data;
    Node<T>* next;
public:
    //<editor-fold desc="constructors and destructors">
    Node(T data, Node<T>* next) : data(data), next(next) {}
    explicit Node(T data) : data(data), next(nullptr) {}
    Node() : data(0), next(nullptr) {}
    ~Node() = default;
    //</editor-fold>


    //<editor-fold desc="getters and setters">
    T getData() const {
        return data;
    }

    void setData(T item) {
        this->data = item;
    }

    Node<T>* getNext() const {
        return next;
    }

    void setNext(Node<T>* ptr) {
        this->next = ptr;
    }
    //</editor-fold>
};