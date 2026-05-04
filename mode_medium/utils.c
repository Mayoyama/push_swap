/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thours <thours@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 10:58:07 by thours            #+#    #+#             */
/*   Updated: 2026/05/04 22:31:30 by thours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_chunk_size(t_stack *stack)
{
	int	i;

	i = 0;
	while ((i * i) < stack->size)
		i++;
	return (stack->size / 2);
}

int	get_chunk_count(int chunk_size, t_stack *stack)
{
	int	size;
	int	count;
	
	size = stack->size;
	count = size / chunk_size;
	if (count * chunk_size != size)
		count++;
	return (count);
}

t_node	*find_node_index(t_node *list, int index)
{
	t_node	*current;

	current = list;
	while (current)
	{
		if (current->index == index)
			return (current);
		current = current->next;
	}
	return (NULL);
}