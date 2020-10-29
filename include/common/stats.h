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
 * @brief All function prototypes and function documentation are added to this header file
 *
 * Check "README.md" file for more information about this program
 *
 * @author  Mohamed Sadek 
 * @date  Tuesday, October 13,2020 
 *
 */
#ifndef __STATS_H__
#define __STATS_H__
 

/**
 * @brief A function that prints the statistics of an array including minimum, maximum, mean, and median
 *
 * This function takes the values of minimum, maximum, mean, and median and prints them out to display, it does not return any value
 *
 * @param minimum The minimum value in the array
 * @param maximum The maximum value in the array
 * @param mean The mean value of the array
 * @param median The median value of the array
 *
 * @return No value to return (void)
 */
void print_statistics (unsigned char minimum,unsigned char maximum,unsigned char mean, unsigned char median);


/**
 * @brief A function that prints an array to the screen
 *
 * This function takes the adress of an array of data and its length and prints the array to the screen, it doesn't return any value
 *
 * @param array_adress This is the adress of the first element in the array
 * @piram array_length The length of the array
 *
 * @return No value to return (void)
 */
void print_array (unsigned char* array_adress,unsigned char array_length);


/**
 * @brief A function that returns the median value of an array.
 *
 * This function takes the adress of an array of data and its length and returns the value of its median
 *
 * @param array_adress This is the adress of the first element in the array.
 * @param array_length The length of the array.
 *
 * @return The median of the given array.
 */
unsigned char find_median (unsigned char* array_adress,unsigned char array_length);


/**
 * @brief A function that returns the mean value of an array.
 *
 * This function takes the adress of an array of data and its length and returns the value of its mean.
 *
 * @param array_adress This is the adress of the first element in the array.
 * @param array_length The length of the array.
 *
 * @return The mean of the given array.
 */
unsigned char find_mean (unsigned char* array_adress,unsigned char array_length);


/**
 * @brief A function that returns the maximum value of an array.
 *
 * This function takes the adress of an array of data and its length and returns the value of its maximum value.
 *
 * @param array_adress This is the adress of the first element in the array.
 * @param array_length The length of the array.
 *
 * @return The maximum value of the given array.
 */
unsigned char find_maximum (unsigned char* array_adress,unsigned char array_length);


/**
 * @brief A function that returns the minimum value of an array.
 *
 * This function takes the adress of an array of data and its length and returns its minimum value.
 *
 * @param array_adress This is the adress of the first element in the array.
 * @param array_length The length of the array.
 *
 * @return The minimum value of the given array.
 */
unsigned char find_minimum (unsigned char* array_adress,unsigned char array_length);


/**
 * @brief A function that sorts an array values from largest to smallest.
 *
 * This function will take the adress of an array and the length of that array,then it sorts the array from largest to smallest.
 * The zeroth Element should be the largest value, and the last element (n-1) should be the smallest value.
 *
 * @param array_adress This is the adress of the first element in the array.
 * @param array_length The length of the array.
 *
 * @return No value to return (void)
 */
void sort_array (unsigned char* array_adress,unsigned char array_length);


/**
 * @brief A function that swpas the values of two variables
 *
 * This function will take the adresses of two variables in memory, and swaps the values of these two variables
 * This function doesn't return anything
 *
 * @param x This is the adress of the frst variable to swap.
 * @param y This ts the adress of the second variable to swap
 *
 * @return No value to return (void)
 */
void exchange_two_variables(unsigned char* x, unsigned char* y);

#endif /* __STATS_H__ */
