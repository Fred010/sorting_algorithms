#include "sort.h"

/**
 * fetch_max - gets the maximum value in an array of integers.
 * @array: array of integers.
 * @size: size of the array.
 *
 * Return: maximum integer in the array.
 */

int fetch_max(int *array, int size)
{
	int nth, id;

	for (nth = array[0], id = 1; id < size; id++)
	{
		if (array[id] > nth)
		{
		    nth = array[id];
		}
	}

	return (nth);
}

/**
 * counting_sort - sort an array of integers in ascending order
 *                using the counting sort algorithm.
 * @array: array of integers.
 * @size: size of the array.
 *
 * Description: outputs the counting array after setting it up.
 */

void counting_sort(int *array, size_t size)
{
	int *compute, *sorted, nth, id;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) *size);
	if (sorted == NULL)
		return;
	nth = fetch_max(array, size);
	compute = malloc(sizeof(int) *(nth + 1));
	if (compute == NULL)
	{
		free(sorted);
		return;
	}

	for (id = 0; id < (nth + 1); id++)
		compute[id] = 0;
	for (id = 0; id < (int) size; id++)
		compute[array[id]] += 1;
	for (id = 0; id < (nth + 1); id++)
		compute[id] += compute[id - 1];
	print_array(compute, nth + 1);

	for (id = 0; id < (int) size; id++)
	{
		sorted[compute[array[id]] - 1] = array[id];
		compute[array[id]] -= 1;
	}

	for (id = 0; id < (int) size; id++)
		array[id] = sorted[id];

	free(sorted);
	free(compute);
}
