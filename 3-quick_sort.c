#include "sort.h"

/**
 * swap_elements - Swap two elements in an array.
 * @x: first element
 * @y: second element. 
 */
void swap_elements(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 * partition_array - divide an array into subset using lomuto partition
 * @array: The array to partition.
 * @size: The size of the array.
 * @lb: lower bound of array(first element).
 * @hb: higher bound of array.
 * Return: partition index.
 */
int partition_array(int *array, size_t size, int lb, int hb)
{
	int *pivot, i, j, temp;

	/*pivot points to element at higher bound*/
	pivot = array + hb;
	i = lb;
	/*iterate thru array from lb to hb -1*/
	for (j = lb; j < hb; j++)
	{
		/*check is curr element is less than pivot element*/
		if (array[j] < *pivot)
		{
			/*for optimization sake*/
			if (i < j)
			{
				/*swap curr element with element at i*/
				temp = array[j];
				array[j] = array[i];
				array[i] = temp;
				print_array(array, size);
			}
			i++;
		}
	}

	if (array[i] > *pivot)
	{
		temp = array[j];
		array[j] = array[i];
		array[i] = temp;
		print_array(array, size);
	}

	return (i);
}

/**
 * sort - sort array using quicksort algorithm.
 * @array: Array to sort
 * @size: size of the array.
 * @lb: Start index of partioned array.
 * @hb: end index of partitioned array.
 */
void sort(int *array, size_t size, int lb, int hb)
{
	int partition;

	/*checks if there is more than one element in the subarray*/
	if (hb > lb)
	{
		partition = partition_array(array, size, lb, hb);
		sort(array, size, lb, partition - 1);
		sort(array, size, partition + 1, hb);
	}
}

/**
 * quick_sort - Sort an array using quicksort algorithm in assending order
 * @array: Array to sort
 * @size: Size of array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	sort(array, size, 0, size - 1);
}
