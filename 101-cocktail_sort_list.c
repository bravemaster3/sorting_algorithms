#include "sort.h"
/**
 * cocktail_sort_list - sorts list using cocktail sort
 * @list: pointer to head pointer
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *curr, *temp1, *temp2;
	int swapped = 1;

	if (list == NULL || *list == NULL)
		return;
	while (swapped == 1)
	{
		curr = *list;
		swapped = 0;
		cocktail_loop_forward(list, &curr, &swapped);
		if (swapped == 0)
			break;
		swapped = 0;
		while (curr != NULL && curr->prev != NULL)
		{
			if (curr->n < curr->prev->n)
			{
				temp1 = curr;
				temp2 = curr->prev;
				swap_nodes(list, &(temp2), &(temp1));
				curr = temp1;
				print_list(*list);
				swapped = 1;
			}
			if (curr->prev)
				curr = curr->prev;
		}
		if (swapped == 0)
			break;
	}
}

/**
 * swap_nodes - swaps 2 nodes of a doubly linked list
 * @head: pointer to the head pointer
 * @node1: node to the left
 * @node2: node to the right
 */
void swap_nodes(listint_t **head, listint_t **node1, listint_t **node2)
{
	listint_t *temp;

	temp = *node2;
	if ((*node1)->prev != NULL)
	{
		(*node1)->prev->next = (*node2);
		(*node2)->prev = (*node1)->prev;
	}
	else
	{
		(*node2)->prev = NULL;
		*head = (*node2);
	}
	if (temp->next != NULL)
	{
		temp->next->prev = (*node1);
		(*node1)->next = temp->next;
		(*node1)->prev = temp;
		(*node2) = temp->next;
	}
	else
		(*node2) = NULL;
	temp->next = (*node1);
	(*node1)->prev = temp;
	(*node1) = temp->prev;
}

/**
 * cocktail_loop_forward - part of the cocktail sort code,the loop forward
 * @list: double pointer to head of the list
 * @c: double pointer to the current pointer
 * @swapped: pointer to the integer used to track if there has been a swap
 *
 */
void cocktail_loop_forward(listint_t **list, listint_t **c, int *swapped)
{
	listint_t *temp1;

	while ((*c) != NULL && (*c)->next != NULL)
	{
		if ((*c)->n > (*c)->next->n)
		{
			temp1 = (*c);
			swap_nodes(list, c, &((*c)->next));
			*c = temp1;
			print_list(*list);
			*swapped = 1;
		}
		if ((*c)->next)
			(*c) = (*c)->next;
	}
}
