/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_mode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: speterse <speterse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 17:10:24 by speterse          #+#    #+#             */
/*   Updated: 2026/05/05 19:58:25 by speterse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	do_complex_algo(t_input *input)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = create_stack_struct(input);
	stack_b = create_stack_struct(NULL);
	if (!stack_a || !stack_b)
	{
		write(2, "error\n", 6);
		if (stack_a)
			free(stack_a);
		if (stack_b)
			free(stack_b);
		return ;
	}
	if (!is_sorted(stack_a))
	{
		set_radix_index(stack_a->list);
		radix(input, stack_a, stack_b);
	}
	///////////////////////////////////////////// DEBUGING
	ft_printf("\n");
	print_stack(stack_a->list);
	ft_printf("Total of operations: %d\n", \
	input->op_counts->total_ops);
	/////////////////////////////////////////////*/
	mem_cleanup(input, stack_a, stack_b);
}
/*	///////////////////////////////////////////// DEBUGING
	ft_printf("\n");
	print_stack(stack_a->list);
	ft_printf("Total of operations: %d\n", \
	input->op_counts->total_ops);
	/////////////////////////////////////////////*/

//input → stack A → (radix distribution) → stack B → 
// (Turk reconstruction) → sorted A
void	radix(t_input *input, t_stack *a, t_stack *b)
{
	int	bit;
	int	bitsize;
	int	size;

	bit = 0;
	bitsize = get_max_bitsize(input->size);
	while (bit < bitsize)
	{
		size = input->size;
		while (size--)
		{
			if (((a->list->index >> bit) & 1) == 0)
				pb(input, a, b);
			else
				ra(input, a);
		}
		while (b->size > 0)
			pa(input, a, b);
		bit++;
	}
}
