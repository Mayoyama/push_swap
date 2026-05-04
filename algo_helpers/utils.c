/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thours <thours@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 22:33:34 by thours            #+#    #+#             */
/*   Updated: 2026/05/04 14:12:17 by thours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	algorithm_has_end(t_stack *a, t_stack *b)
{
	t_node	*current;

	if (b->size != 0)
		return (0);
	current = a->list;
	while(current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

t_node	*find_smallest_value(t_node *list)
{
	t_node	*current;
	t_node	*smallest;

	if (!list)
		return (NULL);
	current = list;
	smallest = list;
	while (current)
	{
		if (current->value < smallest->value)
			smallest = current;
		current = current->next;
	}
	return (smallest);
}

int	get_pos(t_node *node, t_node *list)
{
	t_node	*current;
	int		pos;

	current = list;
	pos = 0;
	while (current)
	{
		if (node == current)
			return (pos);
		pos++;
		current = current->next;
	}
	return (pos);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	reset_cost_flags(t_node *list)
{
	t_node	*current;

	if (!list)
		return ;
	current = list;
	while (current)
	{
		current->cheapest = 0;
		current->push_cost = 0;
		current->target = 0;
		current->above_med = 0;
		current = current->next;
	}
}