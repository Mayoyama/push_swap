/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thours <thours@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 11:01:32 by thours            #+#    #+#             */
/*   Updated: 2026/04/30 13:35:50 by thours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * get_len : get the length of a pointer when printed in hexadecimal
 *
 * fill_blanks : if the width is bigger than the expression size, print spaces
 *
 * put_hex_nbr : print a number (casted in unsigned long) in hexadecimal
 *
 * print_mem : print the memory adress in hexadecimal format and with
 * 	the 0x prefix
*/

#include "libft.h"

static int	get_len(void *ptr)
{
	int				len;
	unsigned long	n;

	if (!ptr)
		len = 5;
	else
	{
		n = (unsigned long)ptr;
		len = 2;
		while (n >= 16)
		{
			n /= 16;
			len++;
		}
		len++;
	}
	return (len);
}

static void	fill_blanks(void *ptr, t_flags *flags)
{
	int	len;
	int	i;

	len = get_len(ptr);
	i = len;
	while (i < flags->width)
	{
		write(1, " ", 1);
		i++;
	}
}

int	print_mem(void *ptr, t_flags *flags)
{
	if (!flags->aff_left)
		fill_blanks(ptr, flags);
	if (!ptr)
		write(1, "(nil)", 5);
	else
	{
		write(1, "0x", 2);
		put_hex_nbr((unsigned long)ptr, 0);
	}
	if (flags->aff_left)
		fill_blanks(ptr, flags);
	if (get_len(ptr) < flags->width)
		return (flags->width);
	return (get_len(ptr));
}
