/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thours <thours@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 17:19:58 by thours            #+#    #+#             */
/*   Updated: 2026/05/03 17:44:48 by thours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
static void	split_stack(t_input *input)
{
	t_stack *stack_a = create_stack_struct(input);
	t_stack *stack_b = create_stack_struct(NULL);
	int	i = 0;
	int starting_size = stack_a->size;
	while (i < starting_size / 2)
	{
		pb(input, stack_a, stack_b);
		i++;
	}
	calculate_cost(stack_b, stack_a);
	ft_printf("STACK A:\n");
	print_stack(stack_a->list);
	ft_printf("STACK B:\n");
	print_stack(stack_b->list);
}*/

int	main(int argc, char **argv)
{
	t_input	*input;

	input = NULL;
	if (argc > 1 && check_input(argc, argv))
	{
		input = extract_user_input(argv);
		if (input)
		{
			ft_printf("bench mod = %d\n", input->bench_mod);
			ft_printf("mod = %d\n", input->mod);
			ft_printf("list size = %d\n", input->size);
			ft_printf("disorder = ");
			ft_putdouble_fd(input->disorder, 1, 2);
			ft_printf("\nstarting simple algorithm:\n\n");
			do_simple_algo(input);
		}
		else
			write(2, "error\n", 6);
	}
	else
		ft_printf("Input error\n");
	return (0);
}
