#include "sort.h"

/**
 * selection_sort- Sorts an array of integers in ascending order using the selection sort algorithm
 * @array: The array to be sorted
 * @size: The length of the array
 *
 * Return: nothing
 */

void selection_sort(int *array, size_t size)
{
	int holder_1 = 0, holder_2 = 0;
	size_t counter_1 = 0, counter_2 = 0, counter_3 = 0, counter_2_holder = 0;

	for (counter_1 = 0; counter_1 < size - 1; counter_1++)
	{
		counter_2 = ++counter_2_holder;
		holder_1 = counter_2;
		while(counter_2 < size)
		{
			if (array[counter_2] < array[counter_3] && array[counter_2] < array[holder_1])
			{
				holder_1 = counter_2;
			}
			counter_2++;
		}

		if (array[holder_1] < array[counter_3])
		{
			holder_2 = array[counter_3];
			array[counter_3] = array[holder_1];
			array[holder_1] = holder_2;
			print_array(array, size);
		}
		counter_3++;
	}
}
