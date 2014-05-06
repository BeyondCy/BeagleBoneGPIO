#ifndef BBGPIO_PIN_H
#define BBGPIO_PIN_H

namespace BBGPIO
{


    typedef struct PinInfo
    {

    } PinInfo;


    class Pin
    {

    public:
        Pin();

    private:
        PinInfo pinInfo;

        static PinInfo pinInfoTable[97];
    };


} // namespace BBGPIO

#endif // PIN_H
