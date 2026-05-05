/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thours <thours@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 10:31:17 by thours            #+#    #+#             */
/*   Updated: 2026/05/05 14:40:27 by thours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_input	*extract_user_input(char **argv)
{
	int		i;
	t_input	*input;

	i = 1;
	input = create_input_struct();
	if (!input)
		return (NULL);
	while (argv[i])
	{
		if (is_parameter(argv[i]))
			get_parameter(input, argv[i]);
		if (is_valid_int(argv[i]))
			get_num_list(input, argv[i]);
		i++;
	}
	if (!input->list)
		return (free(input), NULL);
	input->size = get_list_size(input->list);
	if (check_for_duplicate(input->list) == 1)
		return (free(input), NULL);
	input->disorder = compute_disorder(input->list);
	get_index(input->list);
	return (input);
}

void	get_parameter(t_input *input, char *str)
{
	if (ft_strncmp(str, "--simple", 12) == 0)
		input->mod = SIMPLE;
	if (ft_strncmp(str, "--medium", 12) == 0)
		input->mod = MEDIUM;
	if (ft_strncmp(str, "--complex", 12) == 0)
		input->mod = COMPLEX;
	if (ft_strncmp(str, "--adaptative", 12) == 0)
		input->mod = ADAPTATIVE;
	if (ft_strncmp(str, "--bench", 12) == 0)
		input->bench_mod = 1;
}

/*
 *	Add every number present in the string to the list :
 *	Each time it finds a '-', '+' or a digit, add it to the list with
 *	addback_node finction, then go to the end of the number, and repeat
 *	the operation if needed
*/
void	get_num_list(t_input *input, char *str)
{
	int	i;
	int	malloc_error;

	i = 0;
	malloc_error = 0;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+' || ft_isdigit(str[i]))
		{
			addback_node(&(input->list), ft_atoi(&str[i]), &malloc_error);
			if (malloc_error == 1)
			{
				free_stack(input->list);
				return ;
			}
			while (str[i] == '-' || str[i] == '+' || ft_isdigit(str[i]))
				i++;
		}
		else
			i++;
	}
}

/*
 *	Iterate through the list, and for each node, a helper varaible "looper"
 *	iterate through the rest of the list to check if another node has
 *	the same value
*/
int	check_for_duplicate(t_node *head)
{
	t_node	*current;
	t_node	*looper;

	current = head;
	while (current->next)
	{
		looper = current->next;
		while (looper)
		{
			if (looper->value == current->value)
				return (1);
			looper = looper->next;
		}
		current = current->next;
	}
	return (0);
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
