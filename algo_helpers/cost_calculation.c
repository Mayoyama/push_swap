/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calculation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thours <thours@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 15:33:05 by thours            #+#    #+#             */
/*   Updated: 2026/05/05 14:34:16 by thours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
 *	How cost is calculated :
 *	First initialize the median flag
 *	After that, also initialize the target flag, as these will be used for
 *	the cost calculation of both item and it target.
 *	Then calculate de push cost with the function 'get_push_cost'.
 *	Depending on it position on the stack (above or under the median), it
 *	calculate how must operation is needed to put an item and his target
 *	on top of the stack.
*/
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

/*
 *	The target of an item is the item in the other stack, that have the
 *	smallest value above the value of the item. This means that, in order
 *	to be sorted, you should put the item of a stack just above it target
 *	of the other stack.
 *	This calculation is made by iterating through each item of the other
 *	stack and calculating the difference of values, and stocking the one
 *	with the lowest positive difference.
*/
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
		if (current->value > node->value
			&& current->value - node->value < best_diff)
		{
			target = current;
			best_diff = current->value - node->value;
		}
		current = current->next;
	}
	if (!target)
		return (find_smallest_value(stack->list));
	return (target);
}

/*
 *	Calculate how much operation it takes to put both item and
 *	it target on top of their stacks.
 *	If both are under the median, or both above, return wich
 *	item cost the most to push, as 'rr' or 'rrr' double operations
 *	can be used to moove theim both at the same time.
 *	Else return the summ of their costs.
*/
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
