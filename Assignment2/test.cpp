#include <iostream>
#include "Deque.h"
using namespace std;

void test() {
       Deque dq1;
       cout << dq1.empty() << " - 1" << endl;
       dq1.insertFront(42);
       dq1.insertBack(216);
       cout << dq1.peekFront() << " - 42" << endl;
       cout << dq1.peekBack() << " - 216" << endl;
       cout << dq1.size() << " - 2" << endl;

       Deque dq2(dq1);
       Deque dq3;
       dq3 = dq1;

       cout << dq1.removeFront() << " - 42" << endl;
       cout << dq1.removeBack() << " - 216" << endl;

       cout << dq2.peekFront() << " - 42" << endl;
       cout << dq2.peekBack() << " - 216" << endl;
       cout << dq3.peekFront() << " - 42" << endl;
       cout << dq3.peekBack() << " - 216" << endl;
}

void test2() {
       Deque dq1;
       dq1.insertBack(1);
       dq1.insertBack(2);
       dq1.insertBack(3);
       dq1.insertFront(4);
       dq1.insertBack(3);
       dq1.insertBack(4);
       dq1.printForwards();
       cout << dq1.size();
       Deque dq2(dq1);
       dq2.printForwards();
       dq2.printBackwards();
       
       dq2.insertFront(1900);
       cout << dq2.size();
       dq2.printForwards();
       dq2 = dq2;
       cout << dq2.size();
       dq2.printForwards();
       // cout << "Remove Front "  <<  dq1.removeFront() << endl;
       // cout << dq1.empty() << endl;
       // cout << "Remove Back " << dq1.removeBack() << endl;
       // cout << dq1.empty() << endl;
       // dq1.printForwards();
       // dq1.printBackwards();
}


int main()
{      
       test2();
       test();
       return 0;
}