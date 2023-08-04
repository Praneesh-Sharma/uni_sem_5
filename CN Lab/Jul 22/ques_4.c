/*.Write a C Program to enter a number and store the number across the
following
structure and print the content of each member of the structure. Then
aggregate each
member of the structure to form the original number and print the same.
struct pkt{
char ch1;
char ch2[2];
char ch3;
};*/

#include <stdio.h>
struct pkt{
unsigned char ch1;
unsigned char ch2[2];
unsigned char ch3;
};
int main(){
int num;
printf("Enter the number:\n");
scanf("%d",&num);
int a,b,c,d;
a= (num & 255);
b=((num >>8)&255);
c=((num >>16)&255);
d=((num >>24)&255);
struct pkt obj;
obj.ch1=a;
obj.ch2[0]=b;
obj.ch2[1]=c;
obj.ch3=d;
printf("Byte 1: %0.2x\n",obj.ch1);
printf("Byte 2: %0.2x\n",obj.ch2[0]);
printf("Byte 3: %0.2x\n",obj.ch2[1]);
printf("Byte 4: %0.2x\n",obj.ch3);
printf("Original number:\n");
int v =((int)(obj.ch3<<24)+(int)(obj.ch2[1]<<16)+(int)(obj.ch2[0]<<8)+(int)(obj.ch1));
printf("%d\n",v);
return 0;
}
