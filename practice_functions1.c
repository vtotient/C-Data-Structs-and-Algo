/*
Write a function that raises an integer to a positive integer power.
Call the func- tion x_to_the_n taking two integer arguments x and n.
Have the function return a long int, which represents the results of calculating x^n.

Algoritm: x^n is x times itself n times.
1.) 
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long x_to_the_n( int x, int n );

int main (void)
{

	int x, n;

	printf("Enter an integer base and an exponent:");
	scanf("%d %d", &x, &n);

	printf("%ld\n\n", x_to_the_n( x, n));
}

long x_to_the_n( int x, int n)
{

	if ( n == 0 )
		 return 1;

	int result = 1;

	for ( int i = 0; i < n; i++ )
		 result *= x;

	return result;
}	
