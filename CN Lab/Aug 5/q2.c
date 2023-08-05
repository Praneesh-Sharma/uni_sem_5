//Write a C program to find the Endianness of a given user value
#include <stdio.h>

int main(){
	unsigned int value = 0x11223344;
	char *r = (char *)&value;
	printf("*r is ox%x\n", *r);
	if(*r==0x10)
		printf("Number is in Little Endian\n");
	else
		printf("Number is in Big Endian\n");
		
	return 0;
}
