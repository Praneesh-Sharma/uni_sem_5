//Write a C program to convert the Endianness of a Little Endian value to Big Endian and vice-versa
#include <stdio.h>

void main(){
	int value = 0x11223344;
	int converted = 0;
	
	printf("Value Before Converting = 0x%x\n", value);
	converted |= ((0xff &value) << 24);
	converted |= (((0xff << 8) &value) << 8);
	converted |= (((0xff << 16) &value) >> 8);
	converted |= (((0xff << 24) &value) >> 24);
	
	printf("Value After Converting = 0x%x\n", converted);
}
