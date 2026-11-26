#include "bitvec8.h"
#include "assert.h"
#include "stdio.h"

void test_bitvec8_from_int(void) {
  assert(bitvec8_from_int(0xFF) == 255);
  assert(bitvec8_from_int(0x00) == 0);
  assert(bitvec8_from_int(0x100) == 0);
  assert(bitvec8_from_int(0x101) == 1);
  printf("Test %s passed!\n", __func__);
}


void test_bitvec8_to_int(void) {
  assert(bitvec8_to_int(0xFF) == 255);
  assert(bitvec8_to_int(0x00) == 0);
  assert(bitvec8_to_int(0x01) == 1);
  printf("Test %s passed!\n", __func__);
}

void test_bitvec8_print(void) {
  printf("0xFF == ");
  bitvec8_print(0xFF);
  printf("\n");
  printf("0x00 == ");
  bitvec8_print(0x00);
  printf("\n");
  printf("0x01 == ");
  bitvec8_print(0x01);
  printf("\n");
  printf("0xEF == ");
  bitvec8_print(0xEF);
  printf("\n");
  printf("Test %s!\n", __func__);
}

void test_bitvec8_add(void) {
  assert(bitvec8_to_int(bitvec8_add(bitvec8_from_int(1), bitvec8_from_int(1))) == 2);
  assert(bitvec8_to_int(bitvec8_add(bitvec8_from_int(1), bitvec8_from_int(0))) == 1);
  assert(bitvec8_to_int(bitvec8_add(bitvec8_from_int(127), bitvec8_from_int(1))) == 128);
  assert(bitvec8_to_int(bitvec8_add(bitvec8_from_int(255), bitvec8_from_int(1))) == 0);
  printf("Test %s passed!\n", __func__);
}
  
void test_bitvec8_negate(void) {
  assert(bitvec8_to_int(bitvec8_negate(bitvec8_from_int(1))) == 255);
  assert(bitvec8_to_int(bitvec8_negate(bitvec8_from_int(0))) == 0);
  assert(bitvec8_to_int(bitvec8_negate(bitvec8_from_int(5))) == 251);
  assert(bitvec8_to_int(bitvec8_negate(bitvec8_from_int(255))) == 1);
  assert(bitvec8_to_int(bitvec8_negate(bitvec8_from_int(127))) == 129);
  assert(bitvec8_to_int(bitvec8_negate(bitvec8_from_int(128))) == 128);
  printf("Test %s passed!\n", __func__);
}


int main(void) {
  test_bitvec8_from_int();
  test_bitvec8_to_int();
  test_bitvec8_print();
  test_bitvec8_add();
  test_bitvec8_negate();

  printf("All tests passed!\n");
  return 0;
  
}


