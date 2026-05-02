/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_simple_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thours <thours@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 21:37:33 by thours            #+#    #+#             */
/*   Updated: 2026/05/02 23:18:54 by thours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	do_simple_algo(t_input *input)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = create_stack_struct(input);
	stack_b = create_stack_struct(NULL);
	if (!stack_a || !stack_b)
	{
		write (2, "error\n", 6);
		return ;
	}
	run_simple_algo(stack_a, stack_b);
	free_stack(stack_a->list);
	free(stack_a);
	free(stack_b);
	free(input);
}

void	run_simple_algo(t_stack *a, t_stack *b)
{
	t_node	*smallest;
	
	while (a->size > 1)
	{
		get_above_med(a, b);
		smallest = find_smallest_value(a->list);
	}
	while (b->size > 0)
		pa(a, b);
}

static void	extract_node(t_stack *a, t_stack *b, t_node *node)
{
	while (node->prev != NULL)
	{
		if (node->above_med == 1)
			ra(a);
		else
			rra(a);
	}
	pb(a, b);
}