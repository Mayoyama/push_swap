/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_expression.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thours <thours@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 16:26:57 by username          #+#    #+#             */
/*   Updated: 2026/04/30 13:34:14 by thours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	parse_str(const char *str, va_list *ap)
{
	int		i;
	int		count;
	t_flags	*flags;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] && str[i + 1] != '%')
		{
			flags = create_flag_struct((char *) & str[++i]);
			while (str[i] && !is_conversion(str[i - 1]))
				i++;
			count += handle_arg(str[i - 1], flags, ap);
			free(flags);
		}
		else if (str[i] == '%' && str[i + 1] == '%')
		{
			count += write(1, "%", 1);
			i += 2;
		}
		else
			count += write(1, &str[i++], 1);
	}
	return (count);
}

int	handle_arg(char c, t_flags *flags, va_list *ap)
{
	if (c == 'c')
		return (print_char((char) va_arg(*ap, int), flags));
	if (c == 's')
		return (print_str(va_arg(*ap, char *), flags));
	if (c == 'p')
		return (print_mem(va_arg(*ap, void *), flags));
	if (c == 'd' || c == 'i')
		return (print_int(va_arg(*ap, int), flags));
	if (c == 'u')
		return (print_unsigned_int(va_arg(*ap, unsigned int), flags));
	if (c == 'x')
		return (print_hexa(va_arg(*ap, unsigned int), flags, 0));
	if (c == 'X')
		return (print_hexa(va_arg(*ap, unsigned int), flags, 1));
	else
		return (0);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	ap;

	if (!str)
		return (0);
	va_start(ap, str);
	count = parse_str(str, &ap);
	va_end(ap);
	return (count);
}
