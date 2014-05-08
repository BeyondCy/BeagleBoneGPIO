#include <chrono>
#include <thread>

#include "BBGPIO/BBGPIO.h"

// This will send a signal oscillating high/low every 1 second

int main(int argc, char* argv[])
{
	Pin* p8_26 = PinFactory::slot(PinSlot::P8_26, PinDirection::OUTPUT);
	
	while (true)
	{
		p8_26->isHigh() ? p8_26->setLow() : p8_26->setHigh();
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}

	return 0;
}

