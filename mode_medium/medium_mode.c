/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_mode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thours <thours@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 04:38:10 by thours            #+#    #+#             */
/*   Updated: 2026/05/04 17:22:10 by thours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	do_medium_algo(t_input *input)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = create_stack_struct(input);
	stack_b = create_stack_struct(NULL);
	stack_a->twin_stack = stack_b;
	stack_b->twin_stack = stack_a;
	if (!stack_a || !stack_b)
	{
		write (2, "error\n", 6);
		return ;
	}
	run_medium_algo(input, stack_a);
}

void	run_medium_algo(t_input *input, t_stack *a)
{
	run_phase_one(input, a);
	put_on_top_a(find_smallest_value(a->list), a, input);
	//ft_printf("\nAfter sorting:\n");
	//print_stack(a->list);
	ft_printf("medium mode finished\n");
	ft_printf("Disorder = ");
	ft_putdouble_fd(input->disorder * 100, 1, 2);
	ft_printf("%%\nTotal count of operations = %d\n", input->op_counts->total_ops);
}

void	run_phase_one(t_input *input, t_stack *a)
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
		manage_chunk(input, a, chunk_start_id, chunk_end_id);
		chunk_start_id = chunk_end_id + 1;
		chunk_end_id = chunk_start_id + chunk_size - 1;
	}
}
