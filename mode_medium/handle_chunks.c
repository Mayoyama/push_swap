/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_chunks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thours <thours@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 12:43:40 by thours            #+#    #+#             */
/*   Updated: 2026/05/04 14:15:11 by thours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	manage_chunk(t_input *input, t_stack *a, t_stack *b, int start, int end)
{
	t_node	*chunk_node;
	int		i;

	i = 0;
	while (start + i <= end)
	{
		ft_printf("extracting from id %d to %d\n", start, end);
		chunk_node = find_cheapest_to_push(a, start, end);
		ft_printf("cheapest to push = %d\n", chunk_node->index);
		push_to_b(input, a, b, chunk_node);
		i++;
	}
	ft_printf("STACK A:\n");
	print_stack(a->list);
	ft_printf("STACK B:\n");
	print_stack(b->list); ft_printf("\n");
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
		if (current->above_med == 1)
			ops_to_do = get_pos(current, a->list);
		else
			ops_to_do = a->size - get_pos(current, a->list);
		if (ops_to_do < biggest_diff)
		{
			cheapest = current;
			biggest_diff = ops_to_do;
		}
		start++;
	}
	return (cheapest);
}