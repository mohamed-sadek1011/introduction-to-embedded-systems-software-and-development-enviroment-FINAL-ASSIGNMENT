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
 *
 * @brief This source file contains functions that get some stats from an array
 *
 * @author Mohamed Sadek
 * @date Tuesday, October 13,2020 
 *
 */



#include "platform.h"
#include "stats.h"


void print_statistics (unsigned char minimum,unsigned char maximum,unsigned char mean, unsigned char median)
{
  PRINTF("The array statistics:\n");
  PRINTF("The minimum number is : %d\n",minimum);
  PRINTF("The maximum number is : %d\n",maximum);
  PRINTF("The median is : %d\n",median);
  PRINTF("The mean is : %d\n",mean);
}

void print_array (unsigned char* array_adress,unsigned char array_length)
{
  #ifdef VERBOSE
    PRINTF("%d elements array:\n",array_length);

    for (unsigned char i = 1; i <= array_length ; i++)
    {
      if ( i == 1 )
        PRINTF("{%d, ",*array_adress);
      else if ( i == array_length )
        PRINTF("%d}\n",*array_adress);
      else
        PRINTF("%d, ",*array_adress);
      array_adress++;
    }
  #endif
}

unsigned char find_median (unsigned char* array_adress,unsigned char array_length)
{
  unsigned char median;
  sort_array(array_adress,array_length);
  if ( array_length % 2 == 0 )
  {
    array_adress += (array_length/2);
    median = *array_adress;
    array_adress++;
    median = ( median + *array_adress ) / 2;
  }
  else
  {
    array_adress += (array_length/2+1);
    median = *array_adress;
  }
  return median;
}

unsigned char find_mean (unsigned char* array_adress,unsigned char array_length)
{
  unsigned short int sum = 0;
  unsigned char mean;

  for ( unsigned char i = 1 ; i <= array_length ; i++ )
  {
    sum += *array_adress;
    array_adress++; 
  }

  mean = sum/array_length;
  return mean;

}

unsigned char find_maximum (unsigned char* array_adress,unsigned char array_length)
{
  sort_array(array_adress,array_length);
  return *array_adress;
}

unsigned char find_minimum (unsigned char* array_adress,unsigned char array_length)
{
  sort_array(array_adress,array_length);
  array_adress += (array_length-1);
  return *array_adress;

}

void sort_array (unsigned char* array_adress,unsigned char array_length)
{
  unsigned char* prev_element_adress = array_adress;
  unsigned char* current_element_adress = array_adress+1;
  for ( unsigned char i = 1 ; i <= (array_length-1)  ; i++ )
  {
    prev_element_adress = array_adress;
    current_element_adress = array_adress+1;

    for ( unsigned char i = 1 ; i <= (array_length-1) ; i++ )
    {
      if ( *prev_element_adress < *current_element_adress )
        exchange_two_variables( prev_element_adress, current_element_adress );

      prev_element_adress++;
      current_element_adress++;

    }
  }
}


void exchange_two_variables(unsigned char* x, unsigned char* y)
{
  *x = *x + *y;
  *y = *x - *y;
  *x = *x - *y;
}
