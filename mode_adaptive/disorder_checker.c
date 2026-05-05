/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: speterse <speterse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 23:28:26 by speterse          #+#    #+#             */
/*   Updated: 2026/05/05 18:15:19 by speterse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

double	compute_disorder(t_node *lst)
{
	int		mistakes;
	int		pairs;
	t_node	*i;
	t_node	*j;

	mistakes = 0;
	pairs = 0;
	if (!lst)
		return (0.0);
	i = lst;
	while (i)
	{
		j = i->next;
		while (j)
		{
			pairs++;
			if (i->value > j->value)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	if (pairs == 0)
		return (0.0);
	return ((double) mistakes / pairs);
}
