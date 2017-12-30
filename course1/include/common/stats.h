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
 * @file stats.h
 * @brief Defines the functions
 *
 * The following functions are defined here:
 *   - print_statistics
 *   - print_array
 *   - find_median
 *   - find_mean
 *   - find_maximum
 *   - find_minimum
 *   - sort_array
 *
 * @author Anup Nayak
 * @date 18th Dec '17
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Declarations and Function Comments */ 

/**
 * @brief Prints statistics.
 *
 * The function prints prints the statistics of an array 
 * including minimum, maximum, mean, and median.
 *
 * @param min unisigned char value for minimum
 * @param min unisigned char value for maximum
 * @param min unsigned char value for mean
 * @param min unsigned char value for median
 *
 * @return none.
 */
void print_statistics(unsigned char min,
		      unsigned char max,
		      unsigned char mean,
		      unsigned char median);

/**
 * @brief Prints the array to the screen given an array
 * of unsigned char and length.
 *
 * The function prints array elements separated by
 * spaces and values are right aligned. All the
 * elements are enclosed with a sqare bracket.
 *
 * @param arr The input array of unsigned char to be printed.
 * @param size The size of array.
 *
 * @return none.
 */
void print_array(unsigned char arr[], size_t size);

/**
 * @brief Given an array of data and a length, returns the median value
 *
 * The function finds the median value of the data in an array.
 * It expects the caller to make sure that it pass an sorted
 * non-empty array.
 *
 * @param arr The input array of unsigned char.
 * @param size The size of array.
 *
 * @return The median unisgned char value.
 */
unsigned char find_median(unsigned char arr[], size_t size);

/**
 * @brief Given an array of data and a length, returns the mean value
 *
 * The function finds the mean value of the data in an array.
 *
 * @param arr The input array of unsigned char.
 * @param size The size of array.
 *
 * @return The mean unsigned char value.
 */
unsigned char find_mean(unsigned char arr[], size_t size);

/**
 * @brief Given an array of data and a length, returns the maximum
 *
 * The function finds the maximum of the data in an array.
 * It expects the caller to make sure that it does not pass an
 * empty array.
 *
 * @param arr The input array of unsigned char.
 * @param size The size of array.
 *
 * @return The maximum value.
 */
unsigned char find_maximum(unsigned char arr[], size_t size);

/**
 * @brief Given an array of data and a length, returns the minimum
 *
 * The function finds the minimum of the data in an array.
 * It expects the caller to make sure that it does not pass an
 * empty array.
 *
 * @param arr The input array of unsigned char.
 * @param size The size of array.
 *
 * @return The minimum value.
 */
unsigned char find_minimum(unsigned char arr[], size_t size);

/**
 * @brief Given an array of data and a length, sorts the array
 * from largest to smallest.
 *
 * The function sort the array from largest to smallest.
 * It uses the C library's quick sort (qsort).
 *
 * @param arr The input array of unsigned char to be sorted.
 *            The same array hold the sorted elements.
 * @param size The size of array.
 *
 * @return None.
 */
void sort_array(unsigned char arr[], size_t size);

#endif /* __STATS_H__ */
