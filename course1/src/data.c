#include <stdint.h>
#include "memory.h"

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base) {
  *ptr = 0;
  uint8_t len = 1;
  uint8_t sign = 0; //for +ve
  if (data < 0) {
    sign = 1; //for -ve sign
    data *= -1;
  }
  do
  {
    *(ptr+len++)= '0' + (data%base);
  }while(data /= base);

  if(sign) {
    *(ptr+len++) = '-';
  }
  my_reverse(ptr, len);
  return len;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base) {
  int32_t sign = 1;
  int32_t ret = 0;
  if(*ptr == '-') {
    sign = -1;
    ptr++;
    --digits;
  }
  //Ignore if +ve sign
  else if(*ptr == '+') {
    ptr++;
    --digits;
  }
  while(--digits) {
    ret = ret * base + (*ptr - '0');
    ptr++;
  }
  return (ret*sign);
}

