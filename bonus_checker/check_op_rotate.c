/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_op_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thours <thours@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 18:47:00 by speterse          #+#    #+#             */
/*   Updated: 2026/05/11 11:31:01 by thours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	checker_ra(t_input *input, t_stack *a)
{
	rotate_list(a);
	input->op_counts->ra++;
	input->op_counts->total_ops++;
}

void	checker_rb(t_input *input, t_stack *b)
{
	rotate_list(b);
	input->op_counts->rb++;
	input->op_counts->total_ops++;
}

void	checker_rr(t_input *input, t_stack *a, t_stack *b)
{
	rotate_list(a);
	rotate_list(b);
	input->op_counts->rr++;
	input->op_counts->total_ops++;
}
