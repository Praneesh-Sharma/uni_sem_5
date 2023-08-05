//Write a C program to display the memory address and content of a given value
#include <stdio.h>

void main()
{
    int num;
    printf("Enter number: ");
    scanf("%d", &num);

    printf("Content = %d\n", num);
    printf("Address = %p\n", &num);
}
