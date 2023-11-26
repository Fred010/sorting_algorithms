#include "sort.h"

int get_max(int *array, int size);
void radix_counting_sort(int *array, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);

/**
 * get_max - fetch the maximum value in an array of integers.
 * @array: array of integers.
 * @size: size of the array.
 *
 *Return: maximum integer in the array.
 */

int get_max(int *array, int size)
{
	int max, id;

	for (max = array[0], id = 1; id < size; id++)
	{
		if (array[id] > max)
			max = array[id];
	}

	return (max);
}

/**
 * radix_counting_sort - sort the significant digits of an array of integers
 *                      in ascending order using the counting sort algorithm.
 * @array: array of integers.
 * @size: size of the array.
 * @sig: significant digit to sort on.
 * @buff: buffer to store the sorted array.
 */

void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
	int count[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	size_t id;

	for (id = 0; id < size; id++)
		count[(array[id] / sig) % 10] += 1;

	for (id = 0; id < 10; id++)
		count[id] += count[id - 1];

	for (id = size - 1;
		(int) id >= 0; id--)
	{
		buff[count[(array[id] / sig) % 10] - 1] = array[id];
		count[(array[id] / sig) % 10] -= 1;
	}

	for (id = 0; id < size; id++)
		array[id] = buff[id];
}

/**
 * radix_sort - sort an array of integers in ascending
 *             order using the radix sort algorithm.
 * @array: array of integers.
 * @size: size of the array.
 *
 * Description: implements the LSD radix sort algorithm
 */
void radix_sort(int *array, size_t size)
{
	int max, sig, *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) *size);
	if (buff == NULL)
		return;

	max = get_max(array, size);
	for (sig = 1; max / sig > 0; sig *= 10)
	{
		radix_counting_sort(array, size, sig, buff);
		print_array(array, size);
	}

	free(buff);
}
