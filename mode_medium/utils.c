/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thours <thours@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 10:58:07 by thours            #+#    #+#             */
/*   Updated: 2026/05/05 14:02:02 by thours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
 *	Here the calculation of the chunk size how th original chunk algorithm is
 *	done is still present (chunk_size = √n), but tests shown that size / 2 is
 *	the most efficient for data sorting around a few hundreds.
 *	√n should be more optimized for much larger data sests.
*/
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
