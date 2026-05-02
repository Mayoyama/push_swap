#include "../push_swap.h"

void rev_rotate_list(t_input *stack)
{
	t_node	*curr_last;
	t_node	*new_last;

	if (!stack || stack->size < 2)
		return;
	curr_last = stack->list;
	while (curr_last->next)
		curr_last = curr_last->next;
	new_last = curr_last->prev;
	new_last->next = NULL;
	curr_last->next = stack->list;
	stack->list->prev = curr_last;
	curr_last->prev = NULL;
	stack->list = curr_last;
}	

void rra(t_input *a)
{
	rev_rotate_list(a);
	write(1, "rra\n", 4);
}

void rrb(t_input *b)
{
	rev_rotate_list(b);
	write(1, "rrb\n", 4);
}

void rrr(t_input *a, t_input *b)
{
	rev_rotate_list(a);
	rev_rotate_list(b);
	write(1, "rrr\n", 4);
}