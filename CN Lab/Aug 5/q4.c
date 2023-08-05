//Write a C program to check whether the host machine is Little Endian of Big Endian. Enter a number, print the content of each byte location and convert the Endianness of the same.
#include <stdio.h>
#include <stdlib.h>

void main(){
	unsigned int value = 0x1;
	char *r = (char *)&value;
	
	if(*r == 1)
		printf("Your system is Little Endian\n");
	else
		printf("Your system is Big Endian\n");
		
	int num;
	printf("Enter a number: ");
	scanf("%d", &num);
	char *ptr = (char *)&num;
	for (int i = 0; i < sizeof(num); i++){
		printf("Byte %d: %d\n", i + 1, ptr[i]);
	}
	
	int convertedNum = 0;
	for (int i = 0; i < sizeof(num); i++){
		convertedNum = (convertedNum << 8) | ptr[i];
	}

	printf("Converted Number is: %u\n", convertedNum);
	printf("After Conversion Number in each Byte\n");
	num = convertedNum;
	for (int i = 0; i < sizeof(num); i++){
		printf("Byte %d: %d\n", i + 1, ptr[i]);
	}	
}
