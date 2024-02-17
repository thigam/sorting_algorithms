#include "sort.h"

/**
 * cocktail_sort_list- Sorts a doubly linked list of integers in ascending order using the Cocktail shaker sort algorithm
 * @list: The list to be sorted
 *
 * Return: nothing
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *current, *next;
	int direction = 1, len_counter = 0, len = 0, counter = 0;

	current = next = *list;
	while(next)
	{
		current = next;
		len_counter++;
		if (direction == 1 && current->next == NULL)
		{
			direction = -1;
			if (len == 0)
			{
				len = len_counter;
				counter = 0;
			}
			if (len != 0 && counter > len)
			{
				break;
			}
		}
		if (direction == -1 && current->prev == NULL)
		{
			direction = 1;
		}

		if (direction == 1)
		{
			if (current->n > current->next->n)
			{
				next = current->next;
				if (current->prev == NULL)
				{
					*list = current->next;
				}
				else
				{
					current->prev->next = next;
				}
				if (next->next != NULL)
				{
					next->next->prev = current;
				}
				current->next = current->next->next;
				next->prev = current->prev;
				current->prev = next;
				next->next = current;
				counter = 0;
				print_list(*list);
				continue;
			}
			next = current->next;
		}
		if (direction == -1)
		{
			if(current->n < current->prev->n)
			{
				next = current->prev;
				if (current->prev->prev == NULL)
				{
					*list = current;
				}
				else
				{
					next->prev->next = current;
				}
				if (current->next != NULL)
				{
					current->next->prev = next;
				}
				current->prev = current->prev->prev;
				next->next = current->next;
				current->next = next;
				next->prev = current;
				counter = 0;
				print_list(*list);
				continue;
			}
			next = current->prev;
		}
		counter++;
	}
}
