BeagleBoneGPIO
==============

C++ Beagle Bone GPIO library


#### Why C++ over C?
BeagleBone chips are not 8-bit microcontrollers.  They are fully-fledged computers running 32-bit operating systems.  Taking advantage of the features granted by C++ enables the library to be much more easily used and expressive, while still making optimizations that are not easily available in C.  

One example of benefits over C is that our pin table uses std::hash_map and provides lookups in O(1) time.  While i's true that hash maps can also be created in C (though not as easily or safely), other GPIO libraries we looked at that are written in C use linked lists or iterative-searched arrays, resulting in O(n) time lookups.  In other words, the C++ implementation of this one feature alone is up to 97x faster than the C equivalents we looked at.

Another concern brought up (which is also a problem in C as well) is dynamic memory allocation, which can pollute the memory space of a device, especially one you want to leave running for 5+ years.  This is not a concern as the only dynamic memory used is a constant size and stored indefinitely, freed when the program exits or when references to the library fall off the stack.  A bonus is that you do not need to worry about memory management for this library, as all pin objects will be freed automatically for you using the C++ RAII design pattern.

All of the code written in this library was done with maximum performance in mind.  The C++ and the generated machine code has been heavily audited to ensure efficiency and readability greater than the C libraries.
