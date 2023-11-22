#include "sort.h"

/**
 * swap_nums - swap two integers in an array.
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
 * bubble_sort - sorts an array of integers in ascending order.
 * @array: array of integers to sort.
 * @size: size of the array.
 *
 * Description: Prints the array after each swap.
 */

void bubble_sort(int *array, size_t size)
{
	size_t id, length = size;
	bool bub_sort = false;

	if (array == NULL || size < 2)
		return;

	while (bub_sort == false)
	{
		bub_sort = true;
		for (id = 0; id < length - 1; id++)
		{
			if (array[id] > array[id + 1])
			{
				swap_nums(array + id, array + id + 1);
				print_array(array, size);
				bub_sort = false;
			}
		}

		length--;
	}
}
