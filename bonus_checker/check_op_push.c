/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_op_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thours <thours@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 18:43:39 by speterse          #+#    #+#             */
/*   Updated: 2026/05/12 10:37:18 by thours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	checker_pa(t_input *input, t_stack *a, t_stack *b)
{
	push_to_dest(a, b);
	input->op_counts->pa++;
	input->op_counts->total_ops++;
}

void	checker_pb(t_input *input, t_stack *a, t_stack *b)
{
	push_to_dest(b, a);
	input->op_counts->pb++;
	input->op_counts->total_ops++;
}
