#include "ScmApp.h"
#include <iostream>

using namespace sict;

int main() {
	
	//std::cout << "hello" << std::endl;
	ScmApp X;
	Course B("oop244", "programming", 4, 5);
	std::cout << B;
	int x = 0;
	do {
		x = X.run();
	} while (x == 0);

	return 0;
}