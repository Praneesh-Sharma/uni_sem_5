/*Write a function recursiveMin(a, n) that recursively computes the
minimum value in the input array a and returns it. Initially, n = |a|.
recursiveMin(a, n) : a[0] if n==1
[base case]
min(a[n-1], recursiveMin(a, n-1))
[recursive definition]*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int min(int num1, int num2){
    return (num1 > num2) ? num2 : num1;
}

int recursiveMin(int a[], int n){
	if(n == 1)  
        return a[0];
    else
    	return min(a[n-1], recursiveMin(a, n-1));
}  
      
int main(){
	int n;
	time_t t; 
	srand((unsigned)time(&t));
	printf("Enter size of array: ");
	scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i++)  
    	a[i] = rand(); 
    
    printf("Smallest element: %d\n", recursiveMin(a, n));
      
    return 0;  
}
