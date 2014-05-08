#ifndef BBGPIO_PIN_H
#define BBGPIO_PIN_H

#include <string>

#include "pininfo.h"

namespace BBGPIO
{
	class Pin
    {
	public:
        Pin(PinInfo info);
		~Pin();

		inline PinSlot::Slot slot() const { return static_cast<PinSlot::Slot>(this->pinInfo.slot); }
		inline PinName::Name name() const { return static_cast<PinName::Name>(this->pinInfo.name); }
		inline uint8_t gpio() const { return this->pinInfo.gpio;  }

		/* Direction Methods */
		bool isInput() const;
		void setInput() const;

		bool isOutput() const;
		void setOutput() const;

		PinDirection::Direction direction() const;
		void setDirection(PinDirection::Direction direction) const;

		/* Signal Methods */
		bool isHigh() const;
		void setHigh() const;

		bool isLow() const;
		void setLow() const;
		
		PinSignal::Signal signal() const;
		void setSignal(PinSignal::Signal signal) const;

	protected:
		void setPaths();
		void export();
		void unexport();

    private:
        PinInfo pinInfo;

		static const char* GPIO_DIR;
		static const char* GPIO_EXPORT;
		static const char* GPIO_UNEXPORT;

		std::string directionPath;
		std::string valuePath;
    };


} // namespace BBGPIO

#endif // PIN_H
