#include "../push_swap.h"

int	rev_rotate_list(t_stack *stack)
{
	t_node	*curr_last;
	t_node	*new_last;

	if (!stack || stack->size < 2)
		return (0);
	curr_last = stack->tail;
	new_last = curr_last->prev;
	new_last->next = NULL;
	curr_last->next = stack->list;
	stack->list->prev = curr_last;
	curr_last->prev = NULL;
	stack->list = curr_last;
	stack->tail = new_last;
	return (1);
}

void	rra(t_input *input, t_stack *a)
{
	if (rev_rotate_list(a))
	{
		input->op_counts->rra++;
		input->op_counts->total_ops++;
		write(1, "rra\n", 4);
	}
	else
		write(2, "rra failed\n", 11); // remove after debugging
}

void	rrb(t_input *input, t_stack *b)
{
	if (rev_rotate_list(b))
	{
		input->op_counts->rrb++;
		input->op_counts->total_ops++;
		write(1, "rrb\n", 4);
	}
	else
		write(2, "rrb failed\n", 11); // remove after debugging
}

void	rrr(t_input *input, t_stack *a, t_stack *b)
{
	int res_a;
	int res_b;

	res_a = rev_rotate_list(a);
	res_b = rev_rotate_list(b);
	if (res_a && res_b)
	{
		input->op_counts->rrr++;
		input->op_counts->total_ops++;
		write(1, "rrr\n", 4);
	}
	if (!res_a)
		write(2, "rrr:a failed\n", 13); // remove after debugging
	if (!res_b)
		write(2, "rrr:b failed\n", 13); // remove after debugging
}
