/*Write a C program to extract each byte from a given number and store
them in separate character variables and print the content of those
variables*/
#include<stdio.h>
int main()
{
int a;
printf("Enter the number: ");
scanf("%d",&a);
char *ptr = (char*)&a;
char b1 = *ptr;
char b2 = *(ptr+1);
char b3 = *(ptr+2);
char b4 = *(ptr+3);
printf("Digit in Byte 1 - %d\n", b1);
printf("Digit in Byte 2 - %d\n", b2);
printf("Digit in Byte 3 - %d\n", b3);
printf("Digit in Byte 4 - %d\n", b4);
return 0;
}
