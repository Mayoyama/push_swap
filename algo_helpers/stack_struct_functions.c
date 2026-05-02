/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_struct_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thours <thours@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 21:40:24 by thours            #+#    #+#             */
/*   Updated: 2026/05/02 22:08:50 by thours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*create_stack_struct(t_input *input)
{
	t_stack	*stack;
	t_node	*current;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->list = NULL;
	stack->tail = NULL;
	stack->size = 0;
	if (input)
	{
		stack->list = input->list;
		stack->size = input->size;
		current = input->list;
		while (current->next)
			current = current->next;
		stack->tail = current;
	}
	return (stack);
}
