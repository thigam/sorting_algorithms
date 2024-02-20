#include "sort.h"

/**
 * insertion_sort- Sorts a doubly linked list of integers in ascending order using the insertion sort algorithm
 * @list: A pointer to a pointer of the first node in the list
 *
 * Return: nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *end_of_sorted = *list;
	listint_t *unsorted = (*list)->next, *holder_unsorted_prev,
		  *holder_unsorted_next, *holder_end_of_sorted_prev, *holder_end_of_sorted;
	int len_sorted = 0, len_sorted_holder = 0, ticker = 0;

	if (*list == NULL || (*list)->next == NULL)
	{
		return;
	}

	while (unsorted)
	{
		ticker = 0;
		len_sorted = ++len_sorted_holder;
		holder_end_of_sorted = end_of_sorted;
		holder_unsorted_next = unsorted->next;
		while (len_sorted > 0)
		{
			holder_unsorted_prev = unsorted->prev;
			holder_end_of_sorted_prev = end_of_sorted->prev;
			if (unsorted->n < end_of_sorted->n)
			{
				if (end_of_sorted->prev == NULL)
				{
					*list = unsorted;
					unsorted->prev = NULL;
				}
				else
				{
					end_of_sorted->prev->next = unsorted;
					unsorted->prev = end_of_sorted->prev;
				}
				if (unsorted->next == NULL)
				{
					holder_unsorted_prev->next = NULL;
				}
				else
				{
					holder_unsorted_prev->next = unsorted->next;
					unsorted->next->prev = holder_unsorted_prev;
				}
				unsorted->next = end_of_sorted;
				end_of_sorted->prev = unsorted;
				print_list(*list);
				len_sorted--;
				end_of_sorted = holder_end_of_sorted_prev;
				if (len_sorted == 0)
				{
					end_of_sorted = holder_end_of_sorted;
				}
				ticker = 1;
				continue;
			}
			len_sorted--;
			
			if (len_sorted == 0 && ticker != 1)
			{
				end_of_sorted = unsorted;
			}
			else if (len_sorted != 0)
			{
				end_of_sorted = holder_end_of_sorted_prev;
			}
			else if (len_sorted == 0 && ticker == 1)
			{
				end_of_sorted = holder_end_of_sorted;
			}
		}
		unsorted = holder_unsorted_next;
	}
}
