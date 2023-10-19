#include "sort.h"

/**
 * insertion_sort_list - sorts a linked list using insertion sort
 * @list: head of the list
 * Return: No return
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *ptr, *temp, *hold;
	int swapped = 0;

	if (list == NULL || *list == NULL)
		return;
	curr = *list;
	while (curr->next != NULL)
	{
		swapped = 0;
		if (curr->n > curr->next->n)
		{
			ptr = curr->next;
			hold = curr->next->next;
			while (curr != NULL && curr->n > ptr->n)
			{
				ptr = curr->next;
				temp = curr->next->next;
				curr->next = temp;
				if (temp != NULL)
					temp->prev = curr;
				ptr->next = curr;
				ptr->prev = curr->prev;
				curr->prev = ptr;
				if (ptr->prev != NULL)
					ptr->prev->next = ptr;
				else
					*list = ptr;
				temp = curr;
				curr = ptr->prev;
				print_list(*list);
			}
			swapped = 1;
			if (hold != NULL)
				curr = hold->prev;
			else
				break;
		}
		if (swapped == 0)
			curr = curr->next;
	}
}
