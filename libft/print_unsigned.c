/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thours <thours@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 13:45:32 by thours            #+#    #+#             */
/*   Updated: 2026/04/30 13:36:13 by thours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* fill_left : fill the start of expression with spaces if width is larger
*	than the expression
*
* print_unsigned_num : print the number
*              -> if there is a precision greater than len of number, print "0"
*
* fill_right : if "-" flag is detected, print spaces at the end of
*	expression if needed
*
* print_unsigned_int : print the full expression with given flags
*/

#include "libft.h"

static void	fill_left(unsigned int num, int len, t_flags *flags)
{
	int		num_len;
	char	c;

	if (flags->aff_left)
		return ;
	num_len = 0;
	if (!(num == 0 && flags->precision == 0))
		num_len = get_unsigned_int_len(num);
	if (num_len < flags->precision)
		num_len = flags->precision;
	if (flags->fill_zero)
		c = '0';
	else
		c = ' ';
	while (num_len < len)
	{
		write(1, &c, 1);
		num_len++;
	}
}

static void	print_unsigned_num(unsigned int num, t_flags *flags)
{
	int	num_len;

	num_len = get_unsigned_int_len(num);
	while (num_len < flags->precision)
	{
		write(1, "0", 1);
		num_len++;
	}
	ft_putnbr_unsigned(num);
}

static void	fill_right(unsigned int num, int len, t_flags *flags)
{
	int	num_len;

	if (!flags->aff_left)
		return ;
	num_len = 0;
	if (!(num == 0 && flags->precision == 0))
		num_len = get_unsigned_int_len(num);
	if (num_len < flags->precision)
		num_len = flags->precision;
	while (num_len < len)
	{
		write(1, " ", 1);
		num_len++;
	}
}

int	print_unsigned_int(unsigned int num, t_flags *flags)
{
	int	len;

	len = get_unsigned_expr_size(num, flags);
	fill_left(num, len, flags);
	if (!(num == 0 && flags->precision == 0))
		print_unsigned_num(num, flags);
	fill_right(num, len, flags);
	return (len);
}
