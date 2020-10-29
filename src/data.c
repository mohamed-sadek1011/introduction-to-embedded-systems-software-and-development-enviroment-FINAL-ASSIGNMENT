
#include <stdint.h>
#include "platform.h"

uint8_t number_of_digits_counter(uint32_t num, uint8_t base)
{
  uint8_t counter = 0;

  while ( num != 0 )
    {
      counter++;
      num /= base;
    }
  return counter;
}

uint8_t udecimal_to_string ( uint32_t num, uint8_t* ptr, uint32_t base )
  {
    uint8_t length = 0;
    uint8_t size = number_of_digits_counter(num,base);
    ptr += size;
    *ptr = '\0';
    ptr--;
    length++;
    
    while ( num != 0 )
    {
        
        if ( (num % base) >=10)
        {
          *ptr = (num % base) + 55;
        }
        else
        {
          *ptr = (num % base) + 48;
        }
          PRINTF(" %d",*ptr);
        ptr--;
        length++;
        num = num/base;
    }
    return length;
  }


int32_t power(int32_t x,uint32_t y)
{
  int32_t result = x;

  for (uint8_t i=2 ; i<=y ; i++ )
  {
    result = result * x;
  }
 
  if (y<=0)
    result = 1;

  return result;
}


uint32_t sign_change(int32_t x)
{
  uint32_t result=0;
  result = x - x - x;
  return result;
}


uint8_t my_itoa( int32_t data, uint8_t *ptr, uint32_t base )
{
  uint32_t u_data = 0;
  uint8_t length = 0;
  if( ( base == 10 ) && (data<0) )
  {
    {
      *ptr = '-';
      ptr++;
      length++;
      u_data = sign_change(data);
    }
      length += udecimal_to_string(u_data,ptr,base);
}

  else 
  {
    u_data =  (uint32_t) data;
    PRINTF ("udata is %x\n",u_data); 
    length += udecimal_to_string(u_data,ptr,base);
  }
  return length;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base)
{
  int32_t result;
  uint32_t u_result;
  uint8_t negative_decimal_flag = 0;

  if ( *ptr == '-' )
  {
    ptr++;
    negative_decimal_flag = 1;
  }
    ptr += (digits-2);
    
  for (uint8_t i = 0 ; i < digits-1 ; i++)
  {
    if ( *ptr >= 65 )
    {
      *ptr -= 55;
    }
    else
    {
      *ptr -= 48;
    }

    u_result += *ptr * power(base,i);
    ptr--;
  }
  if (negative_decimal_flag==1)
  {
    result = (int8_t) (u_result * -1);
    negative_decimal_flag = 0;
  }
  else
  result = (int32_t) u_result;

return result;

}
   
