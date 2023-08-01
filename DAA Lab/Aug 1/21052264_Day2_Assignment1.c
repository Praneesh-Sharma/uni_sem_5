/*Write a function generatePrimes(n) that returns an array of prime
numbers less than or equal to n. If your program contains one or more loops, count and print the
number of times each loop is executed.*/
#include <stdio.h>

void generatePrimes(int n)
{
    int n_outer=0, n_inner=0;
    float c1, c2;
    printf("Prime numbers: ");
    for (int i = 2; i <= n; i++){
    	int flag=1;
    	n_outer++;
        for (int j = 2; j < i; j++){
        	if (i % j == 0)
            		flag=0;
            		n_inner++;
        }
        if (flag==1)
        	printf(" %d", i);
    }
    c1 = n_outer/(float)n;
    c2 = n_inner/(float)n;
    
    printf("\nn_outer: %d", n_outer);
    printf("\nn_inner: %d", n_inner);
    printf("\nc1: %f", c1);
    printf("\nc2: %f\n", c2);
}

int main()
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    generatePrimes(n);
}
