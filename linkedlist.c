/*
 File:          linkedlist.c
 Purpose:       Implements the linked list functions whose prototypes
                are declared in the linkedlist.h header file
 Author:			  Your names
 Student #s:		12345678 and 12345678
 CS Accounts:		a1a1 and b2b2
 Date:				  Add the date here
 */
 
/* Preprocessor directives */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

/******************************************************************
 PLEASE EDIT THIS FILE

 Comments that start with // should be replaced with code
 Comments that are surrounded by * are hints
 ******************************************************************/

/*
 Main function drives the program.  Every C program must have one
 main function.  A project will not compile without one.

 In our program, the main function does nothing.  That's because
 our program doesn't do anything.  We're just implementing a linked
 list and testing it using our unit tests.

 PRE:    NULL (no pre-conditions)
 POST:	 NULL (no side-effects)
 RETURN: IF the program exits correctly
		 THEN 0 ELSE 1
 */
int main ( void )
{
	struct airplane test_airplane_one = { 100, "Vancouver", "Toronto", 1, 900, 36000, 350 };
	struct airplane test_airplane_two = { 200, "Toronto", "Halifax", 2, 800, 26000, 280 };
	struct node * test_list = create_linked_list();
	test_list = prepend_node(test_list, create_node(test_airplane_one));
	test_list = prepend_node(test_list, create_node(test_airplane_two));
	test_list = remove_from_list(test_list, "Halifax");
	int length = get_length(test_list);
	/* The system command forces the system to pause */
	system("pause");
	return 0;
}

/*
 Returns a pointer to a new, empty linked list of struct node.
 PRE:       NULL (no pre-conditions)
 POST:      NULL (no side-effects)
 RETURN:    A pointer to a new, empty linked list of struct node (NULL)
 */
struct node * create_linked_list()
{
	return NULL;
}

/*
 Returns a dynamically allocated struct node that contains the specified
 struct airplane.  The node's next pointer doesn't point to anything
 e.g., it is equal to NULL.
 PARAM:     plane, a struct airplane
 PRE:       NULL (no pre-conditions)
 POST:      NULL (no side-effects)
 RETURN:    A pointer to a dynamically allocated struct node a) that contains
            the specified struct airplane, and b) whose next pointer points to NULL
 */
struct node * create_node(struct airplane plane)
{
	struct node* start = (struct node*) malloc(sizeof(struct node));
	start->plane = plane; 
	start->next = NULL;
	return start;
}

/*
 Prepends (push) a struct node passed as a parameter to the list passed as a
 parameter, and returns a pointer to the result.
 PARAM:     list is a pointer to a (possibly empty) linked list of struct node
 PARAM:     new_node is a pointer to a struct node
 PRE:       new_node is not null
 POST:      The specified struct node is added to the beginning of the list
            and its next pointer points to the node that used to be first
 RETURN:    A pointer to a linked list which contains all of the nodes
            of the list passed as a parameter, plus a prepended node
 ***LIST is start****
 */
struct node * prepend_node(struct node * list, struct node * new_node)
{	
		new_node->next = list;
		list = new_node;
		return list;
}

/*
 Deletes the first struct node in the specified list, and returns a pointer to
 the shortened list.
 PARAM:     list is a pointer to a (possibly empty) linked list of struct node
 PRE:       NULL
 POST:      The list passed as a parameter has one fewer node, and the dynamically
            allocated memory which contained that removed node has been freed
 RETURN:    IF the list is empty
            THEN NULL
            ELSE a pointer to the shortened list
 */
struct node * delete_node(struct node * list)
{
	struct node* garbage = list; 
	if (list) { 
		list = list->next;
		free(garbage); 
	}							// If list is empty no need to free
	return list;
}

/*
 Returns the number of nodes in the specified linked list of struct node.
 PARAM:     list is a pointer to a (possibly empty) linked list of struct node
 PRE:       NULL (no pre-conditions)
 POST:      NULL (no side-effects)
 RETURN:    The length of the specified list, an int
 */
int get_length(struct node * list)
{
	struct node* pos = list;		// Keep track of position
	int count = 0;
	
	while (pos != NULL )		// While the next pointer is not null
	{
		count++;
		pos = pos->next;
	}
	
	return count;
}

/*
 Deletes an entire list.  This function iterates along a list and deallocates the
 memory containing each struct node.  
 PARAM:     list is a pointer to a (possibly empty) linked list of struct node
 PRE:       NULL (no pre-conditions)
 POST:      The memory containing all of the nodes in the list has been freed
 RETURN:    an empty list (NULL)
 */
