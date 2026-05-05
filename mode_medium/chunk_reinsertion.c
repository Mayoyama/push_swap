/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_reinsertion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thours <thours@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 15:39:20 by thours            #+#    #+#             */
/*   Updated: 2026/05/05 14:44:57 by thours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
 *	How the chunk reinsertion works :
 *	Before any reinsertion, calculate the cost of pushing each item from B
 *	next to their respective target on A (the item in A with the smallest value
 *	above the chunk item value in B). This calculation (you can find the
 *	fonction in algo_helpers/cost_calculation.c) is done by taking the place
 *	of both item in their respecting stack, and if the item is above the median
 *	or not. if both items are on the same side of the stack, takes in account
 *	that double operation like 'rr' and 'rrr' can be done to moove theim both
 *	in one operation.
 *	The median and cost related flags being stocked on the structure of an item,
 *	flags must be cleared with the function 'reset_cost_flags' after each
 *	reinsertion.
*/
void	handle_chunk_reinsertion(t_stack *a, t_stack *b, t_input *input)
{
	put_on_top_b(find_node_index(b->list, input->size - 1), b, input);
	pa(input, a, b);
	while (b->size > 0)
	{
		get_above_med(a, b);
		calculate_cost(b, a);
		reinsert_chunk_node(a, b, input);
		reset_cost_flags(a->list);
		reset_cost_flags(b->list);
	}
}

/*
 *	This reinsertion method (target based) takes in account that
 *	depending on the place of both items in their stack, rr or rrr operation
 *	can be done to moove theim simutaneously, by using the function
 *	'put_on_top_double'.
*/
void	reinsert_chunk_node(t_stack *a, t_stack *b, t_input *input)
{
	t_node	*node;
	t_node	*target;

	node = b->list;
	while (node && node->cheapest != 1)
		node = node->next;
	target = node->target;
	put_on_top_dbl(target, node, a, input);
	pa(input, a, b);
}

void	put_on_top_dbl(t_node *tar, t_node *node, t_stack *a, t_input *inp)
{
	t_stack	*b;

	b = a->twin_stack;
	if (tar->above_med && node->above_med)
	{
		while (a->list != tar && b->list != node)
			rr(inp, a, b);
	}
	if (!tar->above_med && !node->above_med)
	{
		while (a->list != tar && b->list != node)
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
