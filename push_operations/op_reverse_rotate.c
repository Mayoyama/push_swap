/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: speterse <speterse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 18:44:55 by speterse          #+#    #+#             */
/*   Updated: 2026/05/05 18:46:34 by speterse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	rev_rotate_list(a);
	input->op_counts->rra++;
	input->op_counts->total_ops++;
	write(1, "rra\n", 4);
}

void	rrb(t_input *input, t_stack *b)
{
	rev_rotate_list(b);
	input->op_counts->rrb++;
	input->op_counts->total_ops++;
	write(1, "rrb\n", 4);
}

void	rrr(t_input *input, t_stack *a, t_stack *b)
{
	rev_rotate_list(a);
	rev_rotate_list(b);
	input->op_counts->rrr++;
	input->op_counts->total_ops++;
	write(1, "rrr\n", 4);
}
