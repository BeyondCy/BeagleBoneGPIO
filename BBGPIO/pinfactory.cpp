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

	PinInfo PinFactory::PinDefaults[] =
	{
		{ PinName::USR0, PinSlot::USR0, 53, -1, -1, 1 },
		{ PinName::USR1, PinSlot::USR1, 54, -1, -1, 1 },
		{ PinName::USR2, PinSlot::USR2, 55, -1, -1, 1 },
		{ PinName::USR3, PinSlot::USR3, 56, -1, -1, 1 },
		{ PinName::DGND1, PinSlot::P8_1, 0, -1, -1, -1 },
		{ PinName::DGND2, PinSlot::P8_2, 0, -1, -1, -1 },
		{ PinName::GPIO1_6, PinSlot::P8_3, 38, -1, -1, 1 },
		{ PinName::GPIO1_7, PinSlot::P8_4, 39, -1, -1, 1 },
		{ PinName::GPIO1_2, PinSlot::P8_5, 34, -1, -1, 1 },
		{ PinName::GPIO1_3, PinSlot::P8_6, 35, -1, -1, 1 },
		{ PinName::TIMER4, PinSlot::P8_7, 66, -1, -1, 0 },
		{ PinName::TIMER7, PinSlot::P8_8, 67, -1, -1, 0 },
		{ PinName::TIMER5, PinSlot::P8_9, 69, -1, -1, 0 },
		{ PinName::TIMER6, PinSlot::P8_10, 68, -1, -1, 0 },
		{ PinName::GPIO1_13, PinSlot::P8_11, 45, -1, -1, 0 },
		{ PinName::GPIO1_12, PinSlot::P8_12, 44, -1, -1, 0 },
		{ PinName::EHRPWM2B, PinSlot::P8_13, 23, 4, -1, 0 },
		{ PinName::GPIO0_26, PinSlot::P8_14, 26, -1, -1, 0 },
		{ PinName::GPIO1_15, PinSlot::P8_15, 47, -1, -1, 0 },
		{ PinName::GPIO1_14, PinSlot::P8_16, 46, -1, -1, 0 },
		{ PinName::GPIO0_27, PinSlot::P8_17, 27, -1, -1, 0 },
		{ PinName::GPIO2_1, PinSlot::P8_18, 65, -1, -1, 0 },
		{ PinName::EHRPWM2A, PinSlot::P8_19, 22, 4, -1, 0 },
		{ PinName::GPIO1_31, PinSlot::P8_20, 63, -1, -1, 1 },
		{ PinName::GPIO1_30, PinSlot::P8_21, 62, -1, -1, 1 },
		{ PinName::GPIO1_5, PinSlot::P8_22, 37, -1, -1, 1 },
		{ PinName::GPIO1_4, PinSlot::P8_23, 36, -1, -1, 1 },
		{ PinName::GPIO1_1, PinSlot::P8_24, 33, -1, -1, 1 },
		{ PinName::GPIO1_0, PinSlot::P8_25, 32, -1, -1, 1 },
		{ PinName::GPIO1_29, PinSlot::P8_26, 61, -1, -1, 0 },
		{ PinName::GPIO2_22, PinSlot::P8_27, 86, -1, -1, 1 },
		{ PinName::GPIO2_24, PinSlot::P8_28, 88, -1, -1, 1 },
		{ PinName::GPIO2_23, PinSlot::P8_29, 87, -1, -1, 1 },
		{ PinName::GPIO2_25, PinSlot::P8_30, 89, -1, -1, 1 },
		{ PinName::UART5_CTSN, PinSlot::P8_31, 10, -1, -1, 1 },
		{ PinName::UART5_RTSN, PinSlot::P8_32, 11, -1, -1, 1 },
		{ PinName::UART4_RTSN, PinSlot::P8_33, 9, -1, -1, 1 },
		{ PinName::UART3_RTSN, PinSlot::P8_34, 81, 2, -1, 1 },
		{ PinName::UART4_CTSN, PinSlot::P8_35, 8, -1, -1, 1 },
		{ PinName::UART3_CTSN, PinSlot::P8_36, 80, 2, -1, 1 },
		{ PinName::UART5_TXD, PinSlot::P8_37, 78, -1, -1, 1 },
		{ PinName::UART5_RXD, PinSlot::P8_38, 79, -1, -1, 1 },
		{ PinName::GPIO2_12, PinSlot::P8_39, 76, -1, -1, 1 },
		{ PinName::GPIO2_13, PinSlot::P8_40, 77, -1, -1, 1 },
		{ PinName::GPIO2_10, PinSlot::P8_41, 74, -1, -1, 1 },
		{ PinName::GPIO2_11, PinSlot::P8_42, 75, -1, -1, 1 },
		{ PinName::GPIO2_8, PinSlot::P8_43, 72, -1, -1, 1 },
		{ PinName::GPIO2_9, PinSlot::P8_44, 73, -1, -1, 1 },
		{ PinName::GPIO2_6, PinSlot::P8_45, 70, 3, -1, 1 },
		{ PinName::GPIO2_7, PinSlot::P8_46, 71, 3, -1, 1 },
		{ PinName::DGND3, PinSlot::P9_1, 0, -1, -1, -1 },
		{ PinName::DGND4, PinSlot::P9_2, 0, -1, -1, -1 },
		{ PinName::VDD_3V3_1, PinSlot::P9_3, 0, -1, -1, -1 },
		{ PinName::VDD_3V3_2, PinSlot::P9_4, 0, -1, -1, -1 },
		{ PinName::VDD_5V_1, PinSlot::P9_5, 0, -1, -1, -1 },
		{ PinName::VDD_5V_2, PinSlot::P9_6, 0, -1, -1, -1 },
		{ PinName::SYS_5V_1, PinSlot::P9_7, 0, -1, -1, -1 },
		{ PinName::SYS_5V_2, PinSlot::P9_8, 0, -1, -1, -1 },
		{ PinName::PWR_BUT, PinSlot::P9_9, 0, -1, -1, -1 },
		{ PinName::SYS_RESETn, PinSlot::P9_10, 0, -1, -1, -1 },
		{ PinName::UART4_RXD, PinSlot::P9_11, 30, -1, -1, 0 },
		{ PinName::GPIO1_28, PinSlot::P9_12, 60, -1, -1, 0 },
		{ PinName::UART4_TXD, PinSlot::P9_13, 31, -1, -1, 0 },
		{ PinName::EHRPWM1A, PinSlot::P9_14, 50, 6, -1, 0 },
		{ PinName::GPIO1_16, PinSlot::P9_15, 48, -1, -1, 0 },
		{ PinName::EHRPWM1B, PinSlot::P9_16, 51, 6, -1, 0 },
		{ PinName::I2C1_SCL, PinSlot::P9_17, 5, -1, -1, 0 },
		{ PinName::I2C1_SDA, PinSlot::P9_18, 4, -1, -1, 0 },
		{ PinName::I2C2_SCL, PinSlot::P9_19, 13, -1, -1, 1 },
		{ PinName::I2C2_SDA, PinSlot::P9_20, 12, -1, -1, 1 },
		{ PinName::UART2_TXD, PinSlot::P9_21, 3, 3, -1, 0 },
		{ PinName::UART2_RXD, PinSlot::P9_22, 2, 3, -1, 0 },
		{ PinName::GPIO1_17, PinSlot::P9_23, 49, -1, -1, 0 },
		{ PinName::UART1_TXD, PinSlot::P9_24, 15, -1, -1, 0 },
		{ PinName::GPIO3_21, PinSlot::P9_25, 117, -1, -1, 1 },
		{ PinName::UART1_RXD, PinSlot::P9_26, 14, -1, -1, 0 },
		{ PinName::GPIO3_19, PinSlot::P9_27, 115, -1, -1, 0 },
		{ PinName::SPI1_CS0, PinSlot::P9_28, 113, 4, -1, 1 },
		{ PinName::SPI1_D0, PinSlot::P9_29, 111, 1, -1, 1 },
		{ PinName::SPI1_D1, PinSlot::P9_30, 112, -1, -1, 0 },
		{ PinName::SPI1_SCLK, PinSlot::P9_31, 110, 1, -1, 1 },
		{ PinName::VDD_ADC, PinSlot::P9_32, 0, -1, -1, -1 },
		{ PinName::AIN4, PinSlot::P9_33, 0, -1, 4, -1 },
		{ PinName::GNDA_ADC, PinSlot::P9_34, 0, -1, -1, -1 },
		{ PinName::AIN6, PinSlot::P9_35, 0, -1, 6, -1 },
		{ PinName::AIN5, PinSlot::P9_36, 0, -1, 5, -1 },
		{ PinName::AIN2, PinSlot::P9_37, 0, -1, 2, -1 },
		{ PinName::AIN3, PinSlot::P9_38, 0, -1, 3, -1 },
		{ PinName::AIN0, PinSlot::P9_39, 0, -1, 0, -1 },
		{ PinName::AIN1, PinSlot::P9_40, 0, -1, 1, -1 },
		{ PinName::CLKOUT2, PinSlot::P9_41, 20, -1, -1, 0 },
		{ PinName::GPIO0_7, PinSlot::P9_42, 7, 0, -1, 0 },
		{ PinName::DGND5, PinSlot::P9_43, 0, -1, -1, -1 },
		{ PinName::DGND6, PinSlot::P9_44, 0, -1, -1, -1 },
		{ PinName::DGND7, PinSlot::P9_45, 0, -1, -1, -1 },
		{ PinName::DGND8, PinSlot::P9_46, 0, -1, -1, -1 },
		{ NULL, NULL, 0 }
	};



} // namespace BBGPIO