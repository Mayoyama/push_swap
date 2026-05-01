/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_int_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thours <thours@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 16:44:13 by thours            #+#    #+#             */
/*   Updated: 2026/04/30 13:29:30 by thours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	get_int_len : 	calculate the number of digits in an int,
 *					excluding the '-' sign if negative
 *
 *	get_int_expr_size :	return the total size of an expression
 		with the given flags
 *		-> first calculate how many digits contains the int
 *		-> Add precision if needed
 *		-> Add the sign if needed
 *		-> If size is smaller than width, size equals width
 */

int	get_int_len(int n)
{
	long	nb;
	int		len;

	nb = n;
	len = 0;
	if (nb < 0)
		nb = -nb;
	while (nb > 9)
	{
		nb /= 10;
		len++;
	}
	len++;
	return (len);
}

int	get_int_expr_size(int num, t_flags *flags)
{
	int	size;

	size = 0;
	if (!(num == 0 && flags->precision == 0))
		size = get_int_len(num);
	if (flags->precision >= flags->width && flags->precision > size)
		size = flags->precision;
	if (num < 0 || flags->aff_sign || flags->spc_for_pos)
		size++;
	if (flags->width > size)
		size = flags->width;
	return (size);
}
