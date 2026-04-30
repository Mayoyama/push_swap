/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thours <thours@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:16:09 by thours            #+#    #+#             */
/*   Updated: 2026/04/30 13:34:59 by thours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* fill_left : fill the start of expression with spaces if width is larger
*	than the expression
*
* print_hex_num : print the number, in lowercase or with uppercase if
*	conversion is %X
*				-> print the prefix if needed
*          		-> if there is a precision greater than len of
*					number, print "0"
*
* fill_right : if "-" flag is detected, print spaces at the end of
*	expression if needed
*
* print_hexa : print the full expression with given flags
*/

#include "libft.h"

static void	fill_left(unsigned int num, int len, t_flags *flags, int upper)
{
	int		num_len;
	char	c;

	if (flags->aff_left)
		return ;
	num_len = 0;
	if (!(num == 0 && flags->precision == 0))
		num_len = get_hexnum_len(num);
	if (num_len < flags->precision)
		num_len = flags->precision;
	if (flags->prefix)
		num_len += 2;
	if (flags->fill_zero)
		c = '0';
	else
		c = ' ';
	if (flags->prefix && flags->fill_zero && num_len < flags->width && upper)
		write(1, "0X", 2);
	if (flags->prefix && flags->fill_zero && num_len < flags->width && !upper)
		write(1, "0x", 2);
	while (num_len < len)
	{
		write(1, &c, 1);
		num_len++;
	}
}

static void	print_hex_num(unsigned int num, t_flags *flags, int upper)
{
	int	num_len;

	num_len = get_hexnum_len(num);
	if (flags->prefix && num != 0 && !(flags->fill_zero && !flags->aff_left))
	{
		if (upper)
			write(1, "0X", 2);
		else
			write(1, "0x", 2);
	}
	while (num_len < flags->precision)
	{
		write(1, "0", 1);
		num_len++;
	}
	put_hex_nbr(num, upper);
}

static void	fill_right(unsigned int num, int len, t_flags *flags)
{
	int	num_len;

	if (!flags->aff_left)
		return ;
	num_len = 0;
	if (!(num == 0 && flags->precision == 0))
		num_len = get_hexnum_len(num);
	if (num_len < flags->precision)
		num_len = flags->precision;
	if (flags->prefix)
		num_len += 2;
	while (num_len < len)
	{
		write(1, " ", 1);
		num_len++;
	}
}

int	print_hexa(unsigned int num, t_flags *flags, int upper)
{
	int	len;

	len = get_hex_expr_size(num, flags);
	fill_left(num, len, flags, upper);
	if (!(num == 0 && flags->precision == 0))
		print_hex_num(num, flags, upper);
	fill_right(num, len, flags);
	return (len);
}
