/* 
 * This program will prompt the user to enter in an array of integers. Each index will be squared and printed on the screen using a pointer for
 * the latter operation.
 */

#include <stdio.h>
#include <math.h>

//Since I am writing in vi and the program is trivial I will not include a header file


int main ( void ) 
{

	int size;

	int array[20];

	printf("Size of array (must be less than or equal to 20):\n\n", size);
	scanf("%d", &size);

	printf("\n\nEnter values: \n");
	for( int i = 0; i < size; i++) {
		printf("\nValue at index %d:", i);
		scanf("%d", &array[i]);
	}

	printf("\n\nElements entered: \n");
	for( int i = 0; i < size; i++ ) {
		printf("Index-%d: %d\n", i, *(array+i));	//This points to the beginning of array and adding the i wil get you to the 
	}						        //Correct address

}
 
