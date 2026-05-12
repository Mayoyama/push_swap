/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_small_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thours <thours@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 11:06:47 by thours            #+#    #+#             */
/*   Updated: 2026/05/12 10:36:19 by thours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	dispatch(t_input *input, t_stack *a, t_stack *b);

void	handle_small_list(t_input *input)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = create_stack_struct(input);
	if (!stack_a)
	{
		write(2, "error\n", 6);
		free_input(input);
		return ;
	}
	stack_b = create_stack_struct(NULL);
	if (!stack_b)
	{
		write (2, "error\n", 6);
		free_input(input);
		free(stack_a);
		return ;
	}
	stack_a->twin_stack = stack_b;
	stack_b->twin_stack = stack_a;
	dispatch(input, stack_a, stack_b);
	free(stack_a);
	free(stack_b);
}

static void	dispatch(t_input *input, t_stack *a, t_stack *b)
{
	if (algorithm_has_end(a, b))
		return ;
	if (input->size == 2)
		sa(input, a);
	else if (input->size == 3)
		sort_3(input, a);
	else
		sort_4_to_9(input, a, b);
}

void	sort_3(t_input *input, t_stack *a)
{
	int	top;
	int	mid;
	int	bot;

	top = a->list->index;
	mid = a->list->next->index;
	bot = a->list->next->next->index;
	if (top > mid && top > bot && mid < bot)
		ra(input, a);
	else if (top > mid && top > bot && mid > bot)
	{
		sa(input, a);
		rra(input, a);
	}
	else if (top > mid && top < bot)
		sa(input, a);
	else if (top < mid && top < bot && mid > bot)
	{
		rra(input, a);
		sa(input, a);
	}
	else if (top < mid && top > bot)
		rra(input, a);
}

void	sort_4_to_9(t_input *input, t_stack *a, t_stack *b)
{
	t_node	*smallest;

	while (a->size > 3)
		pb(input, a, b);
	sort_3(input, a);
	while (b->size > 0)
	{
		get_above_med(a, b);
		calculate_cost(b, a);
		reinsert_chunk_node(a, b, input);
		reset_cost_flags(a->list);
		reset_cost_flags(b->list);
	}
	smallest = find_smallest_value(a->list);
	get_above_med(a, b);
	while (a->list != smallest)
	{
		if (smallest->above_med == 1)
			ra(input, a);
		else
			rra(input, a);
	}
}
