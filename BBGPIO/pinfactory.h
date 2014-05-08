#pragma once

#include <unordered_map>

#include "pin.h"


namespace BBGPIO
{
	class PinFactory
	{
	public:
		static Pin* slot(const PinSlot::Slot slot, const PinDirection::Direction direction);
		static Pin* name(const PinName::Name slot, const PinDirection::Direction direction);

		static void reclaim(Pin* pin);
		static void reclaimAll();

	private:
		PinFactory();
		~PinFactory();
		PinFactory(const PinFactory& other) = delete; // non construction-copyable
		PinFactory& operator=(const PinFactory&) = delete; // non copyable

		static PinFactory& getInstance();

		Pin* fetchPin(uint8_t key, uint8_t direction);
		void destroy(Pin* pin);
		void destroyAll();


		static std::unordered_map<uint8_t, Pin*> pins;

		static const uint8_t PIN_MAX = 97;
		static PinInfo PinDefaults[PIN_MAX];
	};

}

