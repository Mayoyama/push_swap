/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_struct_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thours <thours@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 10:50:49 by thours            #+#    #+#             */
/*   Updated: 2026/05/02 15:08:04 by thours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_input	*create_input_struct(void)
{
	t_input	*input;

	input = malloc(sizeof(t_input));
	if (!input)
		return (NULL);
	input->list = NULL;
	input->size = 0;
	input->mod = NONE;
	input->bench_mod = 0;
	input->disorder = 0.0;
	return (input);
}

void	free_input(t_input *input)
{
	free_stack(input->list);
	free(input);
	input = NULL;
}