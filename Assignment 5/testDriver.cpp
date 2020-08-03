#include <iostream>
#include "Heap.h"
using std::cout;
using std::endl;

// void simpleTest()
// {
// 	// Int Heap Tests
// 	Heap<int> pq1(4);
 
// 	pq1.insert(3);
// 	pq1.insert(1);
// 	pq1.insert(42);
 
// 	"pq1 root = " << pq1.peek() ; //42
// 	int urgent = pq1.remove();
// 	"pq1 root = " << pq1.peek() ; //3
// 	"pq1 size = " << pq1.size() ; //2
 
// 	Heap<int> pq2(pq1);
// 	pq2.insert(13);
// 	Heap<int> pq3 = pq1.merge(pq2); // should contain duplicates
// 	"pq3 size = " << pq3.size() ; //5
// 	"pq3 root = " << pq3.peek() ; //13
// }

void test() {
	Heap pt1(7);
	pt1.insert(3);
	pt1.insert(6);
	pt1.insert(9);
	pt1.insert(10);
	pt1.insert(1);
	pt1.insert(7);
	pt1.insert(12);
	pt1.print();
	

	Heap pt2(pt1);
	Heap pt3(3);
	pt3 = pt2;
	pt3 = pt3;

	
	
	pt3.remove() ;
	pt3.remove() ;
	pt3.remove() ;
	pt3.remove() ;
	cout << endl;
	pt3.print();

	Heap pt4 = pt1.merge(pt3);
	cout << pt4.size() << endl;
	cout << "Printing pt4 " << endl;
	pt4.print();

}

void test2() {
	Heap pt1(3);
	Heap pt2(4);
	pt2.insert(4);
	Heap pt3 = pt2.merge(pt1);
	cout << "Size" << pt3.size() << endl;
	pt3.print();

}
int main () {
	test2();
    return 0;
}