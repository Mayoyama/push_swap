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
#include "checker.h"

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
		free_input(input);
	}
	return (0);
}

static int	init_stacks(t_input *inp, t_stack *a, t_stack *b)
{
	a = create_stack_struct(inp);
	b = create_stack_struct(NULL);
	if (!a || !b)
	{
		write(2, "Error\n", 6);
		if (a)
			free(a);
		if (b)
			free(b);
		free_input(inp);
		return (0);
	}
	return (1);
}

void	start_checker(t_input *input)
{
	char	*line;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (!init_stacks(input, stack_a, stack_b))
		return ;
	while ((line = get_next_line(1)) != NULL)
	{
		if (!handle_line(line, input, stack_a, stack_b))
		{
			write(2, "Error\n", 2);
			return ;
		}
	}
	if (algorithm_has_end(stack_a, stack_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(stack_a);
	free(stack_b);
}

int	handle_line(char *line, t_input *inp, t_stack *a, t_stack *b)
{
	if (ft_strncmp(line, "sa\n", 5))
		sa(inp, a);
	else if (ft_strncmp(line, "sb\n", 4))
		sb(inp, b);
	else if (ft_strncmp(line, "ss\n", 4))
		ss(inp, a, b);
	else if (ft_strncmp(line, "pa\n", 4))
		pa(inp, a, b);
	else if (ft_strncmp(line, "pb\n", 4))
		pb(inp, a, b);
	else if (ft_strncmp(line, "ra\n", 4))
		ra(inp, a);
	else if (ft_strncmp(line, "rb\n", 4))
		rb(inp, a);
	else if (ft_strncmp(line, "rr\n", 4))
		rr(inp, a, b);
	else if (ft_strncmp(line, "rra\n", 5))
		rra(inp, a);
	else if (ft_strncmp(line, "rrb\n", 5))
		rrb(inp, b);
	else if (ft_strncmp(line, "rrr\n", 5))
		rrr(inp, a, b);
	else
		return (0);
	return (1);
}