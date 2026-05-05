/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: speterse <speterse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 18:47:00 by speterse          #+#    #+#             */
/*   Updated: 2026/05/05 18:48:20 by speterse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	rotate_list(a);
	input->op_counts->ra++;
	input->op_counts->total_ops++;
	write(1, "ra\n", 3);
}

void	rb(t_input *input, t_stack *b)
{
	rotate_list(b);
	input->op_counts->rb++;
	input->op_counts->total_ops++;
	write(1, "rb\n", 3);
}

void	rr(t_input *input, t_stack *a, t_stack *b)
{
	rotate_list(a);
	rotate_list(b);
	input->op_counts->rr++;
	input->op_counts->total_ops++;
	write(1, "rr\n", 3);
}
