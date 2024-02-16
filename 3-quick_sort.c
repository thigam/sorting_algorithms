#include "sort.h"

/**
 * quick_sort- Sorts an array of integers in ascending order using the Quick sort algorithm
 * @array: The array to be sorted
 * @size: The length of the array
 *
 * Return: nothing
 */

void quick_sort(int *array, size_t size)
{
	int holder = 0;
	size_t counter_1 = 0, pivot_pos = 0;

	for (counter_1 = 0; counter_1 < size - 1; counter_1++)
	{
		if (array[counter_1] < array[size - 1])
		{
			holder = array[counter_1];
			array[counter_1] = array[pivot_pos];
			array[pivot_pos] = holder;
			pivot_pos++;
			print_array(array, size);
		}
	}
	if (array[pivot_pos] > array[size-1])
	{
		holder = array[size - 1];
		array[size - 1] = array[pivot_pos];
		array[pivot_pos] = holder;
		print_array(array, size);
	}

	if (pivot_pos > 0)
	{
		quick_sort(array, pivot_pos);
	}
	if (pivot_pos < size - 1)
	{
		quick_sort(array + pivot_pos + 1, size - pivot_pos - 1);
	}
}
