/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_struct_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thours <thours@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 10:50:49 by thours            #+#    #+#             */
/*   Updated: 2026/05/05 14:37:57 by thours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_input	*create_input_struct(void)
{
	t_input	*input;

	input = malloc(sizeof(t_input));
	if (!input)
		return (NULL);
	input->list = NULL;
	input->size = 0;
	input->mod = NONE;
	input->bench_mod = 0;
	input->op_counts = create_opcounts_struct();
	if (!input->op_counts)
		return (free_input(input), NULL);
	input->disorder = 0.0;
	return (input);
}

t_opcount	*create_opcounts_struct(void)
{
	t_opcount	*opcount;

	opcount = malloc(sizeof(t_opcount));
	if (!opcount)
		return (NULL);
	opcount->pa = 0;
	opcount->pb = 0;
	opcount->sa = 0;
	opcount->sb = 0;
	opcount->ss = 0;
	opcount->ra = 0;
	opcount->rb = 0;
	opcount->rr = 0;
	opcount->rra = 0;
	opcount->rrb = 0;
	opcount->rrr = 0;
	opcount->total_ops = 0;
	return (opcount);
}

void	free_input(t_input *input)
{
	free_stack(input->list);
	free(input->op_counts);
	free(input);
	input = NULL;
}
