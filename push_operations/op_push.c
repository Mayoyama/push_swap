#include "../push_swap.h"

void	push_to_dest(t_stack *dest, t_stack *src)
{
	t_node	*new_dest_top;

	if (!src || !src->list)
		return ;
	new_dest_top = src->list;
	src->list = new_dest_top->next;
	if (src->list)
		src->list->prev = NULL;
	else
		src->tail = NULL;
	src->size--;
	new_dest_top->prev = NULL;
	new_dest_top->next = dest->list;
	if (dest->list)
		dest->list->prev = new_dest_top;
	else
		dest->tail = new_dest_top;
	dest->list = new_dest_top;
	dest->size++;
	
}

void pa(t_stack *a, t_stack *b)
{
	push_to_dest(a, b);
	write(1, "pa\n", 3);
}

void pb(t_stack *a, t_stack *b)
{
	push_to_dest(b, a);
	write(1, "pb\n", 3);
}