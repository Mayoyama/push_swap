/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thours <thours@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 11:04:46 by thours            #+#    #+#             */
/*   Updated: 2026/05/12 16:56:26 by thours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "checker.h"

int	main(int argc, char **argv)
{
	t_input	*input;

	if (argc > 1)
	{
		if (!check_input(argv))
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

void	start_checker(t_input *input)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = create_stack_struct(input);
	stack_b = create_stack_struct(NULL);
	if (!stack_a || !stack_b)
	{
		write(2, "Error\n", 6);
		if (stack_a)
			free(stack_a);
		if (stack_b)
			free(stack_b);
		free_input(input);
		return ;
	}
	execute_operations(input, stack_a, stack_b);
	if (algorithm_has_end(stack_a, stack_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(stack_a);
	free(stack_b);
}

void	execute_operations(t_input *inp, t_stack *a, t_stack *b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		if (!handle_line(line, inp, a, b))
		{
			write(2, "Error\n", 6);
			free(line);
			return ;
		}
		free(line);
	}
}

int	handle_line(char *line, t_input *inp, t_stack *a, t_stack *b)
{
	if (ft_strncmp(line, "sa\n", 3) == 0)
		checker_sa(inp, a);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		checker_sb(inp, b);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		checker_ss(inp, a, b);
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		checker_pa(inp, a, b);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		checker_pb(inp, a, b);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		checker_ra(inp, a);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		checker_rb(inp, b);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		checker_rr(inp, a, b);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		checker_rra(inp, a);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		checker_rrb(inp, b);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		checker_rrr(inp, a, b);
	else
		return (0);
	return (1);
}
