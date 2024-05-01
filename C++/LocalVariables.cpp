/*
In all programming languages:
- local variables exist only while function / code block is executing

In C/C++:
- memory needed for local variables are allocated on execution stack
- when a local variable is created, its value is not automatically initialised
  - variables simply contain data present in the memory at this time
  - debug code initialises the local variables to 0xcc
- program can retrieve address of local variables and use it
- the memory local variables use is released when function returns and move the stack pointer back to the address where it was when the function has been called
- a stack pointer is a small register that stores the memory address of the last data element added to the stack or, in some cases, the first available address in the stack
- stack pointer use Last In First Out basis

In terms of security:
- when variable is not correctly initialised, it may contain data it should not
- always completely initialise the local variable
- if local variable contains important information, the function must clear it before returning

Local variable's address:
- if a function returns the address of a local variable, it can sometimes work because the caller retrieves the data before calling other functions ( bad method )
- if a function passes the address of a local variable to another function, the function called should not store the address
- address stored and used later would access completely different data

Data leak:
- happens when library or program accidentally let some important data outside of its controlled memory/storage space
- if 0xcc is found in the data of the program's debug version, a data leak is possible
- example of scenario:
  1. a server receives request from the network on a datagram based socket (UDP)
  2. when the request is valid, it process it and sends the answer
  3. if request is invalid, a field in it is replaced with an error code and returns the request itself
*/
