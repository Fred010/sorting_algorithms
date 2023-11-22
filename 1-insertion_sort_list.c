#include "sort.h"

/**
 * binode_swap - swap two nodes in a listint_t doubly-linked list
 * 
 * @h: points to the head of the doubly-linked list.
 * @n1: points to the first node to swap.
 * @n2: second node to swap.
 */

void binode_swap(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else *h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 *                      using the insertion sort algorithm
 * 
 * @list: points to the head of a doubly-linked list of integers.
 *
 * Description: output the list after each swap.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *index, *insert, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (index = (*list)->next; index != NULL; index = temp)
	{
		temp = index->next;
		insert = index->prev;
		while (insert != NULL && index->n < insert->n)
		{
			binode_swap(list, &insert, index);
			print_list((const listint_t *) *list);
		}
	}
}
