/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hex_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thours <thours@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:04:24 by thours            #+#    #+#             */
/*   Updated: 2026/04/30 13:29:01 by thours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *	get_unsigned_int_len : 	calculate the number of digits in an unsigned int
 *
 *	get_unsigned_expr_size :	return the total size of an expression
 		with the given flags
 *		- first calculate how many digits contains the int
 *		- Add precision if needed
 *		- If size is smaller than width, size equals width
 */

#include "libft.h"

int	get_hexnum_len(unsigned int n)
{
	int		len;

	len = 0;
	while (n >= 16)
	{
		n /= 16;
		len++;
	}
	len++;
	return (len);
}

int	get_hex_expr_size(unsigned int num, t_flags *flags)
{
	int	size;

	size = 0;
	if (!(num == 0 && flags->precision == 0))
		size = get_hexnum_len(num);
	if (flags->precision > size)
		size = flags->precision;
	if (flags->prefix && num != 0)
		size += 2;
	if (flags->width > size)
		size = flags->width;
	return (size);
}
