/*Write a function gcd(k) which returns the GCD of kth and (k+1)th
Fibonacci numbers for k>1. Use Euclid’s algorithm to calculate the GCD.*/
#include<stdio.h>    

void gcd(int k){
	int n1=0,n2=1,n3,i,flag1,flag2,n_loop=0;

	for(i=2;i<=k;++i){   
  		n3=n1+n2;
  		if(i==k-1)
  			flag1=n3;
  		else if(i==k)
  			flag2=n3;
  		n1=n2;    
  		n2=n3;    
 	}
 	
 	printf("Fibonacci elements: %d %d\n", flag1, flag2);
 	
 	while (flag1 > 0){
 		n_loop++;
        	int rem = flag2%flag1;
        	flag2 = flag1;
        	flag1 = rem;
    	}
    	
    	float c1 = n_loop/(float)k;
    	
    	printf ("GCD = %d \n",flag2);
    	printf ("n_loop = %d \n",n_loop);
    	printf ("Estimated Parameter = %f \n",c1);
}

void main(){
    
	int num;    
 	printf("Enter the number of elements: ");    
 	scanf("%d",&num);
	gcd(num);
}    
