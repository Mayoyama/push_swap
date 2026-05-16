/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_mode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thours <thours@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 21:37:33 by thours            #+#    #+#             */
/*   Updated: 2026/05/16 11:33:26 by thours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
 *	HOW THIS ALGORITHM WORKS :
 *
 *	This algorithm is a selection sort adaptation. At each loop, search for the
 *	smallest value in stack A, and put it at the top of stack B, until only one
 *	item is left on stack A. Once it done, put everything back to stack A.
*/
void	do_simple_algo(t_input *input)
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
	run_simple_algo(input, stack_a, stack_b);
	free(stack_a);
	free(stack_b);
}

/*
 *	Extracting the smallest value for A :
 *		- If the smallest node found is under the median, do a serie of
 *		reverse rotate operation to extract it from the bottom
 *		- If the smallest node found is above the median, do a serie of
 *		rotate operation to extract it from the top
 *		- Once the smallest node is on the top of A, do a push operation
 *		to put it on the top of B.
*/
void	push_to_b(t_input *input, t_stack *a, t_stack *b, t_node *node)
{
	while (node->prev != NULL)
	{
		if (node->above_med == 1)
			ra(input, a);
		else
			rra(input, a);
	}
	pb(input, a, b);
}

/*
 *	First extract the smallest value of A one by one with the extract_node
 *	function, until only one node is left in A (the one with the highest value)
 *	After it is done, every node is in B in descending order, except the
 *	node left in A.
 *	After that, do a serie of push operations to put every node from B back
 *	to the A stack, until B is empty.
 *	A stack is now sorted in ascending order.
*/
void	run_simple_algo(t_input *input, t_stack *a, t_stack *b)
{
	t_node	*smallest;

	if (algorithm_has_end(a, b))
		return ;
	while (a->size > 1)
	{
		get_above_med(a, b);
		smallest = find_smallest_value(a->list);
		push_to_b(input, a, b, smallest);
	}
	while (b->size > 0)
	{
		pa(input, a, b);
	}
}
