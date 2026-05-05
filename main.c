/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: speterse <speterse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 17:19:58 by thours            #+#    #+#             */
/*   Updated: 2026/05/05 18:42:31 by speterse         ###   ########.fr       */
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
				do_complex_algo(input);
			else if (input->mod == ADAPTATIVE || input->mod == NONE)
				adaptive_modeset(input);
		}
		else
			write(2, "error\n", 6);
	}
	else
		ft_printf("Input error\n");
	return (0);
}
