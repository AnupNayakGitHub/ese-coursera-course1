/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c
 * @brief Defination of declared function in stats.h.
 *
 * Implements the funcitons defined in stats.h.
 * Additionally, it has main funciton to test the function.
 *
 * @author Anup Nayak
 * @date 18th Dec '17
 *
 */



#include <stdio.h>
#include <stdlib.h>
#include "stats.h"

/* Size of the Data Set */
//#define SIZE (40)

//int main() {

//  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
//                              114, 88,   45,  76, 123,  87,  25,  23,
//                              200, 122, 150, 90,   92,  87, 177, 244,
//                              201,   6,  12,  60,   8,   2,   5,  67,
//                                7,  87, 250, 230,  99,   3, 100,  90};

  // Other Variable Declarations Go Here 
  // Statistics and Printing Functions Go Here 
  // printf("Original array is:\n");
  // print_array(test, SIZE);
  // sort_array(test, SIZE);
  // print_statistics(find_minimum(test,SIZE),
  //		   find_maximum(test,SIZE),
  //		   find_mean(test,SIZE),
  //		   find_median(test,SIZE));
  // printf("Sorted array is:\n");
  // print_array(test, SIZE);

//  return 0;
//}

void print_statistics(unsigned char min,
                      unsigned char max,
                      unsigned char mean,
		      unsigned char median) {
  printf("Statistics :\n");
  printf("  Minimum : %u\n", min);
  printf("  Maximum : %u\n", max);
  printf("  Mean    : %u\n", mean);
  printf("  Median  : %u\n", median);
}

void print_array(unsigned char arr[], size_t size) {
#ifdef VERBOSE
  printf("[ ");
  for(int i = 0; i < size; ++i) {
    printf("%9u ", arr[i]);
  }
  printf("]\n");
#endif
}

unsigned char find_median(unsigned char arr[], size_t size) {
  unsigned int offset = size/2;

  // odd number of elements
  if(size%2) 
    return arr[offset];

  //even number of elements 
  return ((arr[offset] + arr[offset-1])/2);  
}


unsigned char find_mean(unsigned char arr[], size_t size) {
  unsigned int sum = 0;

  for (int i = 0; i < size; ++i) {
    sum += arr[i];
  }
  // Return 0 when the array is empty and
  // average otherwise.
  return (size==0)?0:(sum/size);
}

unsigned char find_maximum(unsigned char arr[], size_t size) {
  unsigned char max = arr[0];
  for (int i = 1; i < size; ++i) {
    if (arr[i] > max) max = arr[i];
  }
  return max;
}


unsigned char find_minimum(unsigned char arr[], size_t size) {
  unsigned char min = arr[0];
  for (int i = 1; i < size; ++i) {
    if (arr[i] < min) min = arr[i];
  }
  return min;
}

void sort_array(unsigned char arr[], size_t size) {
  // Local function to compare two values
  int cmpfunc (const void * a, const void * b) {
    return ( *(unsigned char*)b - *(unsigned char*)a );
  }
  // Quick sort C library function to sort the array
  qsort(arr, size, sizeof(unsigned char), cmpfunc);
}

