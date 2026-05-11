/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_mode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thours <thours@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 18:13:23 by speterse          #+#    #+#             */
/*   Updated: 2026/05/11 11:56:15 by thours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	adaptive_modeset(t_input *input)
{
	input->disorder = compute_disorder(input->list);
	if (input->disorder < 0.2)
		do_simple_algo(input);
	else if (input->disorder < 0.5)
		do_medium_algo(input);
	else
		do_complex_algo(input);
}
