#include "../push_swap.h"

void swap_top_two(t_input *stack)
{
	t_node	*top_node;
	t_node	*btm_node;

	if (!stack || stack->size < 2)
		return ;
	
	btm_node = stack->list;
	top_node = btm_node->next;

	stack->list = top_node;
	btm_node->next = top_node->next;
	if (btm_node->next)


	stack->list = temp->next;
	temp->next = stack->list->next;
	stack->list->prev = NULL;
	
	//NEED TO FINISH



}

void sa(t_input *a)
{
	swap_top_two(a);
	write(1, "sa\n", 3);
}

void sb(t_input *b)
{
	swap_top_two(b);
	write(1, "sb\n", 3);
}

void ss(t_input *a, t_input *b)
{
	swap_top_two(a);
	swap_top_two(b);
	write(1, "ss\n", 3);
}