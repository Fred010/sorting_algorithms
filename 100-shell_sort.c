#include "sort.h"

/**
 * swap_nums - swap two integers in an array
 * 
 * @x: first integer to swap.
 * @y: second integer to swap.
 */

void swap_nums(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * shell_sort - sorts an array of integers in ascending
 *             order using the shell sort algorithm.
 * @array: array of integers.
 * @size: size of the array.
 *
 * Description: uses the Knuth interval sequence.
 */

void shell_sort(int *array, size_t size)
{
	size_t gap, id1, id2;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap *3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (id1 = gap; id1 < size; id1++)
		{
			id2 = id1;
			while (id2 >= gap && array[id2 - gap] > array[id2])
			{
				swap_nums(array + id2, array + (id2 - gap));
				id2 -= gap;
			}
		}

		print_array(array, size);
	}
}
