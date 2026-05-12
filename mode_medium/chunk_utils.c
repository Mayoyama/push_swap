/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: speterse <speterse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 10:58:07 by thours            #+#    #+#             */
/*   Updated: 2026/05/12 17:49:33 by speterse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
 *	Here the calculation of the chunk size how th original chunk algorithm is
 *	done is still present (chunk_size = √n), but tests shown that size / 2 is
 *	the most efficient for data sorting around a few hundreds.
 *	√n should be more optimized for much larger data sets.
*/
int	get_chunk_size(t_stack *stack)
{
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
