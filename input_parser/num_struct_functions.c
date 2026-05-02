/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_struct_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thours <thours@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 09:45:50 by thours            #+#    #+#             */
/*   Updated: 2026/05/02 10:27:01 by thours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*create_num_node(int num)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = num;
	node->prev = node;
	node->next = node;
	node->target = NULL;
	node->index = 0;
	node->above_med = 0;
	node->push_cost = 0;
	node->cheapest = 0;
	return (node);
}

void	addback_node(t_node **head, int num)
{
	t_node	*new_node;

	new_node = create_num_node(num);
	if (*head == NULL)
		*head = new_node;
	else
	{
		new_node->next = *head;
		new_node->prev = (*head)->prev;
		new_node->prev->next = new_node;
		(*head)->prev = new_node;
	}
}

void	free_stack(t_node *head)
{
	t_node	*last_node;
	t_node	*current;

	if (!head)
		return ;
	last_node = head->prev;
	current = head;
	while (current->next != last_node)
	{
		free(current->prev);
		current = current->next;
	}
}