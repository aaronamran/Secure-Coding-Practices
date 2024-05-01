/*
C : malloc and free to allocate and release memory
C++ : new and delete to allocate and release memory
- exception in Windows: in "Debug" configuration of Microsoft Visual Studios, memory is initialised at 0xcd

- malloc does not initialise the memory
- allocated memory still contains what was in it when other parts of the program freed it
- allocated memory MUST always be initialised
- important data MUST be cleared before releasing memory

- new calls the class constructor
- constructor initialises the memory

- new char[256] -> char is not a class, no constructor to call
- memory is not initialised

Heap Randomisation
- does not reduce data leak risk, but makes data leak unpredictable for exploits
- MUST always be enabled
- In Microsoft Visual Studios, go to:
  Project property page -> Linker -> Advanced -> Randomised base address (Enable it) -> Recompile 
*/
