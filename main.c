/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: speterse <speterse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 17:19:58 by thours            #+#    #+#             */
/*   Updated: 2026/05/15 14:07:59 by speterse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	handle_input(t_input *input);

int	main(int argc, char **argv)
{
	t_input	*input;

	input = NULL;
	if (argc > 1)
	{
		if (!check_input(argv))
		{
			write(2, "Error\n", 6);
			return (0);
		}
		input = extract_user_input(argv);
		if (input)
		{
			handle_input(input);
			free_input(input);
		}
		else
			write(2, "Error\n", 6);
	}
	return (0);
}

static void	handle_input(t_input *input)
{
	if (get_list_size(input->list) <= 9
		&& (input->mod == ADAPTIVE || input->mod == NONE))
	{
		handle_small_list(input);
		if (input->bench_mod)
			benchmark_mode(input);
		return ;
	}
	if (input->mod == SIMPLE)
		do_simple_algo(input);
	else if (input->mod == MEDIUM)
		do_medium_algo(input);
	else if (input->mod == COMPLEX)
		do_complex_algo(input);
	else if (input->mod == ADAPTIVE || input->mod == NONE)
		adaptive_modeset(input);
	if (input->bench_mod)
		benchmark_mode(input);
}
