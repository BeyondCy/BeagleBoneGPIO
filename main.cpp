#include <chrono>
#include <thread>

#include <iostream>

#include "BBGPIO/BBGPIO.h"

// This will send a signal oscillating high/low every 1 second

int main(int argc, char* argv[])
{
	Pin* p9_11 = PinFactory::slot(PinSlot::P9_11, PinDirection::OUTPUT);
	
	while (true)
	{
		p9_11->isHigh() ? p9_11->setLow() : p9_11->setHigh();
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		std::cout << p9_11->isHigh() ? "High" : "Low" << std::endl;
	}

	return 0;
}

