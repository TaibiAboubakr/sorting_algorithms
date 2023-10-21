#include "sort.h"
/**
 * swap_nodes - swaps the position of two nodes in
 * a doubly linked list
 * @b: pointer to the the 1st node to be swapped
 * @c: pointer to the 2nd node to be swapped
 * Return: no return
 */
void swap_nodes(listint_t *b, listint_t *c)
{
	if (b->prev)
		b->prev->next = c;
	if (c->next)
		c->next->prev = b;
	b->next = c->next;
	c->prev = b->prev;
	b->prev = c;
	c->next = b;
}
/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in asceding order using the Insertion sort algirithm
 * @list: pointer to the linked list to be sorted
 * Return: no return
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *temp1;

	if (!list || !*list)
		return;
	if (!(*list)->next)
		return;

	temp = (*list)->next;
	while (temp)
	{
		temp1 = temp;
		temp = temp->next;
		while (temp1 && temp1->prev)
		{
			if (temp1->prev->n > temp1->n)
			{
				swap_nodes(temp1->prev, temp1);
				if (!temp1->prev)
					*list = temp1;
				print_list((listint_t *)*list);
			}
			else
				temp1 = temp1->prev;
		}
	}
}
