#include <iostream>
#include "LinkedList.h"

using std::cout;
using std::endl;


int main() {
    LinkedList ob;
    ob.insert(123);
    ob.insert(1);
    ob.insert(1);
    ob.insert(123);
    ob.insert(123);
    ob.insert(1);
    ob.insert(1);
    ob.insert(3);
    ob.insert(1);
    ob.insert(1);
    ob.insert(1);
    ob.insert(1);
    ob.insert(1);
    ob.insert(2);
    ob.print();
    ob.remove(1);
    
    cout << "After" << endl;
    ob.print();
}