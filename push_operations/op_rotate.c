#include "../push_swap.h"

int	rotate_list(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || stack->size < 2)
		return (0);
	first = stack->list;
	last = stack->tail;
	stack->list = first->next;
	stack->list->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	stack->tail = first;
	return (1);
}

void	ra(t_input *input, t_stack *a)
{
	if (rotate_list(a))
	{
		input->op_counts->ra++;
		input->op_counts->total_ops++;
		write(1, "ra\n", 3);
	}
	else
		write(2, "ra failed\n", 10); // remove after debugging
}

void	rb(t_input *input, t_stack *b)
{
	if (rotate_list(b))
	{
	input->op_counts->rb++;
	input->op_counts->total_ops++;
	write(1, "rb\n", 3);
	}
	else
		write(2, "rb failed\n", 10); // remove after debugging
}

void	rr(t_input *input, t_stack *a, t_stack *b)
{
	int res_a;
	int res_b;

	res_a = rotate_list(a);
	res_b = rotate_list(b);
	if (res_a && res_b)
	{
		input->op_counts->rr++;
		input->op_counts->total_ops++;
		write(1, "rr\n", 3);
	}
	if (!res_a) 
		write(2, "rr:a failed\n", 12); // remove after debugging
	if (!res_b)
		write(2, "rr:b failed\n", 12); // remove after debugging
}