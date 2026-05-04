/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_mode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thours <thours@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 04:38:10 by thours            #+#    #+#             */
/*   Updated: 2026/05/04 13:49:44 by thours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	do_medium_algo(t_input *input)
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
	run_medium_algo(input, stack_a, stack_b);
}

void	run_medium_algo(t_input *input, t_stack *a, t_stack *b)
{
	run_phase_one(input, a, b);
}

void	run_phase_one(t_input *input, t_stack *a, t_stack *b)
{
	int	chunk_size;
	int	chunk_start_id;
	int	chunk_end_id;

	chunk_size = get_chunk_size(a);
	ft_printf("Chunk size is %d\n", chunk_size);
	chunk_start_id = 0;
	chunk_end_id = chunk_size - 1;
	while (chunk_start_id < input->size)
	{
		if (chunk_end_id >= input->size)
			chunk_end_id = input->size - 1;
		manage_chunk(input, a, b, chunk_start_id, chunk_end_id);
		chunk_start_id = chunk_end_id + 1;
		chunk_end_id = chunk_start_id + chunk_size - 1;
	}
}
