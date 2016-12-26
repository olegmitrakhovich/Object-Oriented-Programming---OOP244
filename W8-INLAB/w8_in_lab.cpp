#include <iostream>
#include "Bus.h"
#include "Truck.h"


int main()
{
	Bus cityBus(20, 78);
	Truck pickUp(30, true);
	
	move(cityBus);
	move(pickUp);	
	show(cityBus);
	show(pickUp);

	return 0;
}
