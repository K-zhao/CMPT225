#include "Sequence.h"
#include <cmath>
#include <iostream>

using std::cout;
using std::endl;

// Constructor - Makes an empty array of size 2 
Sequence::Sequence() {
    arr = new double[2];
    currentSize = 0;
    maxSize = 2;
}

// Copy constructor - deep copy of seq
Sequence::Sequence(const Sequence & seq) {
    copySequence(seq);
}

// Destructor
Sequence::~Sequence() {
    
    delete[] arr;
    arr = nullptr;
}

// Overloaded assignment operator
Sequence & Sequence::operator=(const Sequence & seq) {
    // Checks for self-assignment, as there's no need to change
    // anything if assigning to itself
    if (this != &seq) {
        delete[] arr;
        copySequence(seq);
    }
    return *this;
}

// Inserts a single number into array
void Sequence::insert(double num) {
    
    // Checks whether array is full and doubles the size if it is. 
    // Copies old contents of array into new, larger array
    if (currentSize == maxSize) {
        maxSize = maxSize*2;
        double *newarr = new double[maxSize];
        for (int x = 0; x < currentSize; x++) {
            newarr[x] = arr[x];
        }
        delete[] arr;
        arr = newarr;
    }

    // Inserts number parameter into end of array and increases currentsize
    arr[currentSize++] = num;
    
}

// Inserts numbers from array into calling object's array
void Sequence::insert(double *array, int size) {

    // Checks whether array would be full and increases size if it is. 
    // Copies old contents of array into new, larger array.
    if (currentSize + size > maxSize) {
        maxSize = currentSize + size;
        double *newarr = new double[maxSize];
        for (int x = 0; x < currentSize; x++) {
            newarr[x] = arr[x];
        }
        delete[] arr;
        arr = newarr;
    }

    // Inserts array parameter into end of array and increases currentsize by size

    for (int x = 0; x < size; x++) {
        arr[x + currentSize] = array[x];
    }
    currentSize += size;

}

// Returns count of elements that are equal to parameter
int Sequence::find(double num) const {
    
    int count = 0;
    // Check every array element. Increase count if match with parameter
    for (int x = 0; x < currentSize; x++) {
        if (num == arr[x]) {
            count++;
        }
    }
    return count;
}

// Returns amount of elements in array
int Sequence::size() const { 
    return currentSize;
}

// Returns sum of all elements in array
double Sequence::sum() const {
    double sum = 0;
    for (int x = 0; x < currentSize; x++) {
        sum += arr[x];
    }
    return sum;
}

// Returns average of elements in array
double Sequence::mean() const {
    if (isEmpty()) {
        return 0;
    } else {
        return sum()/(double)currentSize;
    }
}

// Returns number middle of sorted set
double Sequence::median() const {
    if (isEmpty()) {
        return 0;
    } else {
        // Copy into temporary array for sorting 
        double sortArr[maxSize] = {};
        for (int x = 0; x < currentSize; x++ ) {
            sortArr[x] = arr[x];
        }
    
        // Sort temporary array using selection sort
        for (int x = 0; x < currentSize + 1; x++) {
            int minimum_index = x;
            for (int y = x + 1; y < currentSize; y++) {
                if (sortArr[y] < sortArr[minimum_index]) {
                    minimum_index = y;
                }
            }
            
            // Swap lowest number into proper index
            double temp = sortArr[x];
            sortArr[x] = sortArr[minimum_index];
            sortArr[minimum_index] = temp;
        }
    
        // Find middle number for median
        // Picks and returns middle number if odd
        if (currentSize % 2 == 1) {
            return sortArr[currentSize / 2];
        } else {
            // Returns the divided sum of middle two array numbers if even
            double midTwo = (sortArr[(currentSize / 2) - 1] + sortArr[currentSize / 2]) / 2;
            return midTwo;
        }
    
    }
    
}

// Returns standard deviation of array
double Sequence::stddev() const {
    // Checks if there are at least 2 numbers, since calculating standard deviation requires 2+.
    if (currentSize < 2) {
        return 0; 
    } else {
    // Standard deviation = root(sum(difference^2)/n) 
    // Difference = number in Array - mean
    double average = mean();
    double sum = 0;

    for (int x = 0; x < currentSize; x++) {
        // This is the summation of (difference^2)
        sum += pow((arr[x] - average),2);
    }

    // divide sum by "n"
    sum /= currentSize;

    // return root of formula
    return sqrt(sum);

    }    
}

// Returns Sequence object containing contents of calling object 
// followed by contents of Sequence parameter
Sequence Sequence::concatenate(const Sequence & seq) {
    
    // Default constructor initializes array at size 2
    Sequence ob;
    ob.insert(this->arr, this->currentSize);
    ob.insert(seq.arr, seq.currentSize);
    return ob;
        
    
}


// Used to determine whether array is empty. Cleans up code in other methods.
bool Sequence::isEmpty() const {
    if (currentSize == 0) {
        return true;
    } else {
        return false;
    }
}

// Used to copy sequence into new sequence 
void Sequence::copySequence(const Sequence & seq) {
    // Deep copy
    arr = new double[maxSize];
    currentSize = seq.currentSize;
    maxSize = seq.maxSize;

    // Copy old array into new array
    for (int x = 0; x < currentSize; x++) {
        arr[x] = seq.arr[x];
    }
}

void Sequence::print() {
    cout << "CurrentSize: " << currentSize << endl;
    cout << "maxSize: " << maxSize << endl;
    cout << "array: ";
    for (int x = 0; x < currentSize; x++) {
        cout << arr[x] << " ";
    }
    cout << endl;
    cout << endl;
}