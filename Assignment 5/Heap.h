#include <stdexcept>
#include <iostream>

using std::cout;
using std::endl;

// Max Heap
class Heap {

    public:
        Heap(int size);
        Heap(const Heap & hp);
        ~Heap();
        Heap & operator=(const Heap & hp);
        void insert(int param);
        int remove();
        int peek() const;
        Heap merge(const Heap & hp) const;
        int size() const;
        void print() const;
    private:
        int currentSize;
        int arraySize;
        int *arr;
        void throwErrorIfFull() const;
        void throwErrorIfEmpty() const;
        void copyHeap(const Heap & hp);
        int leftChild(int parentIndex);
        int rightChild(int parentIndex);
        int leftchildIndex(int parentIndex) const;
        int rightChildIndex(int parentIndex) const;
        void bubbleUp(int i);
        void bubbleDown(int i);
        
};

// Creates heap with underlying array size equal to int parameter
Heap::Heap(int size) {
    arr = new int[size];
    currentSize = 0;
    arraySize = size;
}

// Copy Constructor - Deep copy using constant Heap reference parameter
Heap::Heap(const Heap & hp) {
    copyHeap(hp);
}

// Destructor
Heap::~Heap() {
    delete[] arr;
    arr = nullptr;
}

// Overloaded assignment operator
Heap & Heap::operator=(const Heap & hp) {
    if (this != &hp) {
        delete[] arr;
        copyHeap(hp);
    }
    return *this;
}

// Inserts template paramter in heap, if heap is full throw runtime_error
void Heap::insert(int param) {
    throwErrorIfFull();
    arr[currentSize] = param;
    bubbleUp(currentSize);
    currentSize++;
}

// Removes and returns root of heap, if heap is empty throw runtime_error
int Heap::remove() {
    throwErrorIfEmpty();
    int root = arr[0];
    int currentIndex = currentSize - 1;
    arr[0] = arr[currentIndex];
    bubbleDown(0);
    currentSize--;
    return root;
}

// Returns root, if heap is empty throw runtime_error
int Heap::peek() const {
    throwErrorIfEmpty();
    return arr[0];
}

// Returns heap object that contains values in the calling object and constn reference Heap parameter
Heap Heap::merge(const Heap & hp) const {
    // Copy constructor - Deep copy
    Heap ob(this->currentSize + hp.currentSize);

    // Deep copy array in calling object
    for (int x = 0; x < currentSize; x++) {
        ob.arr[x] = arr[x];
        ob.currentSize++;
    }

    // Deep copy array in constant reference Heap parameter
    for (int x = 0; x < hp.currentSize; x++) {
        ob.insert(hp.arr[x]);
    }

    return ob;
}

// Returns count of elements in heap as an int
int Heap::size() const {
    return currentSize;
}

// HELPER FUNCTIONS --------------------------


// Throws runtime_error if heap is full
void Heap::throwErrorIfFull() const {
    if (currentSize == arraySize) {
        throw std::runtime_error("Heap full");
    }
}

// Throws runtime_error if heap is empty
void Heap::throwErrorIfEmpty() const {
    if (currentSize == 0) {
        throw std::runtime_error("Heap empty");
    }
}

// Used to copy heap into new heap
void Heap::copyHeap(const Heap & hp) {
    // Deep Copy
    arr = new int[hp.arraySize];
    currentSize = hp.currentSize;
    arraySize = hp.arraySize;

    for (int x = 0; x < currentSize; x++) {
        arr[x] = hp.arr[x];
    }
}

int Heap::leftchildIndex(int parentIndex) const {
    return parentIndex * 2 + 1;
}

int Heap::rightChildIndex(int parentIndex) const {
    return parentIndex * 2 + 2;
}

// Bubbles up values until they fulfill heap properties
void Heap::bubbleUp(int i) {
    int parent = (i - 1) / 2;
    if (i > 0 && arr[i] > arr[parent]) {
        int temp = arr[i];
        arr[i] = arr[parent];
        arr[parent] = temp;
        bubbleUp(parent);
    }
}

// Bubbles down values until they fulfill heap properties
void Heap::bubbleDown(int i) {
    int lftIndex = leftchildIndex(i);
    int rhtIndex = rightChildIndex(i);
    // If both left and right child exceed current size, they aren't part 
    // of the heap. End recursion.
    if (lftIndex >= currentSize && rhtIndex >= currentSize) {
        return;
    // Condition if ONLY left child exists
    } else if (lftIndex < currentSize && rhtIndex >= currentSize && arr[i] < arr[lftIndex]) {
        int temp = arr[i];
        arr[i] = arr[lftIndex];
        arr[lftIndex] = temp;
        bubbleDown(lftIndex);
    // Condition if both children exist
    } else if (lftIndex < currentSize && rhtIndex < currentSize) {
        // If left child is larger than parent and right child 
        if (arr[i] < arr[lftIndex] && arr[lftIndex] > arr[rhtIndex]) {
            int temp = arr[i];
            arr[i] = arr[lftIndex];
            arr[lftIndex] = temp;
            bubbleDown(lftIndex);    
        }
        // If right child is larger than parent and left child
        else if (arr[i] < arr[rhtIndex] && arr[rhtIndex] > arr[lftIndex]) {
            int temp = arr[i];
            arr[i] = arr[rhtIndex];
            arr[rhtIndex] = temp;
            bubbleDown(rhtIndex);  
        }

    }
}

// Testing
void Heap::print() const {
    for (int x = 0 ; x < currentSize; x++) {
        cout << x <<  ": "<< arr[x] << endl;
    }
}

// int Heap::leftChild(int parentIndex) {
//     return arr[parentIndex * 2 + 1];
// }

// int Heap::rightChild(int parentIndex) {
//     return arr[parentIndex * 2 + 2];
// }