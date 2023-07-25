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
