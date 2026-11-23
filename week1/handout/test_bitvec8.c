#include "bitvec8.h"
#include "assert.h"
#include "stdio.h"


void test_bitvec8_from_int(void) {
  assert(bitvec8_from_int(0xFF) == 255);
  assert(bitvec8_from_int(0x00) == 0);
  assert(bitvec8_from_int(0x100) == 0);
  assert(bitvec8_from_int(0x101) == 1);
  assert(bitvec8_from_int(0x111) == 17);
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

void test_bitvec8_set(void) {
  assert(bitvec8_set(0,0)== 1);
  assert(bitvec8_set (0,3) == 8);
  assert(bitvec8_set(8,3) == 8);
  printf("Test %s passed!\n", __func__);
}

void test_bitvec8_clear(void) {
  assert(bitvec8_clear(4,0) == 4);
  assert(bitvec8_clear(4,2) == 0);
  assert(bitvec8_clear(9,0)== 8);
  printf("Test %s passed!\n", __func__);
}

void test_bitvec8_get(void) {
  assert(bitvec8_get(4,2) == 1);
  assert(bitvec8_get(4,1) == 0);
  assert(bitvec8_get(2,1) == 1);
  printf("Test %s passed!\n", __func__);
}

void test_bitvec8_all(void) {
  assert(bitvec8_all(255) == true);
  assert(bitvec8_all(0)   == false);
  assert(bitvec8_all(254) == false);
  printf("Test %s passed!\n", __func__);
}

void test_bitvec8_any(void) {
  assert(bitvec8_any(255) == true);
  assert(bitvec8_any(0) == false);
  assert(bitvec8_any(8) == true);
  printf("Test %s passed!\n", __func__);
}

void test_bitvec8_none(void) {
  assert(bitvec8_none(0) == true);
  assert(bitvec8_none(255) == false);
  assert(bitvec8_none(8) == false);
  printf("Test %s passed!\n", __func__);
}

void test_bitvec8_one(void) {
  assert(bitvec8_one(0) == false);
  assert(bitvec8_one(255) == false);
  assert(bitvec8_one(8) == true);
  assert(bitvec8_one(3)== false);
  printf("Test %s passed!\n", __func__);
}

int main(void) {
  test_bitvec8_from_int();
  test_bitvec8_to_int();
  test_bitvec8_print();
  test_bitvec8_set();
  test_bitvec8_clear();
  test_bitvec8_get();
  test_bitvec8_all();
  test_bitvec8_any();
  test_bitvec8_none();
  test_bitvec8_one();
  printf("All tests passed!\n");
  return 0;

}
