/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thours <thours@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 14:38:39 by thours            #+#    #+#             */
/*   Updated: 2026/04/30 13:34:27 by thours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * fill_blakns : if widh is greater than 1, fill the rest of the
 		expression with spaces
 *
 * print_char : print a char with given flags
*/

#include "libft.h"

static void	fill_blanks(t_flags *flags)
{
	int	i;

	if (flags->width > 1)
	{
		i = 0;
		while (i < flags->width - 1)
		{
			write(1, " ", 1);
			i++;
		}
	}
}

int	print_char(char c, t_flags *flags)
{
	if (!flags->aff_left)
		fill_blanks(flags);
	write(1, &c, 1);
	if (flags->aff_left)
		fill_blanks(flags);
	if (flags->width > 1)
		return (flags->width);
	return (1);
}
