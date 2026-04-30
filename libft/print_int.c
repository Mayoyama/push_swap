/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thours <thours@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 10:44:19 by thours            #+#    #+#             */
/*   Updated: 2026/04/30 13:35:21 by thours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * write_sign : used in fonction fill_left -> if a left padding with 0 is
 *	present, the sign must be printed before the '0' padding.
 *
 * fill_left : fill the start of expression with ' ' or '0' if width is
 * 		larger than the expression. If pqdding mod is '0' and a sign must be
 * 		printed, print it before the '0' padding.
 *
 * print_num : print the number
 *              -> print a sign or space if needed, and it has not been already
 * 					printed by the fill_left function
 *              -> if there is a precision greater than len of number, print "0"
 *
 * fill_right : if "-" flag is detected, print spaces at the end of
 * 		expression if needed
 *
 * print_int : print the full expression with given flags
*/

static void	write_sign(int num, t_flags *flags)
{
	if (num < 0)
		write(1, "-", 1);
	else if (flags->aff_sign)
		write(1, "+", 1);
	else if (flags->spc_for_pos)
		write(1, " ", 1);
	flags->sign_written = 1;
}

static void	fill_left(int num, int len, t_flags *flags)
{
	int		num_len;
	char	c;

	if (flags->aff_left)
		return ;
	num_len = get_int_len(num);
	if (num_len < flags->precision)
		num_len = flags->precision;
	if (num < 0 || flags->aff_sign || flags->spc_for_pos)
		num_len++;
	if (flags->fill_zero && flags->precision == -1 && num_len < flags->width)
		c = '0';
	else
		c = ' ';
	if (c == '0')
		write_sign(num, flags);
	while (num_len < len)
	{
		write(1, &c, 1);
		num_len++;
	}
}

static void	print_num(int num, t_flags *flags)
{
	int	num_len;

	if (flags->precision != -1 && flags->fill_zero)
		flags->fill_zero = 0;
	num_len = get_int_len(num);
	if (!flags->sign_written)
	{
		if (num < 0)
			write(1, "-", 1);
		else if (flags->aff_sign)
			write(1, "+", 1);
		else if (flags->spc_for_pos && !flags->aff_sign)
			write(1, " ", 1);
	}
	while (num_len < flags->precision)
	{
		write(1, "0", 1);
		num_len++;
	}
	ft_putnbr(num);
}

static void	fill_right(int num, int len, t_flags *flags)
{
	int	num_len;

	if (!flags->aff_left)
		return ;
	num_len = get_int_len(num);
	if (num_len < flags->precision)
		num_len = flags->precision;
	if (num < 0 || flags->aff_sign || flags->spc_for_pos)
		num_len++;
	while (num_len < len)
	{
		write(1, " ", 1);
		num_len++;
	}
}

int	print_int(int num, t_flags *flags)
{
	int	len;

	if (num == 0 && flags->precision == 0)
		return (0);
	len = get_int_expr_size(num, flags);
	fill_left(num, len, flags);
	print_num(num, flags);
	fill_right(num, len, flags);
	return (len);
}
