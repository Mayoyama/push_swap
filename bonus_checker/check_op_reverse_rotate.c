/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_op_reverse_rotate.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thours <thours@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 18:44:55 by speterse          #+#    #+#             */
/*   Updated: 2026/05/11 11:29:50 by thours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	checker_rra(t_input *input, t_stack *a)
{
	rev_rotate_list(a);
	input->op_counts->rra++;
	input->op_counts->total_ops++;
}

void	checker_rrb(t_input *input, t_stack *b)
{
	rev_rotate_list(b);
	input->op_counts->rrb++;
	input->op_counts->total_ops++;
}

void	checker_rrr(t_input *input, t_stack *a, t_stack *b)
{
	rev_rotate_list(a);
	rev_rotate_list(b);
	input->op_counts->rrr++;
	input->op_counts->total_ops++;
}
