#pragma once
#include <stdexcept>
#include <iostream>

using std::cout;
using std::endl;


template <class T>
class Node {
    
    public:
        // Attributes
        T data;
        Node * prev;
        Node * next;
        
        Node(T val) {
            data = val;
            prev = nullptr;
            next = nullptr;
        }

        // Constructor that considers whether node is to be inserted in the front or back of deque
        Node(T val, Node * nd, bool front) {
            data = val;
            if (front) {
                prev = nullptr;
                next = nd;
            } else {
                prev = nd;
                next = nullptr;
            }
        }
};

template <class T>
class Deque {
    
    public:
        Deque();
        Deque(const Deque & deq);
        ~Deque();
        Deque & operator=(const Deque & deq);
        void insertFront(T num);
        void insertBack(T num);
        T removeFront();
        T removeBack();
        T peekFront() const;
        T peekBack() const;
        bool empty() const;
        int size() const;
        void initFirstNode(T num);
        void throwErrorIfEmpty() const;
        void copyDeque(const Deque & deq);
        void deallocateNodes();
        void printForwards();
        void printBackwards();
        
    private:
        Node<T> * head;
        Node<T> * tail;
};

// Constructor - Makes an empty Deque
template <class T>
Deque<T>::Deque() {
    head = tail = nullptr;
}

// Copy Constructor - deep copy of Deque
template <class T>
Deque<T>::Deque(const Deque & deq) {
    copyDeque(deq);
}

// Destructor
template <class T>
Deque<T>::~Deque() {
    deallocateNodes();
}

// Overloaded assignment operator
template <class T>
Deque<T> & Deque<T>::operator=(const Deque & deq) {
    // Checks for self-assignment
    if (this != &deq) {
        deallocateNodes();
        copyDeque(deq);
    }
    return *this;
}

// Inserts template parameter at front of Deque
template <class T>
void Deque<T>::insertFront(T num) {
    // If deque is empty
    if (empty()) {
        initFirstNode(num);
    } else {
        // If deque has 1+ nodes already
        Node<T> * newNode = new Node<T>(num, head, true);
        head->prev = newNode;
        head = newNode;
    }
}

// Inserts template parameter at back of Deque
template <class T>
void Deque<T>::insertBack(T num) {
    // If deque is empty
    if (empty()) {
        initFirstNode(num);
    } else {
        // If deque has 1+ nodes already
        Node<T> * newNode = new Node<T>(num, tail, false);
        tail->next = newNode;
        tail = newNode;
    }
}

// Removes and returns value at front of Deque
template <class T>
T Deque<T>::removeFront() {

    throwErrorIfEmpty();
    T value = head->data;
    // If there's only one value in deque
    if (head == tail) {
        delete head;
        head = tail = nullptr;
    } else {
        // If deque has 2+ values 
        Node<T> * temp = head;
        head = head->next;
        head->prev = nullptr;
        delete temp;
        temp = nullptr;
    }
    
    return value;
}

// Removes and returns value at back of Deque
template <class T>
T Deque<T>::removeBack() {
    
    throwErrorIfEmpty();
    T value = tail->data;
    // If there's only one value in deque
    if (head == tail) {
        delete tail;
        head = tail = nullptr;
    } else {
        // If deque has 2+ values 
        Node<T> * temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
        temp = nullptr;
    }
    
    return value;
}

// Returns value at front of Deque
template <class T>
T Deque<T>::peekFront() const {
    throwErrorIfEmpty();
    return head->data;
}

// Returns value at back of Deque
template <class T>
T Deque<T>::peekBack() const {
    throwErrorIfEmpty();
    return tail->data;
}

// Returns boolean on whether Deque is empty or not
template <class T>
bool Deque<T>::empty() const {
    // If the head/tail is empty then we know the deque is empty
    if (head == nullptr || tail == nullptr) {
        return true;
    } else {
        return false;
    }
}

// Returns number of items stored in Deque
template <class T>
int Deque<T>::size() const {
    int count = 0;
    Node<T> * temp = head;
    // Loops over deque and increases count with every node traversed
	while (temp != nullptr){
        count++;
		temp = temp->next;
	}
	cout << endl;
    return count;
}

// Initializes first node and sets head and tail to it
template <class T>
void Deque<T>::initFirstNode(T num) {    
    Node<T> * newNode = new Node<T>(num);
    head = newNode;
    tail = newNode;
}

// If deque is empty, throw error
template <class T>
void Deque<T>::throwErrorIfEmpty() const {
    if (empty()) {
        throw std::runtime_error("Deque empty");
    }
}

// Used to copy Deque into new Deque
template <class T>
void Deque<T>::copyDeque(const Deque & deq) {
    head = tail = nullptr;
    // Deep Copy - traverse and copy nodes until there are no more nodes
    Node<T> * temp = deq.head;
    while (temp != nullptr) {
        insertBack(temp->data);
        temp = temp->next;
    }
}

// Loops through all nodes to deallocate
template <class T>
void Deque<T>::deallocateNodes() {
    // Traverse and delete nodes until there are no more nodes
    Node<T> * temp = head;
	while (head != nullptr) {
		head = head->next;
		delete temp;
        temp = nullptr;
		temp = head;
	}
}

// Debugging
template <class T>
void Deque<T>::printForwards() {
    Node<T> * temp = head;
	cout << "Front" << endl;
	while (temp != nullptr){
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

// Debugging
template <class T>
void Deque<T>::printBackwards() {
    Node<T> * temp = tail;
	cout << "Backwards" << endl;
	while (temp != nullptr){
		cout << temp->data << " ";
		temp = temp->prev;
	}
	cout << endl;
}