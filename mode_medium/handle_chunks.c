/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_chunks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thours <thours@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 12:43:40 by thours            #+#    #+#             */
/*   Updated: 2026/05/04 22:17:43 by thours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	manage_chunk(t_input *input, t_stack *a, int start, int end)
{
	t_stack *b;

	b = a->twin_stack;
	while (chunk_has_element_in_a(a, start, end))
	{
		if (is_in_chunk(a->list, start, end))
		{
			pb(input, a, b);
			optimize_b_insertion(input, b, start, end);
		}
		else if (is_in_chunk(a->tail, start, end))
		{
			rra(input, a);
			pb(input, a, b);
			optimize_b_insertion(input, b, start, end);
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

void	optimize_b_insertion(t_input *input, t_stack *b, int start, int end)
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