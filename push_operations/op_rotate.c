#include "../push_swap.h"

void rotate_list(t_input *stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || stack->size < 2)
		return;
	first = stack->list;
	last = first;
	while (last->next)
		last = last->next;
	stack->list = first->next;
	stack->list->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	
}

void	ra(t_input *a)
{
	rotate_list(a);
	write(1, "ra\n", 3);
}

void rb(t_input *b)
{
	rotate_list(b);
	write(1, "rb\n", 3);
}

void rr(t_input *a, t_input *b)
{
	rotate_list(a);
	rotate_list(b);
	write(1, "rr\n", 3);
}