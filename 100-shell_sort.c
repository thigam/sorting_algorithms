#include "sort.h"

/**
 * shell_sort- Sorts an array of integers in ascending order using the Shell sort algorithm, using the knuth sequence
 * @array: The Array to be sorted
 * @size: The size/ length of the array
 *
 * Return: nothing
 */

void shell_sort(int *array, size_t size)
{
	int holder = 0;
	size_t gap = 1, i = 0, gap_holder = 1, pos_holder = 0;

	while(gap < size)
	{
		gap = (3 * gap) + 1;
	}

	gap = (gap - 1) / 3;
	gap_holder = gap;

	while(gap > 0)
	{
		for (i = 0; i < size; i++)
		{
			pos_holder = i;
			if (i + gap >= size)
			{
				break;
			}
			while(i + gap < size)
			{
				if (array[i] > array[i + gap] && array[i + gap] < array[pos_holder])
				{
					pos_holder = i + gap;
				}
				gap = gap + gap_holder;
			}
			gap = gap_holder;
			if (pos_holder != i)
			{
				holder = array[i];
				array[i] = array[pos_holder];
				array[pos_holder] = holder;
			}
		}
		gap = gap_holder = (gap - 1) / 3;
		print_array(array, size);
	}
}
