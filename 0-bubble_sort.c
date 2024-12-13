#include "sort.h"
#include <stdio.h>

/**
 * bubble_sort - Sorts an array of integers in ascending order
 * using the Bubble sort algorithm.
 *
 * @array: Pointer to the array to sort
 * @size: Number of elements in the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, n;
	int temp;
	int j;

	if (array == NULL || size < 2)
		return;

	j = 1;
	for (n = size; n > 1 && j; n--)
	{
		j = 0;
		for (i = 0; i < n - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				j = 1;
				print_array(array, size);
			}
		}
	}
}
