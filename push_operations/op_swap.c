/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thours <thours@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 10:44:59 by thours            #+#    #+#             */
/*   Updated: 2026/05/12 10:45:00 by thours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	swap_top_two(a);
	input->op_counts->sa++;
	input->op_counts->total_ops++;
	write(1, "sa\n", 3);
}

void	sb(t_input *input, t_stack *b)
{
	swap_top_two(b);
	input->op_counts->sb++;
	input->op_counts->total_ops++;
	write(1, "sb\n", 3);
}

void	ss(t_input *input, t_stack *a, t_stack *b)
{
	swap_top_two(a);
	swap_top_two(b);
	input->op_counts->ss++;
	input->op_counts->total_ops++;
	write(1, "ss\n", 3);
}
