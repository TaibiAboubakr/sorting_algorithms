#include "sort.h"

/**
 * swap_nodes - function that swaps the positions of two nodes
 *              in a doubly linked list.
 * @node_1: pointer to the first node to be swapped
 * @node_2: pointer to the second node to be swapped
 */
void swap_nodes(listint_t **node_1, listint_t **node_2)
{
	listint_t *nx_1, *nx_2, *pv_1, *pv_2, *nb_1 = NULL, *nb_2 = NULL;
	listint_t *n1 = *node_1, *n2 = *node_2;

	if (!n1 || !n2)
		return;
	if (n1 == n2)
		return;

	nx_1 = n1->next;
	nx_2 = n2->next;
	pv_1 = n1->prev;
	pv_2 = n2->prev;

	if (n2->next)
		nb_2 = n2->next;
	if (n1->prev)
		nb_1 = n2->prev;

	n1->next = nx_2;
	n1->prev = n2;
	n2->next = n1;
	n2->prev = pv_1;

}


/**
 * insertion_sort_list - function that sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: pointer to linked list to be sorted
 */

void insertion_sort_list(listint_t **list)
{

	listint_t *tmp, *tmp1, *curr, *swp;
	int c;

	if (!list || !*list)
		return;

	tmp = *list;
	if (!tmp->next)
		return;

	for (tmp = tmp->next; tmp; tmp = tmp->next)
	{	curr->n = tmp->n;
		tmp1 = tmp->prev;
		while (tmp1 && tmp1->n > curr->n)
		{
			swp->n = tmp1->next->n;
			tmp1->next->n = tmp1->n;
			tmp1->n = swp->n;
			print_list(*list);
			tmp1 = tmp1->prev;
		}
	}
}
