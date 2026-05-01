/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thours <thours@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 13:12:34 by thours            #+#    #+#             */
/*   Updated: 2026/04/30 13:28:03 by thours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *	is_flag : Detect if the char passed as parameter is a flag for the conversion
 *
 * is_param : Detect if the char passed as parameter is a parameter
 * for the conversion
 *				-> include flags, width and precision parameters
 */

#include "libft.h"

int	is_flag(char c)
{
	return (c == '+' || c == ' ' || c == '#' || c == '0' || c == '-');
}

int	is_param(char c)
{
	return (is_flag(c) || ft_isdigit(c) || c == '.');
}

int	is_conversion(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X');
}
