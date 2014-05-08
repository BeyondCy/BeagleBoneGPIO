#include <iostream>
#include "pinfactory.h"

int main(int argc, char* argv[])
{
	using namespace BBGPIO;
	PinFactory::reclaimAll();
	
	return 0;
}

