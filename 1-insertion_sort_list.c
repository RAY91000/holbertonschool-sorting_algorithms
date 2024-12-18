#include "sort.h"
#include <stdio.h>

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 *
 * @list: Pointer to the head of the list
 * @node1: The first node to swap
 * @node2: The second node to swap
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev)
		node1->prev->next = node2;
	else
		*list = node2;

	if (node2->next)
		node2->next->prev = node1;

	node2->prev = node1->prev;
	node1->next = node2->next;
	node2->next = node1;
	node1->prev = node2;
}

/**
 * insertion_sort_list - Sort doubly linked list of integer in ascending order
 * using the Insertion sort algorithm.
 *
 * @list: Pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *key;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current)
	{
		key = current;
		while (key->prev && key->n < key->prev->n)
		{
			swap_nodes(list, key->prev, key);
			print_list(*list);
		}
		current = current->next;
	}
}
