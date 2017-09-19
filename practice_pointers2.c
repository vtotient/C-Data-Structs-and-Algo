/*Practice exercises for the CPSC 259 textbook. Print a message and area of triangle using pointers. 
 *Victor Sira
 */

#include <stdio.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS

#define BUFFER 50
void print_message();
void compute_tri_area();

int main()
{
	print_message();

	compute_tri_area();

	system("pause");
	return;
}

void print_message() {

	char* char_pointer;
	char buffer_string[BUFFER];
	int size_of_str = 0;

	printf("Enter a message (50 character maximum): ");
	fgets(buffer_string, BUFFER, stdin);
	//sscanf_s(buffer_string, "%c", buffer_string);

	for(int i = 0; buffer_string[i] != '\0'; i++) {
		size_of_str++;
	}
					
	char_pointer = (char*)malloc(size_of_str * sizeof(char));		/*Just practicing allocating mem. in the heap. 
																	This array size is user defined and allocated at run-time*/
	for (int i = 0; buffer_string[i] != '\0'; i++) {
		char_pointer[i] = buffer_string[i];
	}

	printf("\n\nYou entered: %c", *char_pointer);

	return;
}

void compute_tri_area() {

	double* p_base, *p_height;
	double base, height, area;

	printf("Enter base:");
	scanf("%lf", &base);
	printf("\nEnter height:");
	scanf("%lf", &height);

	*p_base = base;
	*p_height = height;

	area = base*height*0.5;

	printf("\nThe area is: %lf\n", area);
	return;
}
