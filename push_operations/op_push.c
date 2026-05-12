/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thours <thours@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 18:43:39 by speterse          #+#    #+#             */
/*   Updated: 2026/05/12 10:44:45 by thours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	push_to_dest(t_stack *dest, t_stack *src)
{
	t_node	*new_dest_top;

	if (!src || !src->list)
		return (0);
	new_dest_top = src->list;
	src->list = new_dest_top->next;
	if (src->list)
		src->list->prev = NULL;
	else
		src->tail = NULL;
	src->size--;
	new_dest_top->prev = NULL;
	new_dest_top->next = dest->list;
	if (dest->list)
		dest->list->prev = new_dest_top;
	else
		dest->tail = new_dest_top;
	dest->list = new_dest_top;
	dest->size++;
	return (1);
}

void	pa(t_input *input, t_stack *a, t_stack *b)
{
	push_to_dest(a, b);
	input->op_counts->pa++;
	input->op_counts->total_ops++;
	write(1, "pa\n", 3);
}

void	pb(t_input *input, t_stack *a, t_stack *b)
{
	push_to_dest(b, a);
	input->op_counts->pb++;
	input->op_counts->total_ops++;
	write(1, "pb\n", 3);
}
