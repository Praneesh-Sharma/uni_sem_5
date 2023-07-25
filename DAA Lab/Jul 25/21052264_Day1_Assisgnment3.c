//Take 2 array as input. Merge the arrays and sort the final array
#include <stdio.h>

int main(){
	int num1, num2;
	printf("Enter sizes of two arrays: ");
	scanf("%d %d", &num1, &num2);
	
	int arr[num1+num2];
	printf("Array 1 input:\n");
	for(int i=0; i<num1; i++){
		printf("Enter element: ");
		scanf("%d", &arr[i]);
	}
	
	printf("Array 2 input:\n");
	for(int i=num1; i<num1+num2; i++){
		printf("Enter element: ");
		scanf("%d", &arr[i]);
	}
	
	for(int i=0; i<num1+num2; ++i){
		for(int j=i+1; j<num1+num2; ++j){
			if(arr[i] > arr[j]){
				int n = arr[i];
				arr[i] = arr[j];
				arr[j] = n;
			}
		}
	}
	
	printf("\nSorted array:");
	for(int i=0; i<=num1+num2-1; i++){
		printf(" %d", arr[i]);
	}
	

	return 0;
}
