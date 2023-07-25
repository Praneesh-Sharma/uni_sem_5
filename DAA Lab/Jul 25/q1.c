#include <stdio.h>
#include <stdlib.h>

int main(){
	int num;
	printf("Enter size of array: ");
	scanf("%d",&num);
	int arr[num];
	
	printf("Array generated: ");
	for(int i=0; i<=num-1; i++){
		arr[i]=rand();
		printf("%d ", arr[i]);
	}
	
	for(int i=0; i<=num; ++i){
		for(int j=i+1; j<=num; ++j){
			if(arr[i] > arr[j]){
				int n = arr[i];
				arr[i] = arr[j];
				arr[j] = n;
			}
		}
	}
	
	printf("\nSecond largest element: %d", arr[num-2]);
	printf("\nSecond smallest element: %d\n", arr[1]);
	return 0;
}
