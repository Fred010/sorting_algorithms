#include "sort.h"

void swap_ints(int *x, int *y);
void heap_max(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

/**
 * swap_ints - Swap two integers in an array.
 * @x: The first integer to swap.
 * @y: The second integer to swap.
 */

void swap_ints(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * heap_max - Turn x binary tree into x complete binary heap.
 * @array: An array of integers representing x binary tree.
 * @size: The size of the array/tree.
 * @base: The index of the base row of the tree.
 * @root: The root node of the binary tree.
 */

void heap_max(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, large;

	left = 2 *root + 1;
	right = 2 *root + 2;
	large = root;

	if (left < base && array[left] > array[large])
		large = left;
	if (right < base && array[right] > array[large])
		large = right;

	if (large != root)
	{
		swap_ints(array + root, array + large);
		print_array(array, size);
		heap_max(array, size, base, large);
	}
}

/**
 * heap_sort - Sort an array of integers in ascending
 *            order using the heap sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the sift-down heap sort
 * algorithm. Prints the array after each swap.
 */

void heap_sort(int *array, size_t size)
{
	int id;

	if (array == NULL || size < 2)
		return;

	for (id = (size / 2) - 1; id >= 0; id--)
		heap_max(array, size, size, id);

	for (id = size - 1; id > 0; id--)
	{
		swap_ints(array, array + id);
		print_array(array, size);
		heap_max(array, size, id, 0);
	}
}
