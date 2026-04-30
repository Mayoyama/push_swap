/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thours <thours@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 10:44:00 by thours            #+#    #+#             */
/*   Updated: 2026/04/30 14:19:11 by thours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* fill_blank : if a width is specified and larger than the original str,
*	add spaces to fill the width
*
* manage_nul_ptr : manage the case where the pointer passed as argument is null
*      -> print "(null)", if a precision is specified and is smaller than 6
*	(size of length of "(null)"), nothing is printed
*      -> the rest of the flags are treated the same
*
* print_str : print the str pointed to by the argument with the given flags
*/

static void	fill_blank(char *str, t_flags *flags)
{
	int	len;

	len = ft_strlen_int(str);
	if (flags->precision != -1 && len > flags->precision)
		len = flags->precision;
	while (len < flags->width)
	{
		write(1, " ", 1);
		len++;
	}
}

static int	manage_nul_ptr(t_flags *flags)
{
	int	i;

	i = 0;
	if (flags->precision != -1 && flags->precision < 6 && flags->width != -1)
	{
		while (i < flags->width)
		{
			write(1, " ", 1);
			i++;
		}
		return (flags->width);
	}
	if (flags->precision != -1 && flags->precision < 6)
		return (0);
	if (!flags->aff_left)
		fill_blank("(null)", flags);
	write(1, "(null)", 6);
	if (flags->aff_left)
		fill_blank("(null)", flags);
	if (flags->width <= 6)
		return (6);
	return (flags->width);
}

static int	get_str_size(char *str, t_flags *flags)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	if (flags->precision > flags->width && flags->precision < len)
		len = flags->precision;
	if (flags->width > flags->precision && flags->width > len)
		len = flags->width;
	return (len);
}

int	print_str(char *str, t_flags *flags)
{
	int	i;

	if (!str)
		return (manage_nul_ptr(flags));
	if (!flags->aff_left)
		fill_blank(str, flags);
	i = 0;
	while (str[i] && (flags->precision == -1 || i < flags->precision))
		write(1, &str[i++], 1);
	if (flags->aff_left)
		fill_blank(str, flags);
	return (get_str_size(str, flags));
}
