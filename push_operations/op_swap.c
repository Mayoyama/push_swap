#include "../push_swap.h"

int	swap_top_two(t_stack *stack)
{
	t_node	*top_node;
	t_node	*second_node;
	t_node	*temp;

	if (!stack || stack->size < 2)
		return (0);
	second_node = stack->list;
	top_node = second_node->next;
	temp = top_node->next;
	second_node->next = temp;
	if (second_node->next)
		second_node->next->prev = second_node;
	second_node->prev = top_node;
	top_node->next = second_node;
	top_node->prev = NULL;
	stack->list = top_node;
	if (!temp)
		stack->tail = second_node;
	return (1);
}

void	sa(t_input *input, t_stack *a)
{
	if (swap_top_two(a))
	{
		input->op_counts->sa++;
		input->op_counts->total_ops++;
		if (!input->bench_mod)
			write(1, "sa\n", 3);
	}
	else
		write(2, "sa failed\n", 10); // remove after debugging
}

void	sb(t_input *input, t_stack *b)
{
	if (swap_top_two(b))
	{
		input->op_counts->sb++;
		input->op_counts->total_ops++;
		if (!input->bench_mod)
			write(1, "sb\n", 3);
	}
	else
		write(2, "sb failed\n", 10); // remove after debugging
}

void	ss(t_input *input, t_stack *a, t_stack *b)
{
	int res_a;
	int res_b;

	res_a = swap_top_two(a);
	res_b = swap_top_two(b);
	if (res_a && res_b)
	{
		input->op_counts->ss++;
		input->op_counts->total_ops++;
		if (!input->bench_mod)
			write(1, "ss\n", 3);
	}
	if (!res_a)
		write(2, "ss:a failed\n", 12); // remove after debugging
	if (!res_b)
		write(2, "ss:b failed\n", 12); // remove after debugging
}
