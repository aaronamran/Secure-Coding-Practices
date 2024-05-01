/* 
1. Signed (negative and positive) vs Unsigned Integer (only positive)
  - Integer size
  - Standard integer type
2. Comparing integers
3. Overflow / Underflow

Part 1: 
8-bit signed integer
- possible positive values = 0000 0001 -> 0111 1111 | 1 -> 127
- possible negative values = 1111 1111 -> 1000 0000 | -1 -> -128
- computers use "2's complements" to store negative integer value
- to change sign of integer, all bits are reversed and 1 is added
  - example:
    127 -> 0111 1111 -> 1000 0000+1 -> 1000 0001 -> -127
    1 -> 0000 0001 -> 1111 1110+1 -> 1111 1111 -> -1
    0 -> 0000 0000 -> 1111 1111+1 -> (1) 0000 0000 (1 is removed, because extra digit) -> 0
    -1 -> 1111 1111 -> 0000 0000+1 -> 0000 0001 -> 1
    -128 -> 1000 0000 -> 0111 1111+1 -> 1000 0000 -> -128

- when naming variables, put l in front of names to indicate local. Example: lFile, lData
 
Integer type size ( can create test program and use sizeof(int) )
- char / unsigned char = 8 bits
- short / unsigned short = 16 bits
- int / unsigned int = 32 bits (sometimes 64 bits, 16 bits are in the past)
- long / unsigned long = either 32 or 64 bits
- long long / unsigned long long = 64 bits
(On Linux, 32 bits and 64 bits Windows, some integer types don't have the same size -> more convenient to use standard integer type)
- use int and unsigned int when size does not matter


Part 2: 
Comparing Integers
- result of comparison varies on how compiler performs it
- some compilers give a warning ( take note! )
- Best Solution: avoid signed / unsigned comparison


Part 3:
Overflow / Underflow
- Overflow: when result exceeds maximum value that can be stored by the data type
*/

int a = INT_MAX;
int b = 1;
int result = a + b;
if (result < a || result < b) {
    // Overflow occurred
}

/*
- Underflow: when result is smaller than minimum value that can be stored by the data type
*/
int c = INT_MIN;
int d = 1;
int result = c - d;
if (result > c || result > d) {
    // Underflow occurred
}

/* 
Signed Validation

Signed Operation  |  A  |  B  |  After  
--------------------------------------------------------------
R = A + B         |  +  |  B  | if ((A<R) || (B<R)) Overflow!
                  |  +  |  -  | No 
                  |  -  |  +  | Risk
                  |  -  |  -  | if ((A>R) || (B>R)) Underflow!
--------------------------------------------------------------
R = A - B         |  +  |  +  | No Risk
                  |  +  |  -  | if (A>R) Overflow!
                  |  -  |  +  | if (A<R) Underflow!
                  |  -  |  -  | No Risk

- Divisions do not cause overflow or underflow
- Multiplications can clearly cause overflow ( check by doing division to verify if result is expected ) 
*/

