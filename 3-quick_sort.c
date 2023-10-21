#include "sort.h"

/**
 * partition - parts the array into subarray
 * @array: array to part
 * @lb: lower bound of the array(first element)
 * @hb: higher bound of the array
 * @size: size of the array
 * Return: the part position
 */
size_t partition(int *array, size_t lb, size_t hb, size_t size)
{
	size_t i, j;
	int temp, pivot;

	i = lb;
	pivot = array[hb];

	for (j = lb; j < hb; j++)
	{
		if (array[j] <= pivot)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i++;
		}
	}
	temp = array[i];
	array[i] = array[hb];
	array[hb] = temp;
	print_array(array, size);
	return (i);
}

/**
 * sort - sorts the array
 * @array: array to part
 * @lb: lower bound of the array(first element)
 * @hb: higher bound of the array
 * @size: size of the array
 */

void sort(int *array, size_t lb, size_t hb, size_t size)
{
	size_t part_location;

	if (lb < hb)
	{
		part_location = partition(array, lb, hb, size);
		if (part_location != 0)
		{
			sort(array, lb, part_location - 1, size);
		}
		sort(array, part_location + 1, hb, size);
	}
}

/**
 * quick_sort - sorts array using quick sort(lomuto)
 * @array: array to sort
 * @size: size of the array
 */

void quick_sort(int *array, size_t size)
{

	sort(array, 0, size - 1, size);
}
