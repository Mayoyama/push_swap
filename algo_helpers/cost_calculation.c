/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calculation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thours <thours@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 15:33:05 by thours            #+#    #+#             */
/*   Updated: 2026/05/04 04:12:44 by thours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	calculate_cost(t_stack *stack, t_stack *target_stack)
{
	t_node	*current;

	get_above_med(stack, target_stack);
	current = stack->list;
	while (current)
	{
		current->target = get_target(target_stack, current);
		current = current->next;
	}
	current = stack->list;
	while (current)
	{
		current->push_cost = get_push_cost(target_stack, current);
		current = current->next;
	}
	get_cheapest(stack->list);
}

static int	get_cost(t_node *node)
{
	t_node	*current;
	int		cost;
	
	current = node;
	cost = 0;
	if (node->above_med == 1)
	{
		while (current)
		{
		cost++;
		current = current->prev;
		}
	}
	else
	{
		while (current)
		{
			cost++;
			current = current->next;
		}
	}
	return (cost);
}
t_node	*get_target(t_stack *stack, t_node *node)
{
	t_node	*target;
	t_node	*current;
	int		best_diff;

	target = NULL;
	best_diff = INT_MAX;
	current = stack->list;
	while (current)
	{
		if (current->value > node->value && current->value - node->value < best_diff)
		{
			target = current;
			best_diff = current->value - node->value;
		}
		current = current->next;
	}
	if (!target)
		return(find_smallest_value(stack->list));
	return (target);
}

int	get_push_cost(t_stack *target_stack, t_node *node)
{
	int		cost_node;
	int		cost_target;
	t_node	*target;

	target = get_target(target_stack, node);
	if (!target)
		return (INT_MAX);
	cost_node = get_cost(node);
	cost_target = get_cost(node->target);
	if (node->above_med && node->target->above_med)
		return (ft_max(cost_node, cost_target));
	else if (!node->above_med && !node->target->above_med)
		return (ft_max(cost_node, cost_target));
	else
		return (cost_node + cost_target);
}

void	get_cheapest(t_node *list)
{
	t_node	*current;
	t_node	*cheapest;
	
	current = list;
	cheapest = list;
	while (current)
	{
		if (current->push_cost < cheapest->push_cost)
			cheapest = current;
		current = current->next;
	}
	cheapest->cheapest = 1;
}