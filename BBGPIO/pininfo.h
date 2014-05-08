#ifndef BBGPIO_PININFO_H
#define BBGPIO_PININFO_H

#include <stdint.h>

namespace BBGPIO
{
    namespace PinSlot
    {
        enum Slot
        {
            USR0 = 0, USR1, USR2, USR3,

            P8_1, P8_2, P8_3, P8_4, P8_5, P8_6, P8_7, P8_8, P8_9, P8_10,
            P8_11, P8_12, P8_13, P8_14, P8_15, P8_16, P8_17, P8_18, P8_19, P8_20,
            P8_21, P8_22, P8_23, P8_24, P8_25, P8_26, P8_27, P8_28, P8_29, P8_30,
            P8_31, P8_32, P8_33, P8_34, P8_35, P8_36, P8_37, P8_38, P8_39, P8_40,
            P8_41, P8_42, P8_43, P8_44, P8_45, P8_46,

            P9_1, P9_2, P9_3, P9_4,
            P9_5, P9_6, P9_7, P9_8, P9_9, P9_10, P9_11, P9_12, P9_13, P9_14,
            P9_15, P9_16, P9_17, P9_18, P9_19, P9_20, P9_21, P9_22, P9_23, P9_24,
            P9_25, P9_26, P9_27, P9_28, P9_29, P9_30, P9_31, P9_32, P9_33, P9_34,
            P9_35, P9_36, P9_37, P9_38, P9_39, P9_40, P9_41, P9_42, P9_43, P9_44,
            P9_45, P9_46
        };
    }

	namespace PinName
	{
		enum Name
		{
			USR0 = 0, USR1, USR2, USR3, DGND1, DGND2,
			GPIO1_6, GPIO1_7, GPIO1_2, GPIO1_3, TIMER4, TIMER7,
			TIMER5, TIMER6, GPIO1_13, GPIO1_12, EHRPWM2B, GPIO0_26,
			GPIO1_15, GPIO1_14, GPIO0_27, GPIO2_1, EHRPWM2A, GPIO1_31,
			GPIO1_30, GPIO1_5, GPIO1_4, GPIO1_1, GPIO1_0, GPIO1_29,
			GPIO2_22, GPIO2_24, GPIO2_23, GPIO2_25, UART5_CTSN, UART5_RTSN,
			UART4_RTSN, UART3_RTSN, UART4_CTSN, UART3_CTSN, UART5_TXD, UART5_RXD,
			GPIO2_12, GPIO2_13, GPIO2_10, GPIO2_11, GPIO2_8, GPIO2_9,
			GPIO2_6, GPIO2_7, DGND3, DGND4, VDD_3V3_1, VDD_3V3_2,
			VDD_5V_1, VDD_5V_2, SYS_5V_1, SYS_5V_2, PWR_BUT, SYS_RESETn,
			UART4_RXD, GPIO1_28, UART4_TXD, EHRPWM1A, GPIO1_16, EHRPWM1B,
			I2C1_SCL, I2C1_SDA, I2C2_SCL, I2C2_SDA, UART2_TXD, UART2_RXD,
			GPIO1_17, UART1_TXD, GPIO3_21, UART1_RXD, GPIO3_19, SPI1_CS0,
			SPI1_D0, SPI1_D1, SPI1_SCLK, VDD_ADC, AIN4, GNDA_ADC,
			AIN6, AIN5, AIN2, AIN3, AIN0, AIN1,
			CLKOUT2, GPIO0_7, DGND5, DGND6, DGND7, DGND8
		};
	}

	namespace PinDirection
	{
		enum Direction
		{
			OUTPUT = 0,
			INPUT
		};
	}

	namespace PinSignal
	{
		enum Signal
		{
			LOW = 0,
			HIGH
		};
	}

    typedef struct PinInfo
    {
		uint8_t name;
        uint8_t slot;
        
		uint8_t gpio;
		uint8_t pwmMuxMode;
		uint8_t ain;
		uint8_t allocated;
    } PinInfo;
}

#endif // PININFO_H
