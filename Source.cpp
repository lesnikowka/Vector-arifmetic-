#include <iostream>
#include "vector.h"

int main() {
	vector a(2), b(3);
	
	a.pushback(1);
	a.pushback(7);
	b.pushback(2);
	b.pushback(8);
	b.pushback(89);
	
	a.pushback(9);
	a.pushback(21);
	a.pushback(96);

	//a.popback();
	std::cout << a << std::endl;
	a.insert(10000,3);
	a.erase(1);
	a.popback();

	std::cout << a;
	std::cout << b;

	return 0;
}