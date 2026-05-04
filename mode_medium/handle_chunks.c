/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_chunks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thours <thours@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 12:43:40 by thours            #+#    #+#             */
/*   Updated: 2026/05/04 18:02:38 by thours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	manage_chunk(t_input *input, t_stack *a, int start, int end)
{
	t_node	*chunk_node;
	int		i;
	t_stack *b;

	b = a->twin_stack;
	i = 0;
	while (start + i <= end)
	{
		chunk_node = find_cheapest_to_push(a, start, end);
		push_to_b(input, a, b, chunk_node);
		if (chunk_node->index < (end - start) / 2)
			rb(input, b);
		i++;
	}
	handle_chunk_reinsertion(a, b, input);
}

t_node	*find_cheapest_to_push(t_stack *a, int start, int end)
{
	int		ops_to_do;
	int		biggest_diff;
	t_node	*cheapest;
	t_node	*current;

	biggest_diff = INT_MAX;
	get_above_med(a, NULL);
	while (start <= end)
	{
		current = find_node_index(a->list, start);
		if (!current)
		{
			start++;
			continue ;
		}
		ops_to_do = get_ops_to_do(current, a);
		if (ops_to_do < biggest_diff)
		{
			cheapest = current;
			biggest_diff = ops_to_do;
		}
		start++;
	}
	return (cheapest);
}

int	get_ops_to_do(t_node *node, t_stack *stack)
{
	int	ops_to_do;

	if (node->above_med == 1)
			ops_to_do = get_pos(node, stack->list);
		else
			ops_to_do = stack->size - get_pos(node, stack->list);
	return (ops_to_do);
}
