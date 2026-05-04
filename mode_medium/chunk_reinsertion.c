/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_reinsertion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thours <thours@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 15:39:20 by thours            #+#    #+#             */
/*   Updated: 2026/05/04 16:58:19 by thours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	handle_chunk_reinsertion(t_stack *a, t_stack *b, t_input *input)
{
	while (b->size > 0)
	{
		get_above_med(a, b);
		calculate_cost(b, a);
		reinsert_chunk_node(a, b, input);
		reset_cost_flags(a->list);
		reset_cost_flags(b->list);
	}
}

void	reinsert_chunk_node(t_stack *a, t_stack *b, t_input *input)
{
	t_node	*node;
	t_node	*target;

	node = b->list;
	while (node && node->cheapest != 1)
		node = node->next;
	target = node->target;
	put_on_top_double(target, node, a, input);
	pa(input, a, b);
}

void	put_on_top_double(t_node *tar, t_node *node, t_stack *a, t_input *inp)
{
	t_stack	*b;

	b = a->twin_stack;
	if (tar->above_med && node->above_med)
	{
		while (tar->prev && node->prev)
			rr(inp, a, b);
	}
	if (!tar->above_med && !node->above_med)
	{
		while (tar->prev && node->prev)
			rrr(inp, a, b);
	}
	put_on_top_a(tar, a, inp);
	put_on_top_b(node, b, inp);
}

void	put_on_top_a(t_node *node, t_stack *a, t_input *inp)
{
	while (node->prev)
	{
		if (node->above_med)
			ra(inp, a);
		else
			rra(inp, a);
	}
}

void	put_on_top_b(t_node *node, t_stack *b, t_input *inp)
{
	while (node->prev)
	{
		if (node->above_med)
			rb(inp, b);
		else
			rrb(inp, b);
	}
}