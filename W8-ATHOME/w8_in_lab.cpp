#include <iostream>
#include "Bus.h"
#include "Truck.h"

int main()
{
	Bus cityBus;
	Truck pickUp;
	std::cin >> cityBus >> pickUp;
	std::cout << cityBus << pickUp;

	return 0;
}

