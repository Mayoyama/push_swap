/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thours <thours@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 11:04:46 by thours            #+#    #+#             */
/*   Updated: 2026/05/08 18:50:15 by thours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_input	*input;

	if (argc > 2)
	{
		if (!check_input(argc, argv))
		{
			write(2, "Error\n", 6);
			return (0);
		}
		input = extract_user_input(argv);
		if (!input)
		{
			write(2, "Error\n", 6);
			return (1);
		}
		start_checker(input);
	}
	return (0);
}

static int	init_stacks(t_input *inp, t_stack *a, t_stack *b)
{
	a = create_stack_struct(input);
	b = create_stack_struct(NULL);
	if (!a || !b)
	{
		write(2, "Error\n", 6);
		if (a)
			free(a);
		if (b)
			free(b);
		free_input(inp);
	}
}

void	start_checker(t_input *input)
{
	char	*line;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (!init_stacks(input, stack_a, stack_b))
		return ;
	while ((line != get_next_line(1)) != NULL)
	{
		if (!handle_line(line))
		{
			write(2, "Error\n", 2);
			return ;
		}
	}
}