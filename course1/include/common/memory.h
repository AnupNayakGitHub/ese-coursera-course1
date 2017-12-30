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
 * @file memory.h
 * @brief Abstraction of memory read and write operations
 *
 * This header file provides an abstraction of reading and
 * writing to memory via function calls. 
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <stdint.h>
#include <stddef.h>

/**
 * @brief Sets a value of a data array 
 *
 * Given a pointer to a char data set, this will set a provided
 * index into that data set to the value provided.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 * @param value value to write the the locaiton
 *
 * @return void.
 */
void set_value(char * ptr, unsigned int index, char value);

/**
 * @brief Clear a value of a data array 
 *
 * Given a pointer to a char data set, this will clear a provided
 * index into that data set to the value zero.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return void.
 */
void clear_value(char * ptr, unsigned int index);

/**
 * @brief Returns a value of a data array 
 *
 * Given a pointer to a char data set, this will read the provided
 * index into that data set and return the value.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return Value to be read.
 */
char get_value(char * ptr, unsigned int index);

/**
 * @brief Sets data array elements to a value
 *
 * Given a pointer to a char data set, this will set a number of elements
 * from a provided data array to the given value. The length is determined
 * by the provided size parameter.
 *
 * @param ptr Pointer to data array
 * @param value value to write the the locaiton
 * @param size Number of elements to set to value
 *
 * @return void.
 */
void set_all(char * ptr, char value, unsigned int size);

/**
 * @brief Clears elements in a data array
 *
 * Given a pointer to a char data set, this will set a clear a number
 * of elements given the size provided. Clear means to set to zero. 
 *
 * @param ptr Pointer to data array
 * @param size Number of elements to set to zero
 *
 * @return void.
 */
void clear_all(char * ptr, unsigned int size);

/**
 * @brief moves data from one location to another location
 *
 * Given a pointer to a destination it moves specified number of 
 * data from source location. Length specifies the number of data.
 *
 * @param src Pointer to source
 * @param dst Pointer to destination
 * @param length Number of elements to move
 *
 * @return ptr to destination
 */
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief copies data from one location to another location
 *
 * Given a pointer to a destination, it copies specified number of 
 * data from source location. Length specifies the number of data.
 *
 * @param src Pointer to source
 * @param dst Pointer to destination
 * @param length Number of elements to copy
 *
 * @return ptr to destination
 */
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief sets the value of each element.
 *
 * Given a pointer to a source, it initializes specified number of 
 * elements starting from source location. Length specifies the number 
 * of elements.
 *
 * @param src Pointer to source
 * @param length Number of elements to initialize
 * @param value Initialization value
 *
 * @return ptr to src
 */
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value);

/**
 * @brief sets the value of each element to zero
 *
 * Given a pointer to a source, it initializes specified number of 
 * elements starting from source location. Length specifies the number 
 * of elements.
 *
 * @param src Pointer to source
 * @param length Number of elements to initialize
 *
 * @return ptr to src
 */
uint8_t * my_memzero(uint8_t * src, size_t length);

/**
 * @brief reverses array of elements.
 *
 * Given a pointer to a source, it reverses the order of elements. 
 *
 * @param src Pointer to source
 * @param length Number of elements to be reversed
 *
 * @return ptr to src
 */
uint8_t * my_reverse(uint8_t * src, size_t length);

/**
 * @brief reserves memory in the heap.
 *
 * Given a length, it reserves specified number of words.
 *
 * @param length Number of words to be reserved.
 *
 * @return ptr to reserved memory
 */
int32_t * reserve_words(size_t length);


/**
 * @brief frees memory from the heap.
 *
 * frees the memory specied by src.
 *
 * @param src Pointer to memory to be freed
 *
 * @return void
 */
//void free_words(int32_t * src);
void free_words(uint32_t * src);

#endif /* __MEMORY_H__ */
