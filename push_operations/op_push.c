#include "../push_swap.h"

int	push_to_dest(t_stack *dest, t_stack *src)
{
	t_node	*new_dest_top;

	if (!src || !src->list)
		return (0);
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
	return (1);
}

void	pa(t_input *input, t_stack *a, t_stack *b)
{
	if (push_to_dest(a, b))
	{
		input->op_counts.pa++;
		input->op_counts.total_ops++;
		write(1, "pa\n", 3);
	}
	else
		write(2, "pa failed\n", 10); // remove after debugging
}

void	pb(t_input *input, t_stack *a, t_stack *b)
{
	if (push_to_dest(b, a))
	{
		input->op_counts.pb++;
		input->op_counts.total_ops++;
		write(1, "pb\n", 3);
	}
	else
		write(2, "pb failed\n", 10); // remove after debugging
}