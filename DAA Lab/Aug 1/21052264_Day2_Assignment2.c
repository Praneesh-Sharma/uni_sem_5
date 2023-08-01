/*Write a function sine(x, d) that returns the sine of input x accurately
up to d decimal places computed using Taylor’s series approximation of sine.
sin(x) = x - x3/3! + x5/5! - x7/7! + ...
Count and print the number of times the main loop in your program executes.*/
#include <stdio.h>
#include <math.h>

int fac(int x){
	int i,fac=1;
	for(i=1;i<=x;i++)
		fac=fac*i;
	return fac;
}

void sine(float x, int d){
	x = x*(3.1415/180);
	int i,j, flag=0;
	float sum=0,c1;
	for(i=1,j=1;i<=d;i++,j=j+2){
		flag++;	
		if(i%2!=0)
			sum=sum+pow(x,j)/fac(j);
		else
			sum=sum-pow(x,j)/fac(j);
	}
	c1 = log(flag)/(float)d;
	
	printf("Sin: %f\n",sum);
	printf("n_loop: %d\n", flag);
	printf("Estimated parameter: %f\n", c1);

}

void main(){
	float x;
	int d;
	printf("Enter the value of x and d: ");
	scanf("%f %d",&x, &d);
	sine(x, d);
}


