#include "sort.h"

void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
	size_t back);
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 * merge_subarr - sort a subarray of integers.
 * @subarr: subarray of an array of integers to sort.
 * @buff: buffer to store the sorted subarray.
 * @front: front index of the array.
 * @mid: middle index of the array.
 * @back: back index of the array.
 */

void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
	size_t back)
{
	size_t id1, id2, id3 = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);

	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	for (id1 = front, id2 = mid; id1 < mid && id2 < back; id3++)
		buff[id3] = (subarr[id1] < subarr[id2]) ? subarr[id1++] : subarr[id2++];
	for (; id1 < mid; id1++)
		buff[id3++] = subarr[id1];
	for (; id2 < back; id2++)
		buff[id3++] = subarr[id2];
	for (id1 = front, id3 = 0; id1 < back; id1++)
		subarr[id1] = buff[id3++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
 * merge_sort_recursive - implement the merge sort algorithm through recursion.
 * @subarr: subarray of an array of integers to sort.
 * @buff: buffer to store the sorted result.
 * @front: front index of the subarray.
 * @back: back index of the subarray.
 */

void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		merge_sort_recursive(subarr, buff, front, mid);
		merge_sort_recursive(subarr, buff, mid, back);
		merge_subarr(subarr, buff, front, mid, back);
	}
}

/**
 * merge_sort - sort an array of integers in ascending
 *             order using the merge sort algorithm.
 * @array: array of integers.
 * @size: size of the array.
 *
 * Description: implements the top-down merge sort algorithm.
 */

void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) *size);
	if (buff == NULL)
		return;

	merge_sort_recursive(array, buff, 0, size);

	free(buff);
}
