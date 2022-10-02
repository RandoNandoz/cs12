#pragma once
template<typename T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    unsigned int length;

public:
    //<editor-fold desc="constructor and destructors">
    // initialize empty linked list with nullptr as both the head and tail, of
    // length zero.
    LinkedList() : head(nullptr), tail(nullptr), length(0) {}

    LinkedList(const std::initializer_list<T>& initializerList) : head(nullptr), tail(nullptr), length(0) {
        for (const auto& item : initializerList) {
            this->append(item);
        }
    }


    // disable the default copy constructors
    LinkedList(const LinkedList&&) = delete;

    LinkedList(const LinkedList&) = delete;

    // destructor for our class
    ~LinkedList() {
        this->clear();
    }
    //</editor-fold>

    //<editor-fold desc="append and insert">
    // inserts into the "front" of the linked list: O(1)
    auto insert(const T& item) -> void {
        // create a new Node, which is an unconnected Node with the item.
        auto* newNode = new Node<T>(item);
        // if the list is empty, set the head and tail to our new Node.
        if (this->empty()) {
            head = newNode;
            tail = newNode;
        }
        else {
            // otherwise, get the old head, store it, then set the head to our new
            // Node, then connect our head to the old head.
            Node<T>* oldHead = head;
            head = newNode;
            head->setNext(oldHead);
        }

        // increment length.
        length++;
    }

    // pushes an element to the back of the linked list: O(1)
    auto append(const T& item) -> void {
        // the new Node, unconnected with our item param.
        auto* newNode = new Node<T>(item);
        // like insert(), if the list is empty, our appended item is both the head
        // and the tail.
        if (this->empty()) {
            head = newNode;
            tail = newNode;
        }
        else {
            // otherwise,
            // set the next element of the tail to our new Node.
            tail->setNext(newNode);
            tail = newNode;
        }

        // increment length.
        length++;
    }

    // push an item before the index: O(n)
    auto insertIndex(const T& item, const unsigned int index) -> void {
        // if the index is equal to the length, so we're trying to insert to the
        // element after the last. this is just a regular append, so we can call
        // append(item) to do that.
        if (index == length) {
            this->append(item);
        }
        else if (index == 0) {
            // if we're trying to insert to the 0th index, it's just a regular
            // insertion which is merely O(1)
            this->insert(item);
        }
        else if (index > length) {
            throw std::out_of_range("Cannot insert into non-existent index!");
        }
        else {
            // we just need to get the index's Node, and the Node before it.
            Node<T>* indexNode = head;
            Node<T>* indexPrevNode;
            for (int i = 0; i < index; ++i) {
                indexPrevNode = indexNode;
                indexNode = indexNode->getNext();
            }

            // insert a new Node between the previous Node, in where that new Node
            // links to our index's Node.
            indexPrevNode->setNext(new Node<T>(item, indexNode));
            length++;
        }
    }

    // push an item after the selected index: O(n)
    auto appendIndex(const T& item, const unsigned int index) -> void {
        // if we're appending to the last element, it is just a regular append.
        if (index == length - 1 || length == 0) {
            this->append(item);
        }
        else if (index >= length) {
            throw std::out_of_range("Cannot insert into non-existent index!");
        }
        else {
            // we traverse the list, until we get to index + 1 and the index's Node.
            Node<T>* indexPlusOneNode = head;
            Node<T>* indexNode;
            for (int i = 0; i < index + 1; ++i) {
                indexNode = indexPlusOneNode;
                indexPlusOneNode = indexPlusOneNode->getNext();
            }

            // once we have the index's Node, and the Node after the index, we add a
            // new Node in between.
            indexNode->setNext(new Node<T>(item, indexPlusOneNode));

            // incr length
            length++;
        }
    }

    //</editor-fold>

    //<editor-fold desc="delete operations">
    // delete the item in the front of the list: O(1)
    auto deleteFront() -> void {
        // if it isn't empty, we can do this, but if it's empty, we can't delete it.
        // if the list is of length one, we just clear the list.
        if (length == 1) {
            delete head;
            head = nullptr;
            tail = nullptr;
            length--;
        }
        else if (!this->empty()) {
            // store the old head in frontNode
            Node<T>* frontNode = head;
            // set the head to the element next to it (it can be nullptr)
            head = head->getNext();
            // delete frontNode.
            delete frontNode;
            // decrement Node.
            length--;
        }
        else {
            // throw a runtime error if the list is empty.
            throw std::runtime_error("Cannot delete from an empty list!");
        }
    }

    // delete the item at the back of the list: O(n)
    auto deleteBack() -> void {
        if (length == 1) {
            this->deleteFront();
        }
        else if (!this->empty()) {
            // we want to remove the last Node, but since this is a singly-linked
            // list, we have to traverse the list, so unfortunately it'll be O(n) :(
            Node<T>* oldLastNode = tail;
            // we just need to traverse to the last index - 2'th element.
            Node<T>* secondLastNode = head;
            while (secondLastNode->getNext()->getNext() != nullptr) {
                secondLastNode = secondLastNode->getNext();
            }
            // so now we assign our tail to the second last Node, then set the element
            // next to it as nullptr, effectively orphaning our oldLastNode.
            tail = secondLastNode;
            tail->setNext(nullptr);

            // We can kill this orphan ;)
            delete oldLastNode;

            // decrement the length.
            length--;
        }
        else {
            // if the list is empty, throw and error.
            throw std::runtime_error("Cannot delete from an empty list!");
        }
    }

    // delete an element at a specified index. O(n)
    auto deleteIndex(unsigned int index) -> void {
        // if the index is greater than the size of the array, then we throw an
        // error because we can't
        if (index > length - 1) {
            throw std::out_of_range("Cannot delete non-existent index!");
        }
        else if (index == length - 1) {
            // if the index is just the last the element, we can use deleteBack() to
            // delete it.
            this->deleteBack();
        }
        else if (index == 0) {
            // if we're trying to delete the 0th element, it is the first, and we can
            // use the deleteFront() function.
            this->deleteFront();
        }
        else {
            // create target, target previous, and target next Nodes.
            // init the targetNode at the head, as we are going to traverse index
            // times to find the index's Node, the Node before index, and the Node
            // after the index, which is pretty much targetNode->getNext().
            Node<T>* targetNode = head;
            Node<T>* targetPrevNode;
            Node<T>* targetNextNode;

            // traverse the list, finding both the Node before the index, and the
            // index's Node.
            for (int i = 0; i < index; ++i) {
                targetPrevNode = targetNode;
                targetNode = targetNode->getNext();
            }
            // now assign the Node after index as the Node after index lol
            targetNextNode = targetNode->getNext();

            // set the previous Node of the index to get next Node after the next
            targetPrevNode->setNext(targetNextNode);

            // then finally, we can delete the target Node.
            delete targetNode;

            // decrement the length.
            length--;
        }
    }
    //</editor-fold>

    //<editor-fold desc="utility functions">
    [[nodiscard]] auto empty() const -> bool {
        if (head == nullptr && tail == nullptr) {
            return true;
        }
        return false;
    }

    [[nodiscard]] auto size() const -> unsigned int { return length; };

    // clears all elements of the linked list and resets its state.
    auto clear() -> void {
        // delete every single element.
        if (!this->empty()) {
            do {
                this->deleteFront();
            } while (head != nullptr);
        }
        // reset the head, and tail to nullptr.
        head = nullptr;
        tail = nullptr;

        // set the length to the zero.
        length = 0;
    }
    //</editor-fold>

    //<editor-fold desc="getters and setters">
    auto setHead(Node<T> ptr) -> void { head = ptr; }

    auto setTail(Node<T> ptr) -> void { tail = ptr; }

    auto getHead() const -> Node<T>* { return head; }

    auto getTail() const -> Node<T>* { return tail; }
    //</editor-fold>

    //<editor-fold desc="operator overloads">
    // disable the equality operator.
    auto& operator=(const LinkedList&) = delete;

    // override subscript
    auto operator[](const unsigned int index) const -> Node<T>* {
        // if we're trying to access the first or last elem, return the head and
        // tail, respectively.
        if (index == 0) {
            return head;
        }
        else if (index == length - 1) {
            return tail;
        }
        else if (index >= length) {
            // if we're out of range, trying to access an index that does not exist,
            // throw an exception.
            throw std::out_of_range(
                "Unable to access non-existent index of linked list!");
        }
        else {
            // traverse index times through the array, and the return the Node at that
            // position.
            Node<T>* indexNode = this->head;
            for (int i = 0; i < index; ++i) {
                indexNode = indexNode->getNext();
            }
            return indexNode;
        }
    }
    //</editor-fold>
};