struct node * delete_list(struct node * list)
{
	int i;
	int length = get_length(list);
	struct node* pos = list;
	
	if (length == 1)
	{
		delete_node(pos);
		return NULL;
	}
	else if (list != NULL )					// if the list is not empty
	{
		for (i = 1; i < length; i++)
		{
			pos = delete_node(pos); 
			pos = pos->next;
		}

		pos = delete_node(pos);			// Do the last node separately so as to avoid derefrencing NULL pointer

		return pos;
	}
	else
	{
		return list;			// list is already empty 
	}
}

/*
 Prints the data stored in a node.  For the struct airplane in the node,
 prints the fields on separate lines.  For each field, prints the field name
 and the field value.  For the pointer, prints "Link = NULL\n" if the pointer points
 to null, else prints "Link points to address xxx\n", where xxx is the pointer address
 in hexademical.
 If node_to_print is NULL, prints "The node is empty\n".
 PARAM:     node_to_print is a pointer to a (possibly null) struct node
 PRE:       NULL (no pre-conditions)
 POST:      Information about node_to_print has been printed to standard output
 RETURN:    NULL
 */
void print_node(struct node * node_to_print)
{
	struct airplane flight_info = node_to_print->plane;
	printf_s("**************FLIGHT INFO*******************");
	printf_s("Flight Number: %d\n", flight_info.flight_number);
	printf_s("City Origin: %s\n", flight_info.city_origin);
	printf_s("City Destination: %s\n", flight_info.city_destination);
	printf_s("Priority: %d\n", flight_info.priority);
	printf_s("Maximum Speed (kph): %d", flight_info.maximum_speed_kph);
	printf_s("Cruiing Altitude: %d", flight_info.cruising_altitude);
	printf_s("Capacity: %d", flight_info.capacity);
	printf_s("Link points to address: %x", node_to_print->next);
}

/*
 Prints the data stored in all nodes in the specified list to print.
 For each node, prints the data inside the node the same way that it
 is printed by print_node.  If the list is empty, a suitable message
 is printed to standard output.
 PARAM:     node_to_print is a pointer to a (possibly empty) linked list of
            struct node
 PRE:       NULL (no pre-conditions)
 POST:      Information about list_to_print has been printed to standard output
 RETURN:    NULL
 */
void print_list(struct node * list_to_print)
{
	int length = get_length(list_to_print);
	int i;
	struct node* pos = list_to_print;
	 
	if (list_to_print)		// If list is not empty proceed:
	{
		for (i = 1; i < length; i++)
		{
			print_node(pos);
			pos = pos->next;
		}
		
		print_node(pos);	// To avoid derefrencing a NULL pointer print this one separately without incrementing pos
	}
	else					// If the list is empty: print appropriate message:
	{
		printf_s("\nThe list is currently empty\n");
	}
}

/*
 Reverses a list. 
 PARAM:     list is a pointer to a (possibly empty) linked list of struct node
 PRE:       NULL (no pre-conditions)
 POST:      The order of the nodes in the list passed as a parameter has been
            reversed
 RETURN:    a list of struct node that is the reverse of the list passed as a
            parameter
 */
 
// For this function we will assume that length will always return an int >= 0
struct node * reverse(struct node * list)
{
	struct node* back, *mid, *front;
	int length = get_length(list);

	if (length == 0 || length == 1)
	{
		return list;				// No need to reverse an empty list or list of one node
	}
	else if (length == 2)
	{
		back = list;
		mid = list->next;			// Set up 
		mid->next = back;

		back->next = NULL;			// Move links around
		return mid;
	}
	else if (length == 3)
	{
		back = list;
		mid = list->next;
		front = mid->next;			// Initial set up

		back->next = NULL;			// Ground the first node
		mid->next = back;			// Second node points to the first
		front->next = mid;			// Third node points to second
		
		return front;
	}
	else							// Generic Case
	{
		back = list;
		mid = list->next;
		front = mid->next;			// Same Initial set up

		back->next = NULL;			// Ground the first node
		mid->next = back;			// Second node points to the first

		back = mid;
		mid = front;
		front = front->next;		// Shift pointers along

		// So far we have taken care of the special first case, where we need to ground first node
		// Now we can proceed flipping the pointers around
		while (front->next != NULL)
		{
			mid->next = back;		// Adjust links

			back = mid;
			mid = front;
			front = front->next;	// Shift pointers
		}

		// When we reach the end:
			mid->next = back;
			front->next = mid;
			return front;
	}
}

