#include "sort.h"

/**
 * bubble_sort - sort an array using bubble sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp, control;

	if (size <= 1)
		return;
	for (i = 0; i < size - 1; i++)
	{
		control = 0;
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
				control = 1;
			}
		}
		if (control == 0)
			break;
	}
}
