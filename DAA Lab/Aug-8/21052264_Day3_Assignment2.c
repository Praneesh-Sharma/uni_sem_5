/*Guess game
A and B are playing a guessing game where B first thinks up an integer X (positive, negative or
zero, and could be of arbitrarily large magnitude) and A tries to guess it. In response to A’s guess,
B gives exactly one of the following three replies:
a) Try a bigger number
b) Try a smaller number or
c) You got it.
Write a program by designing an efficient algorithm to minimize the number of guesses A has to
make.*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	int num, upper=100, lower=0, guess, guess_num=1;
	printf("Enter lower and upper bound of range: ");
	scanf("%d %d", &lower, &upper);
	num = (rand()%(upper-lower+1)) + lower;
	
	do{
		printf("\nGuess the number:");
		scanf("%d", &guess);
		if(guess>num)
			printf("Try a smaller number\n");
		else if(guess<num)
			printf("Try a bigger number\n");
		else{
			printf("You got it");
		}
		guess_num++;
	} while(guess!=num);
	printf("\nNumber of guesses: %d\n", guess_num);
	
	return 0;
}

