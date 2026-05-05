/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_chunks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thours <thours@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 12:43:40 by thours            #+#    #+#             */
/*   Updated: 2026/05/05 14:44:03 by thours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
 *	this function takes care of the insertion of the chunk's items in B.
 *	Get through the A stack with a serie of operations while A still have a
 *	chunk item in it with a serie of 'ra' operations.
 *	After each rotation, if a chunk item is on top of A, push it to B.
*/
void	manage_chunk(t_input *input, t_stack *a, int start, int end)
{
	t_stack	*b;

	b = a->twin_stack;
	while (chunk_has_element_in_a(a, start, end))
	{
		if (is_in_chunk(a->list, start, end))
		{
			pb(input, a, b);
			optimize_b_inser(input, b, start, end);
		}
		else if (is_in_chunk(a->tail, start, end))
		{
			rra(input, a);
			pb(input, a, b);
			optimize_b_inser(input, b, start, end);
		}
		else
			ra(input, a);
	}
}

int	is_in_chunk(t_node *node, int start, int end)
{
	if (!node)
		return (0);
	if (node->index >= start && node->index <= end)
		return (1);
	return (0);
}

/*
 *	With chunk item being pushed in B depending just on their place in A,
 *	it can be intresting to do a rotate on B if an item, regarding it
 *	relative index, should rather be at the bottom of B.
 *	This optimisation does a 'rb' operation if an item should be in
 *	the low zone of the chunk, after each insertion fram A to B.
 *	Optimisation phase has shown that this optimization works with big
 *	chunks, but lose it efficiency with small chunks, sometime showing even
 *	worst results with chunks under around 25 items.
*/
void	optimize_b_inser(t_input *input, t_stack *b, int start, int end)
{
	if (b->list->index < (end - start) / 2)
		rb(input, b);
}

int	chunk_has_element_in_a(t_stack *a, int start, int end)
{
	t_node	*current;

	if (!a->list)
		return (0);
	current = a->list;
	while (current)
	{
		if (current->index >= start && current->index <= end)
			return (1);
		current = current->next;
	}
	return (0);
}
