#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list using Cocktail Shaker Sort
 * @list: A pointer to the pointer of the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *current;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (swapped)
	{
		swapped = 0;
		for (current = *list; current->next != NULL; current = current->next)
		{
			if (current->n > current->next->n)
			{
				swap_nodes1(list, current, current->next);
				swapped = 1;
				print_list(*list);
			}
		}

		if (!swapped)
			break;

		swapped = 0;
		for (; current->prev != NULL; current = current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes1(list, current->prev, current);
				swapped = 1;
				print_list(*list);
			}
		}
	}
}

/**
 * swap_nodes1 - Swaps two nodes in a doubly linked list
 * @list: A pointer to the pointer of the head of the list
 * @node1: First node to swap
 * @node2: Second node to swap
 */
void swap_nodes1(listint_t **list, listint_t *node1, listint_t *node2)
{
	listint_t *prev_node1, *next_node2;

	prev_node1 = node1->prev;
	next_node2 = node2->next;

	if (prev_node1)
		prev_node1->next = node2;
	else
		*list = node2;
	node2->prev = prev_node1;

	node1->prev = node2;
	node1->next = next_node2;

	if (next_node2)
		next_node2->prev = node1;
	node2->next = node1;
}
