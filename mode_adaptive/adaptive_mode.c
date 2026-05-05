/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_mode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: speterse <speterse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 18:13:23 by speterse          #+#    #+#             */
/*   Updated: 2026/05/05 20:19:10 by speterse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	adaptive_modeset(t_input *input)
{
	input->disorder = compute_disorder(input->list);
	ft_printf("\n");
	if (input->disorder < 0.2)
		do_simple_algo(input);
	else if (input->disorder < 0.5)
		do_medium_algo(input);
	else
		do_complex_algo(input);
}
