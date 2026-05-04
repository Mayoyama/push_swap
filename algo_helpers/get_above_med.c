/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_above_med.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thours <thours@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 22:09:32 by thours            #+#    #+#             */
/*   Updated: 2026/05/04 13:10:32 by thours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	get_med_a(t_stack *a)
{
	t_node	*current;
	int		pos;

	pos = 0;
	current = a->list;
	while (current)
	{
		if (pos >= a->size / 2)
			current->above_med = 0;
		else
			current->above_med = 1;
		pos++;
		current = current->next;
	}
}

static void	get_med_b(t_stack *b)
{
	t_node	*current;
	int		pos;

	pos = 0;
	current = b->list;
	while (current)
	{
		if (pos >= b->size / 2)
			current->above_med = 0;
		else
			current->above_med = 1;
		pos++;
		current = current->next;
	}
}

void	get_above_med(t_stack *a, t_stack *b)
{
	if (a && a->list)
		get_med_a(a);
	if (b && b->list)
		get_med_b(b);
}
