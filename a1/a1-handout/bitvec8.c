#include "stdio.h"
#include "bitvec8.h"

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

struct add_result {
    bitvec8 s;
    bitvec8 c;
};

struct add_result sum_and_carry(bitvec8 x, bitvec8 y) {
    struct add_result res;
    
    // TODO: Udregn del-summen med XOR og gem den i res.s
    res.s = x ^ y;
    
    // TODO: Udregn carry med AND, shift den 1 til venstre, og gem den i res.c
    res.c = (x & y) << 1;
    
    return res;
}
 
// Add, and possibly truncate, two bitvec8 values
// into a bitvec8 value.
bitvec8 bitvec8_add(bitvec8 x, bitvec8 y) {
    struct add_result res = sum_and_carry(x, y);
    res = sum_and_carry(res.s, res.c);
    res = sum_and_carry(res.s, res.c);
    res = sum_and_carry(res.s, res.c);
    res = sum_and_carry(res.s, res.c);
    res = sum_and_carry(res.s, res.c);
    res = sum_and_carry(res.s, res.c);
    res = sum_and_carry(res.s, res.c);
    res = sum_and_carry(res.s, res.c);

    return res.s;
}

bitvec8 bitvec8_negate(bitvec8 x){
  return bitvec8_add(~x,1);
};

bitvec8 bitvec8_mul(bitvec8 x, bitvec8 y){
  
};