/*
 Removes every node from the list which contains an airplane destined for
 the city name passed in the second parameter.
 PARAM:     list is a pointer to a (possibly empty) linked list of struct node
 PARAM:     destination_city is a pointer to a null-terminated array of char
 PRE:       NULL (no pre-conditions)
 POST:      Any struct node in the list which contains an airplane struct
            destined for the destination_city is removed from the list, and
            the memory deallocated
 RETURN:    a list of struct node that does not contain any struct node that
            has an airplane destined for the destination_city
 */
struct node * remove_from_list(struct node * list, char * destination_city)
{
	int length = get_length(list);
	int i;
	struct node* pos = list;
	struct node* prev = list;
	struct node* hold;
	struct node *start = list;
	struct airplane temp;
	

	if (length == 0)
	{
		return list;				// Empty list requires no modification
	}
	else if (length == 1)
	{
		temp = pos->plane;

		if (strcmp(temp.city_destination, destination_city) == 0)
			return delete_list(pos);						// return a NULL pointer
		else return list;
	}
	else
	{
		temp = pos->plane;

		// Apply a linear search, to avoid derefrencing a null pointer, do not check last node
		for(i=1; i<length; i++)
		{
			if (i == 1 && (strcmp(temp.city_destination, destination_city) == 0))
			{
				start = pos->next;
			}
			else if (i > 0 && strcmp(temp.city_destination, destination_city) == 0)
			{
				hold = pos->next;
				prev->next = delete_node(pos);
				pos = hold;
				temp = pos->plane;
			}
			else
			{
				prev = pos;
				pos = pos->next;
				temp = pos->plane;
			}
		}
		
		// After iterating through that loop pos is at the last node:
		if (strcmp(temp.city_destination, destination_city) == 0)
		{
			prev->next = NULL;
			delete_node(pos);
		}

		return start;
	}
}

/*
 Returns a reference to the nth node (but does not remove it ) in the
 specified list.  If the list is too short, returns NULL.
 PARAM:     list is a pointer to a (possibly empty) linked list of struct node
 PARAM:     ordinality is an integer
 PRE:       ordinality > 0
 POST:      NULL (no side-effects)
 RETURN:    IF ordinality <= length of list
            THEN a pointer to the nth node
            ELSE NULL
 */
struct node * retrieve_nth(struct node * list, int ordinality)
{
	int length = get_length(list);
	int i;
	struct node* pos = list;
	struct node* prev = list;

	if (ordinality > length)
	{
		return NULL;
	}
	else
	{
		for (i=0; i < ordinality; i++)
		{
			prev = pos;
			pos = pos->next;
		}
		return prev;
	}
}

/*
 Inserts the specified node into the specified list of nodes at the specified
 ordinality.  For example, if ordinality = 1, this is a simple prepend_node
 operation.  If ordinality = 3, then when this function is finished, the third
 node in the list will be the node_to_insert.  If the ordinality = the length
 of the list + 1, then the node_to_insert is appended to the end of the list.
 If the ordinality > 1 + length of the list, the function returns a pointer
 to the unchanged list.
 PARAM:     list is a pointer to a (possibly empty) linked list of struct node
 PARAM:     ordinality is an integer
 PRE:       ordinality > 0
 PRE:       node_to_insert is NEVER a null (it is always a correct node pointer)
 POST:      NULL (no side-effects)
 RETURN:    IF ordinality <= length of list + 1
            THEN a pointer to the list which contains the node_to_insert in the
			correct location
            ELSE a pointer to the unchanged list
 */
struct node * insert_nth(struct node * list, struct node * node_to_insert, int ordinality)
{
	int length = get_length(list);
	struct node* pos, *prev;

	if (ordinality == 1)
		return prepend_node(list, node_to_insert);

	else if (length + 1 == ordinality)
	{
		return append_node(list, node_to_insert);
	}

	else if (ordinality > length + 1)
	{
		return list;
	}

	else
	{
		pos = retrieve_nth(list, ordinality);
		prev = retrieve_nth(list, ordinality - 1);
		node_to_insert->next = pos;
		prev->next = node_to_insert;
		return list;
	}
}

/*
Appends the node to insert at the end of list.
PARAM:     list is a pointer to a non-empty linked list of struct node
PARAM:     node_to_insert is a node to append
PRE:       list is not NULL and has more than 1 node
PRE:       node_to_insert is NEVER a null (it is always a correct node pointer)
POST:      List now contains node_to_insert as last node
RETURN:    Pointer to start of list, so just list
*/
struct node* append_node(struct node* list, struct node* node_to_insert)
{
	struct node* pos = list;
	struct node* prev = list;

	while (pos)
	{
		prev = pos;
		pos = pos->next;
	}
	
	prev->next = node_to_insert;
	node_to_insert->next = NULL;

	return list;
}