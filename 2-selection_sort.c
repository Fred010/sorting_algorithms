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
 * selection_sort - sort an array of integers in ascending order
 *                 using the selection sort algorithm.
 * @array: array of integers.
 * @size: size of the array.
 *
 * Description: outputs the array after each swap.
 */

void selection_sort(int *array, size_t size)
{
	int *base;
	size_t id1, id2;

	if (array == NULL || size < 2)
		return;

	for (id1 = 0; id1 < size - 1; id1++)
	{
		base = array + id1;
		for (id2 = id1 + 1; id2 < size; id2++)
			base = (array[id2]<*base) ? (array + id2) : base;

		if ((array + id1) != base)
		{
			swap_nums(array + id1, base);
			print_array(array, size);
		}
	}
}
