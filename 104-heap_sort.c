#include "sort.h"

/**
 * max_heapify - use "heapify" tecnique to maintain the max-heap
 * property within a binary heap
 * @array: pointer to integer array
 * @size: number of element in the array/tree
 * @root: root node of subtree
 * @size_of_heap: size of heap, decreases as element is sorted
 */

void max_heapify(int *array, size_t size, size_t root, size_t size_of_heap)
{
	/*left child, right child, parent*/
	size_t left, right, largest;
	int temp;


	largest = root;
	/*calculate indices of the child to largest*/
	left = 2 * root + 1;
	right = 2 * root + 2;

	if (left < size_of_heap && array[left] > array[largest])
	{
		largest = left;
	}

	if (right < size_of_heap && array[right] > array[largest])
	{
		largest = right;
	}
	/*if true, it indicates that one of the child*/
	/*element is larger and should be swapped*/
	if (largest != root)
	{
		temp = array[root];
		array[root] = array[largest];
		array[largest] = temp;
		print_array(array, size);
		max_heapify(array, size, largest, size_of_heap);
	}
}

/**
 * heap_sort - sort array of integers using the heap sort algorithms
 * @array: array of integers to sort
 * @size: number of element in the array
 */

void heap_sort(int *array, size_t size)
{
	int i;
	int temp;

	if (array == NULL || size < 2)
		return;
	for (i = size / 2 - 1; i >= 0; i--)
	{
		max_heapify(array, size, i, size);
	}
	for (i = size - 1; i > 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		print_array(array, size);
		max_heapify(array, size, 0, i);
	}
}
