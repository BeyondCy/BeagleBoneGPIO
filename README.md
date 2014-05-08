BeagleBoneGPIO
==============

C++11 Beagle Bone GPIO library

#### Usage

1. include "BBGPIO/BBGPIO.h" in your project.  
2. Use static methods of the PinFactory class to create Pin objects (which are automatically freed for you).  
3. Read or write to the Pin as needed.

There is a simple [test driver that oscillates an output](https://github.com/zerosum0x0/BeagleBoneGPIO/blob/master/main.cpp) pin between high and low every 1 second.

#### License
BBGPIO is released under the wutdoPL v1.0

           DO WHAT YOU WANNA WUTDO PUBLIC LICENSE
                   Version 1.0, May 2014

Copyright (C) 2014 zerosum0x0 <zerosum0x0@gmail.com>
       TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION

 0. You just DO WHAT YOU WANNA WUTDO.

#### Why C++ over C?
Taking advantage of the features granted by C++ enables the library to be much more easily used and expressive, while still making optimizations that are not easily available in C.  BeagleBone chips are not 8-bit microcontrollers, they're fully-fledged computers running 32-bit operating systems.  

One example of benefits over C is that our pin table uses std::unordered_map and provides lookups in O(1) time.  While it's true that hash maps can also be created in C (though not as easily or safely), other GPIO libraries we looked at that are written in C use linked lists or iterative-searched arrays, resulting in O(n) time lookups.  In other words, the C++ implementation of this one feature alone is up to 97x faster than the C equivalents we looked at.

Another concern brought up (which is also a problem in C as well) is dynamic memory allocation, which can pollute the memory space of a device, especially one you want to leave running for 5+ years.  This is not a concern as the only dynamic memory used is a constant size and stored indefinitely, freed automatically for you using the C++ RAII design pattern when the program exits or when references to the library fall off the stack. 
