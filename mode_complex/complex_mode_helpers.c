/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_mode_helpers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thours <thours@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 17:10:16 by speterse          #+#    #+#             */
/*   Updated: 2026/05/07 10:40:15 by thours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_stack *a)
{
	t_node	*temp;

	temp = a->list;
	while (temp && temp->next)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	set_radix_index(t_node *head)
{
	t_node	*current;
	t_node	*comparison;
	int		rank;

	current = head;
	while (current)
	{
		comparison = head;
		rank = 0;
		while (comparison)
		{
			if (current->value > comparison->value)
				rank++;
			comparison = comparison->next;
		}
		current->index = rank;
		current = current->next;
	}
}

int	get_max_bitsize(int size)
{
	int	bits;
	int	n;

	bits = 0;
	n = size -1;
	while (n > 0)
	{
		n /= 2;
		bits++;
	}
	return (bits);
}
