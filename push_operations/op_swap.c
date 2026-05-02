#include "../push_swap.h"

void	swap_top_two(t_stack *stack)
{
	t_node	*top_node;
	t_node	*second_node;
	t_node	*temp;

	if (!stack || stack->size < 2)
		return ;
	
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
}

void	sa(t_stack *a)
{
	swap_top_two(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	swap_top_two(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	swap_top_two(a);
	swap_top_two(b);
	write(1, "ss\n", 3);
}