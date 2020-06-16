#pragma once
#include <stdexcept>
#include <iostream>

using std::cout;
using std::endl;

class Node {
    
    public:
        // Attributes
        int data;
        Node * prev;
        Node * next;
        
        Node(int val) {
            data = val;
            prev = nullptr;
            next = nullptr;
        }

        // Constructor that considers whether node is to be inserted in the front or back of deque
        Node(int val, Node * nd, bool front) {
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


class Deque {
    
    public:
        Deque();
        Deque(const Deque & deq);
        ~Deque();
        Deque & operator=(const Deque & deq);
        void insertFront(int num);
        void insertBack(int num);
        int removeFront();
        int removeBack();
        int peekFront() const;
        int peekBack() const;
        bool empty() const;
        int size() const;
        void initFirstNode(int num);
        void throwErrorIfEmpty() const;
        void copyDeque(const Deque & deq);
        void deallocateNodes();
        void printForwards();
        void printBackwards();
        
    private:
        Node * head;
        Node * tail;
};

// Constructor - Makes an empty Deque
Deque::Deque() {
    head = tail = nullptr;
}

// Copy Constructor - deep copy of Deque
Deque::Deque(const Deque & deq) {
    copyDeque(deq);
}

// Destructor
Deque::~Deque() {
    deallocateNodes();
}

// Overloaded assignment operator
Deque & Deque::operator=(const Deque & deq) {
    if (this != &deq) {
        deallocateNodes();
        copyDeque(deq);
    }
    return *this;
}

// Inserts template parameter at front of Deque
void Deque::insertFront(int num) {
    if (empty()) {
        initFirstNode(num);
    } else {
        Node * newNode = new Node(num, head, true);
        head->prev = newNode;
        head = newNode;
    }
}

// Inserts template parameter at back of Deque
void Deque::insertBack(int num) {
    if (empty()) {
        initFirstNode(num);
    } else {
        Node * newNode = new Node(num, tail, false);
        tail->next = newNode;
        tail = newNode;
    }
}

// Removes and returns value at front of Deque
int Deque::removeFront() {

    throwErrorIfEmpty();
    int value = head->data;
    // If there's only one value in deque
    if (head == tail) {
        delete head;
        head = tail = nullptr;
    } else {
        // If deque has 2+ values 
        Node * temp = head;
        head = head->next;
        head->prev = nullptr;
        delete temp;
        temp = nullptr;
    }
    
    return value;
}

// Removes and returns value at back of Deque
int Deque::removeBack() {
    
    throwErrorIfEmpty();
    int value = tail->data;
    // If there's only one value in deque
    if (head == tail) {
        delete tail;
        head = tail = nullptr;
    } else {
        // If deque has 2+ values 
        Node * temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
        temp = nullptr;
    }
    
    return value;
}

// Returns value at front of Deque
int Deque::peekFront() const {
    throwErrorIfEmpty();
    return head->data;
}

// Returns value at back of Deque
int Deque::peekBack() const {
    throwErrorIfEmpty();
    return tail->data;
}

// Returns boolean on whether Deque is empty or not
bool Deque::empty() const {
    if (head == nullptr || tail == nullptr) {
        return true;
    } else {
        return false;
    }
}

// Returns number of items stored in Deque
int Deque::size() const {
    int count = 0;
    Node* temp = head;
    // Loops over deque and increases count with every node traversed
	while (temp != nullptr){
        count++;
		temp = temp->next;
	}
	cout << endl;
    return count;
}

// Initializes first node and sets head and tail to it
void Deque::initFirstNode(int num) {    
    Node * newNode = new Node(num);
    head = newNode;
    tail = newNode;
}

// If deque is empty, throw error
void Deque::throwErrorIfEmpty() const {
    if (empty()) {
        throw std::runtime_error("Deque empty");
    }
}

// Used to copy Deque into new Deque
void Deque::copyDeque(const Deque & deq) {
    head = tail = nullptr;
    // Deep Copy
    Node * temp = deq.head;
    while (temp != nullptr) {
        insertBack(temp->data);
        temp = temp->next;
    }
}

// Loops through all nodes to deallocate
void Deque::deallocateNodes() {
    Node * temp = head;
	while (head != nullptr) {
		head = head->next;
		delete temp;
        temp = nullptr;
		temp = head;
	}
}

// Debugging
void Deque::printForwards() {
    Node* temp = head;
	cout << "Front" << endl;
	while (temp != nullptr){
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

// Debugging
void Deque::printBackwards() {
    Node* temp = tail;
	cout << "Backwards" << endl;
	while (temp != nullptr){
		cout << temp->data << " ";
		temp = temp->prev;
	}
	cout << endl;
}