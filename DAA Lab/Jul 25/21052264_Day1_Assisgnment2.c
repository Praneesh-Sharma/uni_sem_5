/*Write a program to display an array of n integers (n>1), where every
index of the array should contain the product of all elements in the input array except the element
at the given index. Solve this problem by taking a single loop and without an additional array.*/
#include <stdio.h>

int main(){
	int num;
	printf("Enter number of elements: ");
	scanf("%d", &num);
	
	int arr[num], temp=1;
	for(int i=0; i<=num-1; i++){
		printf("Enter element: ");
		scanf("%d", &arr[i]);
		temp = temp * arr[i];
	}
	
	printf("\nOutput:");
	for(int i=0; i<=num-1; i++){
		arr[i] = temp/arr[i];
		printf(" %d", arr[i]);
	}
	printf("\n");	
	return 0;
}
