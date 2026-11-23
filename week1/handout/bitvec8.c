#include "stdio.h"
#include "bitvec8.h"


//it starts over when it overflows(truncates) (hits FF or 255) it starts over back to 0
bitvec8 bitvec8_from_int(unsigned int x) {
  return 0xFF & x;
}

unsigned int bitvec8_to_int(bitvec8 v) {
  return v;
}

void bitvec8_print(bitvec8 v) {
  putchar('0' + ((v>>7) & 1));
  putchar('0' + ((v>>6) & 1));
  putchar('0' + ((v>>5) & 1));
  putchar('0' + ((v>>4) & 1));
  putchar('0' + ((v>>3) & 1));
  putchar('0' + ((v>>2) & 1));
  putchar('0' + ((v>>1) & 1));
  putchar('0' + (v & 1));
}

bitvec8 bitvec8_set(bitvec8 v, int i) {
  return v | (1 << i);
}

// Clear bit at position i to 0
bitvec8 bitvec8_clear(bitvec8 v, int i){
  return v &~(1 << i);
}

// Get bit at position i
bool bitvec8_get(bitvec8 v, int i){
  return v &(1<< i);
}

// Check if all bits are set
bool bitvec8_all(bitvec8 v){
  return v == 0xFF;
}

// Check if any bit is set
bool bitvec8_any(bitvec8 v){
  return v!= 0;
}

// Check if no bits are set
bool bitvec8_none(bitvec8 v){
  return v == 0;
}

// Check if exactly one bit is set
bool bitvec8_one(bitvec8 v){
  return v != 0 && (v & (v - 1)) == 0;
}