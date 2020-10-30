#ifndef data_h
#define data_h
/*
 * @brief will convert an integer number to a string and store it in an array 
 *
 * Given an integer number an adress in memory and the base you want to store 
 * the number into it will store thhat number into ascii in the given adress 
 *
 * @param data an integer numbet to store into ascii
 * @param ptr a pointer to store the converted data into
 * @param base the base you wish to start data into
 *
 * @return number of digits.
 */
int32_t my_itoa (int32_t data, uint8_t* ptr, uint32_t base);

/*
 * @brief will convert a string of numbers to integer 
 *
 * Given a string number and and number of digits and the base the number
 * is stored in it returns the integer number
 *
 * @param ptr Pointer to string of numbers
 * @param digits number of digits in the string
 * @param base base number of the string
 *
 * @return void.
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);




#endif
