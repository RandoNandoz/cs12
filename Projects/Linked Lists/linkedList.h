//
// Created by Randy on 2022-01-22.
//
#include <stdexcept>
#include "node.h"

#ifndef LINKED_LISTS_LINKEDLIST_H
#define LINKED_LISTS_LINKEDLIST_H

template<typename T>
class linkedList {
private:
    node<T> *head;
    node<T> *tail;

public:
    //<editor-fold desc="Constructors">
    linkedList() {
        // create a new linked list of the first element being a pointer to nothing.
        this->head = nullptr;
        this->tail = nullptr;
    }

    linkedList(T array[], unsigned int size) {
        for (unsigned int i = 0; i < size; i++) {
            this->append(array[i]);
        }
    }

    // disable copy constructor
    linkedList(const linkedList &list) = delete;
    //</editor-fold>

    //<editor-fold desc="Destructor">
    virtual ~linkedList() {
        // traverse the list, deleting each element.
        auto *currentNode = this->head;
        node<T> *previousNode;
        while (currentNode != nullptr) {
            previousNode = currentNode;
            currentNode = currentNode->getNext();
            delete previousNode;
        }
    }
    //</editor-fold>

    //<editor-fold desc="Insertion operations">
    // Adds to the front of the linked list. O(1).
    void prepend(const T &item) {
        // add an element to the front of the list
        auto newElement = new node<T>(item, head);
        this->head = newElement;
    }

    // Adds to the end of the linked list. O(n).
    void append(const T &item) {
        // If the list isn't empty, we can traverse and append.
        if (this->head != nullptr) {
            // create a new node with no ptrs to anything
            auto newElement = new node<T>(item);

            // traverse the list, until you get to the end of the list.
            auto *currentNode = this->head;
            node<T> *previousNode;
            while (currentNode != nullptr) {
                previousNode = currentNode;
                currentNode = currentNode->getNext();
            }
            // set the next node of the last element in the list to our new element.
            previousNode->setNext(newElement);
        } else {
            // but if the list is empty, just prepend.
            this->prepend(item);
        }
    }

    void insertAfterIndex(const T &item, unsigned int index) {
        // get the node after the index
        auto indexPlusOneNode = this->head;
        // and the node of the index
        node<T> *indexNode;

        // iterate through index items
        for (int i = 0; i < index + 1; ++i) {
            // if the i+1'th node is not null, we can move forward
            if (indexPlusOneNode != nullptr) {
                indexNode = indexPlusOneNode;
                indexPlusOneNode = indexPlusOneNode->getNext();
            } // otherwise, the list is shorter than index, so let us raise an exception.
            else {
                throw std::runtime_error("Cannot insert into non-existent index!");
            }
        }
        // if the index exists, set the next item to the index plus one node.
        indexNode->setNext(new node<T>(item, indexPlusOneNode));
    }

    void insertBeforeIndex(const T &item, unsigned int index) {
        // the node of the index
        auto indexNode = this->head;
        // and the node of the index before
        node<T> *indexMinusOneNode;

        for (int i = 0; i < index; ++i) {
            // if the index node is nullptr, then it does not exist, throw and error.
            if (indexNode != nullptr) {
                indexMinusOneNode = indexNode;
                indexNode = indexNode->getNext();
            } else {
                throw std::runtime_error("Cannot insert into non-existent index!");
            }
        }
        // set the i - 1 node's next to the new node, and the new node's next node to be the index's
        indexMinusOneNode->setNext(new node<T>(item, indexNode));
    }
    //</editor-fold>

    //<editor-fold desc="Pop operations">
    // pop like a stack (i.e. remove the first element)
    void firstPop() {

        // check if the first element of the linked list exists, if it does then we can do this
        if (this->head != nullptr) {
            // the node to remove, would be the first element.
            auto nodeToRemove = this->head;

            // set the new head to the element after the head
            this->head = nodeToRemove->getNext();

            // delete the old first node.
            delete nodeToRemove;
        } else {
            throw std::runtime_error("Cannot stack pop from an empty list!");
        }

    }

    // pop like a queue (i.e. remove the last element)
    void lastPop() {
        // check if the list is empty, if it is empty, we cannot pop an element that does not exist.
        if (this->head != nullptr) {
            // traverse the list, until currentNode is the last element.
            auto currentNode = this->head;
            node<T> *previousNode;
            while (currentNode->getNext() != nullptr) {
                previousNode = currentNode;
                currentNode = currentNode->getNext();
            }

            // set the previous node's next element to nullptr, and then delete the last node,
            previousNode->setNext(nullptr);
            delete currentNode;
        } else {
            throw std::runtime_error("Cannot queue pop from an empty list!");
        }
    }

    // pop at an index.
    void indexPop(unsigned int index) {
        // the node at the index.
        auto indexNode = this->head;
        // the index - 1's node.
        node<T> *indexMinusOneNode;
        // the index + 1's node.
        node<T> *indexPlusOneNode;

        for (int i = 0; i < index; ++i) {
            // if the index node is a nullptr, then it does not exist, so throw and error!
            if (indexNode != nullptr) {
                // track the node previous to indexNode (i - 1 node)
                indexMinusOneNode = indexNode;
                indexNode = indexNode->getNext();
            } else {
                throw std::runtime_error("Cannot pop from non-existent index!");
            }
        }
        // assign indexPlusOneNode to be the node next to our index.
        indexPlusOneNode = indexNode->getNext();
        // delete the node, so we have a dangling indexMinusOneNode.
        delete indexNode;
        // and then "reconnect" the index - 1'th node, by setting its next node to the index + 1 node.
        indexMinusOneNode->setNext(indexPlusOneNode);
    }
    //</editor-fold>

    // Last element of the linked list.
    node<T> *last() const {
        // traverse the list until you get to the last node
        auto lastNode = this->head;
        while (lastNode->getNext() != nullptr) {
            lastNode = lastNode->getNext();
        }

        // return it.
        return lastNode;
    }

    // Length of linked list.
    [[nodiscard]] unsigned int size() const {
        // count how many times the list needs to be traversed, then return it.
        auto currentNode = this->head;
        unsigned int length = 0;
        while (currentNode != nullptr) {
            length++;
            currentNode = currentNode->getNext();
        }
        return length;
    }

    // Index operator, gets the node pointer at the index.
    node<T> *operator[](const unsigned int index) {
        // iterate through the list, until we get into the index's node pointer, and return it.
        auto indexNode = this->head;
        for (int i = 0; i < index; ++i) {
            if (indexNode != nullptr) {
                indexNode = indexNode->getNext();
            } else {
                throw std::runtime_error("Cannot access non-existent index!");
            }
        }
        return indexNode;
    }

    T *toPointer() const {
        T *array = new T[this->size()];
        auto currentNode = this->head;
        int i = 0;
        while (currentNode != nullptr) {
            array[i] = currentNode->getData();
            currentNode = currentNode->getNext();
            ++i;
        }
        return array;
    }

    // prevent the usage of the assignment operator.
    linkedList &operator=(const linkedList &list) = delete;

    // gets the first element of the list
    node<T> *getHead() const {
        return head;
    }
};


#endif //LINKED_LISTS_LINKEDLIST_H
