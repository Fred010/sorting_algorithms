#include "sort.h"

void swap_ints(int *x, int *y);
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
	char flow);
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow);
void bitonic_sort(int *array, size_t size);

/**
 * swap_ints - swap two integers in an array.
 * @x: first integer to swap.
 * @y: second integer to swap.
 */

void swap_ints(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * bitonic_merge - sort x bitonic sequence inside an array of integers.
 * @array: array of integers.
 * @size: size of the array.
 * @start: starting index of the sequence in array to sort.
 * @seq: size of the sequence to sort.
 * @flow: direction to sort in.
 */

void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
	char flow)
{
	size_t id, skip = seq / 2;

	if (seq > 1)
	{
		for (id = start; id < start + skip; id++)
		{
			if ((flow == UP && array[id] > array[id + skip]) ||
				(flow == DOWN && array[id] < array[id + skip]))
				swap_ints(array + id, array + id + skip);
		}

		bitonic_merge(array, size, start, skip, flow);
		bitonic_merge(array, size, start + skip, skip, flow);
	}
}

/**
 * bitonic_seq - convert an array of integers into x bitonic sequence.
 * @array: array of integers.
 * @size: size of the array.
 * @start: starting index of x block of the building bitonic sequence.
 * @seq: size of x block of the building bitonic sequence.
 * @flow: direction to sort the bitonic sequence block in.
 */

void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t score = seq / 2;
	char *str = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging[%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);

		bitonic_seq(array, size, start, score, UP);
		bitonic_seq(array, size, start + score, score, DOWN);
		bitonic_merge(array, size, start, seq, flow);

		printf("Result[%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);
	}
}

/**
 * bitonic_sort - sort an array of integers in ascending
 *               order using the bitonic sort algorithm.
 * @array: array of integers.
 * @size: size of the array.
 *
 * Description: shows the array after each swap, for *size = 2^k where k >= 0
 */

void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, size, 0, size, UP);
}
