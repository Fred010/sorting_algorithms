#include "sort.h"

void swap_nums(int *x, int *y);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_nums - Swap two integers in an array
 * 
 * @x: The first integer to swap.
 * @y: The second integer to swap.
 */

void swap_nums(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * lomuto_partition - aligns x subset of an array of integers according to
 *                   the lomuto partition scheme (last element as rotate).
 * @array: array of integers.
 * @size: size of the array.
 * @left: starting index of the subset to order.
 * @right: ending index of the subset to order.
 *
 *Return: final partition index.
 */

int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *rotate, atop, below;

	rotate = array + right;
	for (atop = below = left; below < right; below++)
	{
		if (array[below]<*rotate)
		{
			if (atop < below)
			{
				swap_nums(array + below, array + atop);
				print_array(array, size);
			}

			atop++;
		}
	}

	if (array[atop] > *rotate)
	{
		swap_nums(array + atop, rotate);
		print_array(array, size);
	}

	return (atop);
}

/**
 * lomuto_sort - Implement the quicksort algorithm through recursion
 * 
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 *
 * Description: Uses the Lomuto partition scheme.
 */

void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending
 *             order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Lomuto partition scheme. Prints
 *             the array after each swap of two elements.
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
