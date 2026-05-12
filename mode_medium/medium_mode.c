/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_mode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thours <thours@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 04:38:10 by thours            #+#    #+#             */
/*   Updated: 2026/05/12 10:43:31 by thours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
 *	HOW THIS CHUNK BASED ALGORITHM WORKS :
 *	First split in chunks (originally √n chunks, but it appeared in the
 *	optimisation phase that chunk size =  n / 2 was more efficient) of items of
 *	the list that follow themselves by relative index.
 *	It extracts chunks one after another in the B pile. After all item are on B,
 *	put first the item with highest value in A. Once it's done, it will reinsert
 *	every item one by one, by finding the cheapest item to push each time
 *	(cheapest = the smallest cost in operations to put an item on top of B and
 *	it's target with the closest value above it on top of A)
 *	After that and when every item is back on A and sorted, put the item with
 *	smallest value on top.
*/
void	do_medium_algo(t_input *input)
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
	run_medium_algo(input, stack_a);
	free(stack_a);
	free(stack_b);
}

void	run_medium_algo(t_input *input, t_stack *a)
{
	run_phase_one(input, a);
	handle_chunk_reinsertion(a, a->twin_stack, input);
	put_on_top_a(find_smallest_value(a->list), a, input);
}

void	run_phase_one(t_input *input, t_stack *a)
{
	int	chunk_size;
	int	chunk_start_id;
	int	chunk_end_id;

	chunk_size = get_chunk_size(a);
	chunk_start_id = 0;
	chunk_end_id = chunk_size - 1;
	while (chunk_start_id < input->size)
	{
		if (chunk_end_id >= input->size)
			chunk_end_id = input->size - 1;
		manage_chunk(input, a, chunk_start_id, chunk_end_id);
		chunk_start_id = chunk_end_id + 1;
		chunk_end_id = chunk_start_id + chunk_size - 1;
	}
}
