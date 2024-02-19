#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 * @array: The array to be sorted
 * @size: The lenght of the array
 *
 * Return: nothing
 */

void bubble_sort(int *array, size_t size)
{
	int j = 0, holder = 0, temp_len = 0;
	size_t i = 0;

	temp_len = size;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < temp_len - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				holder = array[j];
				array[j] = array[j + 1];
				array[j + 1] = holder;
				print_array(array, size);
			}
		}
		temp_len--;
	}
}
