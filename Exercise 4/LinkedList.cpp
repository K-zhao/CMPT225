#include "LinkedList.h"

// To be completed for exercise 4
// Recursive helper method for remove(int)
// ONLY CHANGE BODY OF THIS METHOD
void LinkedList::remove(Node* nd, int val)
{
	Node * current = nd;
	if (head == nullptr || current == nullptr) {
		return;
	}

	// Deleting values from head
	if (current->data == val && current == head) {
		Node * temp = current;
		current = current->next;
		delete temp;
		head = head->next;
		remove(nd->next, val);
	}

	
	if (current->next != nullptr && current->next->data == val) {
		Node * nextNext = current->next->next;
		// Deleting values between head and tail
		if (nextNext != nullptr) {
			Node * temp = current->next;
			delete temp;
			current->next = nextNext;
			// If next value matches target, recursive call on self node
			if (nd->next->data == val) {
				remove(nd, val);
			} else {
				// We can safely call next Node since we know it won't match target
				remove(nd->next, val);
			}
		}
		// Deleting value at the tail if target matched.  
		else if (nextNext == nullptr) {
			Node * next = current->next;
			delete next;
			current->next = nullptr;
		}
	} 

}

// Constructors and destructor
// Creates an empty list
LinkedList::LinkedList()
{
	head = nullptr;
}

LinkedList::~LinkedList()
{
	deleteList();
}
// Copy constructor and overloaded assignment operator not implemented

// Mutators------------------
// PARAM: val = value to be inserted
// POST: inserts val at the front of the list
void LinkedList::insert(int val)
{
	Node* newNode = new Node(val, head);
	head = newNode;
}

// PARAM: val = value to be removed from list
// POST: removes all incidences of val from list,
// Calls remove(Node*, int)
void LinkedList::remove(int val)
{
	remove(head, val);
}

// Helper method for destructor
// (and un-implemented overloaded assignment operator)
void LinkedList::deleteList()
{
	Node* temp = head;
	while (head != nullptr) {
		head = head->next;
		delete temp;
		temp = head;
	}
}

// Accessors
bool LinkedList::check(const vector<int> & v)
{
	Node* p = head;
	for (int x : v) {
		if (p == nullptr || p->data != x) {
			return false;
		}
		p = p->next;
	}
	return (p == nullptr); // p != nullptr list contains unchecked values
}

void LinkedList::print() {
	Node* temp = head;
	cout << endl;
	while (temp != nullptr){
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}