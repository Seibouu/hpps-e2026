#include "stdint.h"

typedef uint8_t bitvec8;

// Convert, and possibly truncate, an unsigned int value
// into a bitvec8 value.
bitvec8 bitvec8_from_int(unsigned int x);

// Convert a bitvec8 value into an unsigned int value.
unsigned int bitvec8_to_int(bitvec8 x);

// prints a bitvec8 value.  
void bitvec8_print(bitvec8 v);

bitvec8 bitvec8_add(bitvec8 x, bitvec8 y);

// Return the negation of a bitvec8, as a bitvec8.
bitvec8 bitvec8_negate(bitvec8 x);

// Multiply, and possibly truncate, two bitvec8 values
// into a bitvec8 value. 
bitvec8 bitvec8_mul(bitvec8 x, bitvec8 y);