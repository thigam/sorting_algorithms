#include "sort.h"

/**
 * insertion_sort- Sorts a doubly linked list of integers in ascending order using the insertion sort algorithm
 * @list: A pointer to a pointer of the first node in the list
 *
 * Return: nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *navigator = (*list);
	listint_t *iterator;
	listint_t *holder_1;
       	listint_t *holder_2;
	int counter = 0, counter_holder = 0;

	navigator = navigator->next;
	while(navigator)
	{
		iterator = (*list);
		counter = ++counter_holder;
		while(counter > 0)
		{
			holder_1 = navigator->next;
			if (navigator->n < iterator->n)
			{
				if (navigator->prev != NULL)
				{
					navigator->prev->next = navigator->next;
				}
				if (navigator->next != NULL)
				{
					navigator->next->prev = navigator->prev;
				}
				if (iterator->prev == NULL)
				{
					(*list) = navigator;
					navigator->prev = NULL;
				}
				else
				{
					iterator->prev->next = navigator;
					navigator->prev = iterator->prev;
				}
				iterator->prev = navigator;
				navigator->next = iterator;
				print_list(*list);
				navigator = holder_1;
				break;
			}
			counter--;
			if (counter == 0)
			{
				holder_2 = iterator->next;
				iterator->next = navigator;
				navigator->prev = iterator;
				navigator->next = holder_2;
			}
			iterator = iterator->next;
		}
		navigator = holder_1;
	}
}

