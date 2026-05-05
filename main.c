/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thours <thours@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 17:19:58 by thours            #+#    #+#             */
/*   Updated: 2026/05/06 11:33:56 by thours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_input	*input;

	input = NULL;
	if (argc > 1 && check_input(argc, argv))
	{
		input = extract_user_input(argv);
		if (input)
		{
			if (input->mod == SIMPLE)
				do_simple_algo(input);
			else if (input->mod == MEDIUM)
				do_medium_algo(input);
			else if (input->mod == COMPLEX)
				ft_printf("No complex algorithm implemented.\n");
			else if (input->mod == ADAPTATIVE || input->mod == NONE)
				ft_printf("No adaptative algorithm implemented\n");
			if (input->bench_mod)
				benchmark_mode(input);
		}
		else
			write(2, "error\n", 6);
	}
	else
		ft_printf("Input error\n");
	return (0);
}
