/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_struct_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thours <thours@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 09:45:50 by thours            #+#    #+#             */
/*   Updated: 2026/05/05 14:37:18 by thours           ###   ########.fr       */
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
	node->prev = NULL;
	node->next = NULL;
	node->target = NULL;
	node->index = 0;
	node->above_med = 0;
	node->push_cost = 0;
	node->cheapest = 0;
	return (node);
}

void	addback_node(t_node **head, int num, int *malloc_error)
{
	t_node	*new_node;
	t_node	*current;

	new_node = create_num_node(num);
	if (!new_node)
	{
		*malloc_error = 1;
		return ;
	}
	if (*head == NULL)
		*head = new_node;
	else
	{
		current = *head;
		while (current->next)
			current = current->next;
		current->next = new_node;
		new_node->prev = current;
	}
}

void	free_stack(t_node *head)
{
	t_node	*next;
	t_node	*current;

	if (!head)
		return ;
	current = head;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	head = NULL;
}

void	print_stack(t_node *head)
{
	t_node	*current;

	if (!head)
	{
		ft_printf("NULL\n");
		return ;
	}
	current = head;
	while (current)
	{
		ft_printf("value = %d (id = %d,", current->value, current->index);
		if (current->target)
			ft_printf(" target = %d, ", current->target->value);
		else
			ft_printf(" target = NULL, ");
		ft_printf("above_med = %d, ", current->above_med);
		ft_printf("push_cost = %d, cheapest = %d)\n",
			current->push_cost, current->cheapest);
		current = current->next;
	}
	ft_printf("\n");
}

int	get_list_size(t_node *head)
{
	t_node	*current;
	int		count;

	if (!head)
		return (0);
	count = 0;
	current = head;
	while (current)
	{
		count++;
		current = current->next;
	}
	return (count);
}
