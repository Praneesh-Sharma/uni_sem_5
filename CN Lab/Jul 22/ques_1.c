/*Write a C program to swap the content of 2 variables entered through
the command line using function and pointer.*/
#include <stdio.h>

void swap(int *num1, int *num2){
	int temp;
	
	temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int main(){
	int num1, num2;
	printf("Enter 2 numbers:");
	scanf("%d %d", &num1, &num2);
	printf("Before swapping: %d %d\n", num1, num2);
	
	swap(&num1, &num2);
	printf("After swapping: %d %d\n", num1, num2);
	
	return 0;
}
