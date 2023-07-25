#include "sort.h"
/**
 * node_swap - Swap two nodes in a doubly-linked list.
 *
 * @head: A pointer.
 * @node1: first node.
 * @node2: second node.
 */
void node_swap(listint_t **head, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;
	if (node2->next != NULL)
		{
		node2->next->prev = *node1;
		}
	node2->prev = (*node1)->prev;
	node2->next = *node1;
	if ((*node1)->prev != NULL)
		{
		(*node1)->prev->next = node2;
		}
	else
		*head = node2;
	(*node1)->prev = node2;
	*node1 = node2->prev;
}

/**
 * insertion_sort_list - Insertion sort algorithm sorts x
 * doubly linked list of integers.
 *
 * @list: A pointer.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *ibel, *add, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		{
		return;
		}

		ibel = (*list)->next;
		while (ibel != NULL)
		{
				tmp = ibel->next;
				add = ibel->prev;

				while (add != NULL && ibel->n < add->n)
				{
						node_swap(list, &add, ibel);
						print_list((const listint_t *)*list);
				}

				ibel = tmp;
		}
}
