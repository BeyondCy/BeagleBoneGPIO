#include "PinFactory.h"

namespace BBGPIO
{

	PinFactory::PinFactory()
	{
	}

	PinFactory::~PinFactory()
	{
		PinFactory::reclaimAll();
	}

	PinFactory& PinFactory::getInstance()
	{
		static PinFactory p;
		return p;
	}

	Pin* PinFactory::slot(const PinSlot::Slot slot, const PinDirection::Direction direction)
	{
		return PinFactory::getInstance().fetchPin(static_cast<uint8_t>(slot), static_cast<uint8_t>(direction));
	}

	Pin* PinFactory::name(const PinName::Name name, const PinDirection::Direction direction)
	{
		return PinFactory::getInstance().fetchPin(static_cast<uint8_t>(name), static_cast<uint8_t>(direction));
	}


	Pin* PinFactory::fetchPin(uint8_t index, uint8_t direction)
	{
		if (index > PIN_MAX)
			return 0;

		if (PinFactory::pins.find(index) != PinFactory::pins.end())
			return pins[index];

		Pin* pin = new Pin(PinDefaults[index]);
		PinFactory::pins[index] = pin;

		return pin;
	}

	void PinFactory::reclaim(Pin* pin)
	{
		uint8_t key = static_cast<uint8_t>(pin->slot());

		if (PinFactory::pins.find(key) != PinFactory::pins.end())
		{
			delete PinFactory::pins[key];
			PinFactory::pins.erase(key);
		}
	}

	void PinFactory::reclaimAll()
	{
		for (auto kv : PinFactory::pins)
			delete kv.second;

		PinFactory::pins.clear();
	}




} // namespace BBGPIO