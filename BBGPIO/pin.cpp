#include <fstream>
#include "pin.h"

namespace BBGPIO
{
	const char* Pin::GPIO_DIR = "/sys/class/gpio";
	const char* Pin::GPIO_EXPORT = "/sys/class/gpio/export";
	const char* Pin::GPIO_UNEXPORT = "/sys/class/gpio/unexport";

	Pin::Pin(PinInfo info) :
		pinInfo(info)
	{
		this->setPaths();
		this->export();
	}

	Pin::~Pin()
	{
		this->unexport();
	}

	void Pin::setPaths()
	{
		this->directionPath = Pin::GPIO_DIR;
		this->directionPath += "/gpio" + std::to_string(this->pinInfo.gpio) + "/direction";

		this->valuePath = Pin::GPIO_DIR;
		this->valuePath += "/gpio" + std::to_string(this->pinInfo.gpio) + "/value";
	}

	void Pin::export()
	{
		std::ofstream kernel(Pin::GPIO_EXPORT);
		kernel << this->pinInfo.gpio;
	}

	void Pin::unexport()
	{
		std::ofstream kernel(Pin::GPIO_UNEXPORT);
		kernel << this->pinInfo.gpio;
	}

	void Pin::setLow() const
	{
		this->setSignal(PinSignal::LOW);
	}

	bool Pin::isLow() const
	{
		return this->signal() == PinSignal::LOW;
	}

	void Pin::setHigh() const
	{
		this->setSignal(PinSignal::HIGH);
	}

	bool Pin::isHigh() const
	{
		return this->signal() == PinSignal::HIGH;
	}

	void Pin::setSignal(PinSignal::Signal signal) const
	{
		std::ofstream kernel(this->valuePath.c_str());

		kernel << (signal == PinSignal::HIGH) ? '1' : '0';
	}

	PinSignal::Signal Pin::signal() const
	{
		std::ifstream kernel(this->valuePath.c_str());

		char val;
		kernel >> val;
	
		return (val == '1') ? PinSignal::HIGH : PinSignal::LOW;		
	}

	void Pin::setOutput() const
	{
		this->setDirection(PinDirection::OUTPUT);
	}

	bool Pin::isOutput() const
	{
		return this->direction() == PinDirection::OUTPUT;
	}

	void Pin::setHigh() const
	{
		this->setDirection(PinDirection::INPUT);
	}

	bool Pin::isHigh() const
	{
		return this->direction() == PinDirection::INPUT;
	}

	void Pin::setDirection(PinDirection::Direction direction) const
	{
		std::ofstream kernel(this->directionPath.c_str());

		kernel << (direction == PinDirection::INPUT) ? '1' : '0';
	}

	PinDirection::Direction Pin::direction() const
	{
		std::ifstream kernel(this->directionPath.c_str());

		char val;
		kernel >> val;

		return (val == '1') ? PinDirection::INPUT : PinDirection::OUTPUT;
	}

}