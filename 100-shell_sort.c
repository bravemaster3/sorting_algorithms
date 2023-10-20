#include "sort.h"

/**
 * shell_sort - sorts an array using shell sort
 * @array: pointer to the array
 * @size: size of the array
 * Return: No return
 */
void shell_sort(int *array, size_t size)
{
	size_t h, h_max, i, j;
	int temp;

	if (size <= 1)
		return;
	h = 1;
	while (h < size)
	{
		h_max = h;
		h = h * 3 + 1;
	}

	for (h = h_max; h > 0; h = (h - 1) / 3)
	{
		for (i = h; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= h && array[j - h] > temp; j -= h)
			{
				array[j] = array[j - h];
			}
			array[j] = temp;
		}
		print_array(array, size);
	}
}
