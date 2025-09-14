#include "VectorStore.h"

// ----------------- ArrayList Implementation -----------------

template <class T> ArrayList<T>::ArrayList (int initCapacity = 10) {
    // TODO
}

template <class T> ArrayList<T>::ArrayList (const ArrayList<T>& other) {
    // TODO
}

template <class T> ArrayList<T>::~ArrayList () {
    // TODO
}

// TODO: implement other methods of ArrayList
template <class T> void ArrayList<T>::ensureCapacity (int cap) {
    // TODO
}

// ----------------- Iterator of ArrayList Implementation -----------------
template <class T>
ArrayList<T>::Iterator::Iterator (ArrayList<T>* pList, int index) {
    // TODO
}

// TODO: implement other methods of ArrayList::Iterator

// ----------------- SinglyLinkedList Implementation -----------------
template <class T> SinglyLinkedList<T>::SinglyLinkedList () {
    // TODO
    // Create a empty LinkedList
    this->count = 0;
    this->head  = nullptr;
    this->tail  = this->head;
}

template <class T> SinglyLinkedList<T>::~SinglyLinkedList () {
    // TODO
}

// TODO: implement other methods of SinglyLinkedList
template <class T> void SinglyLinkedList<T>::add (T e) {
    // Add element to end of the list;
    Node* newNode = new Node (e, nullptr);
    if (this->head == nullptr) {
        this->head = newNode;
        this->tail = newNode;
    } else {
        this->tail->next = newNode;
        this->tail       = newNode;
    }
    // Increment count only after all logic has completed successfully
    count++;
}

template <class T> void SinglyLinkedList<T>::add (int index, T e) {
    // Check for valid index
    if (index < 0 || index > count) {
        throw std::out_of_range ("Index is invalid!");
    }

    // Insert at the specified index
    // Insert at head == previous insert method
    if (index == 0) {
        Node* newNode = new Node (e, this->head);
        this->head    = newNode;
        if (count == 0) {
            this->tail = newNode;
        }
    } else {
        // if inserting at tail
        if (index == count) {
            Node* newNode    = new Node (e, nullptr);
            this->tail->next = newNode;
            this->tail       = newNode;
        } else {
            for (int i = 0; i < index - 1; i++) {
                if (curr == nullptr) {
                    throw std::runtime_error (
                    "List structure corrupted: null pointer encountered.");
                }
                curr = curr->next;
            }
        }
        Node* newNode = new Node (e, curr->next);
        curr->next    = newNode;
    }
    count++;
}

template <class T> T SinglyLinkedList<T>::removeAt (int index) {
    // TODO
    T val;
    if (index < 0 || index >= count) {
        throw out_of_range ("Index is invalid!");
    }
    Node* curr = this->head;
    for (int i = 0; i < index; i++) {
        curr = curr->next;
    }
    Node* tmp  = curr->next; // Node to be removed
    curr->next = tmp->next;
    val        = tmp->data;
    if (tmp == this->tail) {
        this->tail = curr;
    }
    delete tmp;
    count--;
    return val;
}

// ----------------- Iterator of SinglyLinkedList Implementation -----------------
template <class T> SinglyLinkedList<T>::Iterator::Iterator (Node* node) {
    // TODO
}

// TODO: implement other methods of SinglyLinkedList::Iterator

// ----------------- VectorStore Implementation -----------------

VectorStore::VectorStore (int dimension = 512, EmbedFn embeddingFunction = nullptr) {
    // TODO
}

VectorStore::~VectorStore () {
    // TODO
}

// TODO: implement other methods of VectorStore

// Explicit template instantiation for char, string, int, double, float, and Point

template class ArrayList<char>;
template class ArrayList<string>;
template class ArrayList<int>;
template class ArrayList<double>;
template class ArrayList<float>;
template class ArrayList<Point>;

template class SinglyLinkedList<char>;
template class SinglyLinkedList<string>;
template class SinglyLinkedList<int>;
template class SinglyLinkedList<double>;
template class SinglyLinkedList<float>;
template class SinglyLinkedList<Point>;
