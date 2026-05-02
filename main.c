/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thours <thours@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 17:19:58 by thours            #+#    #+#             */
/*   Updated: 2026/05/02 22:01:19 by thours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

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
			print_stack(input->list);
			do_simple_algo(input);
		}
		else
			write(2, "error\n", 6);
	}
	else
		ft_printf("Input error\n");
	return (0);
}
