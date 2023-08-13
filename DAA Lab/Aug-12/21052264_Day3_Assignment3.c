//Write a function unique(a) that returns an array of unique elements in input array a.
#include <stdio.h>
#include <stdlib.h>
 
void unique(int a[], int n){
	printf("Unique elements:");
    for (int i=0; i<n; i++){
        int j;
        
        for (j=0; j<i; j++)
        	if (a[i] == a[j])
            	break;
            	
        if (i == j)
        	printf(" %d", a[i]);
    }
    printf("\n");
}
 
int main(){
	int n;
    printf("Enter size of array: ");
	scanf("%d", &n);
	int a[n];
	for(int i = 0; i < n; i++)  
    	a[i] = rand(); 
    unique(a, n);
    return 0;
}
