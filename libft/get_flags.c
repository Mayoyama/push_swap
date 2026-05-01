/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thours <thours@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 13:20:59 by username          #+#    #+#             */
/*   Updated: 2026/04/30 13:28:52 by thours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*	initialize_flags : dynamically alocate a t_flags struct and initialize
each value at 0
*
*	create_flag_struct : Initialize a flag struct and call the get_params
function
*
*	get_params : parse the expression and extract in the structure flags
*	and parameters
*		-> First search for the flags ('-', '0', '#', ' ', '+')
*		-> then search for the width and precision parameters
*		-> each time a flag or parameter is detected, it respective
*			value is set to 1
*
*	get_flag : detect what flag has been parsed and set it
*	respective value to 1
*/

#include "libft.h"

t_flags	*initialize_flags(void)
{
	t_flags	*flags;

	flags = malloc(sizeof(t_flags));
	if (!flags)
		return (NULL);
	flags->aff_left = 0;
	flags->fill_zero = 0;
	flags->aff_sign = 0;
	flags->spc_for_pos = 0;
	flags->prefix = 0;
	flags->precision = -1;
	flags->width = -1;
	flags->sign_written = 0;
	return (flags);
}

t_flags	*create_flag_struct(char *str)
{
	t_flags	*flags;

	flags = initialize_flags();
	if (!flags)
		return (NULL);
	flags = get_params(flags, str);
	return (flags);
}

static t_flags	*get_width_and_prec(t_flags *flags, char *str)
{
	int	i;

	i = 0;
	while (str[i] && is_param(str[i]) && !is_flag(str[i]))
	{
		if (str[i] == '.' && str[i + 1])
		{
			i++;
			if (ft_isdigit(str[i]))
				flags->precision = ft_atoi(&str[i]);
			else
				flags->precision = 0;
			while (str[i] && ft_isdigit(str[i]))
				i++;
		}
		if (ft_isdigit(str[i]))
		{
			flags->width = ft_atoi(&str[i]);
			while (str[i] && ft_isdigit(str[i]))
				i++;
		}
		else
			i++;
	}
	return (flags);
}

t_flags	*get_params(t_flags *flags, char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && is_flag(str[i]))
		flags = get_flag(flags, str[i++]);
	flags = get_width_and_prec(flags, &str[i]);
	return (flags);
}

t_flags	*get_flag(t_flags *flags, char c)
{
	if (c == '-')
		flags->aff_left = 1;
	if (c == '0')
		flags->fill_zero = 1;
	if (c == '+')
		flags->aff_sign = 1;
	if (c == ' ')
		flags->spc_for_pos = 1;
	if (c == '#')
		flags->prefix = 1;
	return (flags);
}
