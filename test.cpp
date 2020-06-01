#include "Sequence.h"
#include <iostream>

using std::cout;
using std::endl;


void test() {
    Sequence s1;
    s1.insert(5.3);
    double numbers[] = { 1.1,2.2,3.3 };
    s1.insert(numbers,3);
    Sequence s2(s1);
    Sequence sq3 = s2.concatenate(s1);
    s1.print();
    s2.print();
    sq3.print();
    sq3 = s1;
    sq3.print();
    sq3 = sq3;
    sq3.print();

}

void basicTest()
{
	Sequence sq1;
	double numbers[] = { 1.1,2.2,3.3 };
	int n = 3;
 
	sq1.insert(3.14);
	sq1.insert(numbers, n);
    sq1.print();
 
//	int pies = sq1.find(3.14);
//	int sqSize = sq1.size();
//	double sqSum = sq1.sum();
//	double sqMean = sq1.mean();
//	double sqMedian = sq1.median();
//	double sqStddev = sq1.stddev(); 
	Sequence sq2(sq1);
    sq2.print();
	Sequence sq3 = sq2.concatenate(sq1);
 
	
}



int main () {
    test();
    // basicTest();
    return 0;
}

