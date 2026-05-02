/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index_and_target.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thours <thours@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 15:21:23 by thours            #+#    #+#             */
/*   Updated: 2026/05/02 15:47:26 by thours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	get_index_and_target(t_node *list)
{
	get_index(list);
	get_target(list);
}

void	get_index(t_node *list)
{
	t_node	*current;
	t_node	*looper;
	int		under;
	int		current_value;

	current = list;
	while (current)
	{
		under = 0;
		current_value = current->value;
		looper = list;
		while (looper)
		{
			if (looper->value < current_value)
				under++;
			looper = looper->next;
		}
		current->index = under;
		current = current->next;
	}
}

void	get_target(t_node *list)
{
	t_node	*current;
	t_node	*looper;

	current = list;
	while (current)
	{
		looper = list;
		while (looper)
		{
			if (looper->index == current->index + 1)
			{
				current->target = looper;
				break ;
			}
			looper = looper->next;
		}
		current = current->next;
	}
}
