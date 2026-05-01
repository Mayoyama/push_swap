/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thours <thours@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 18:46:11 by thours            #+#    #+#             */
/*   Updated: 2026/05/01 21:31:52 by thours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../push_swap.h"

int	check_input(int argc, char **argv)
{
	int	i;
	if (argc > 1)
	{
		i = 1;
		while (argv[i])
		{
			if (!is_parameter(argv[i]) && !is_valid_list(argv[i]))
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

/*
 *	On the first loop : Check if the numbers are correctly written (Only spaces,
 *	signs and numbers, if there is a sign, detect if there is a number
 *	directly after)
 *	On the second loop : Check if each number can fit in an int
*/
int	is_valid_list(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if ((argv[i] == '-' || argv[i] == '+') && ft_isdigit(argv[i + 1]))
			i++;
		if (!ft_isdigit(argv[i]) && !ft_isspace(argv[i]))
			return (0);
		i++;
	}
	i = 0;
	while (argv[i])
	{
		while (ft_isspace(argv[i]))
			i++;
		if (argv[i] == '-' || argv[i] == '+' || ft_isdigit(argv[i]))
		{
			if (!is_valid_int(&argv[i]))
				return (0);
			while (argv[i] == '-' || argv[i] == '+' || ft_isdigit(argv[i]))
				i++;
		}
	}
	return (1);
}

/*
 *	Helper for ft_atoi_long function, return the number (long) and check if it
 *	can fit in an int.
 *	Error cases -> If there is more than 10 chars (INT_MAX and MIN length)
 *				-> If there is 10 chars and first one is above 3
 *					(These two if statements check if it can fit in a
 *					long (between 3 000 000 000 and -3 000 000 000))
 *				-> If it fits in a long but is above INT_MAX or under INT_MIN
*/
static long extract_num(char *nptr, int sign, int *error)
{
	int		char_count;
	long	res;
	int		i;
	
	i = 0;
	char_count = 0;
	res = 0;
	while (nptr[i] && ft_isdigit(nptr[i]))
	{
		char_count++;
		if (char_count > 10)
		{
			*error = 1;
			break ;
		}
		res = res * 10 + nptr[i] - '0';
		i++;
	}
	if (char_count >= 10 && nptr[0] >= '3')
		*error = 1;
	if (res * sign > INT_MAX || res * sign < INT_MIN)
		*error = 1;
	return (res * sign);
}

long	ft_atoi_long(char *nptr, int *error)
{
	long	res;
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	res = extract_num(&nptr[i], sign, error);
	return (res);
}

int	is_valid_int(char *str)
{
	int	error;

	error = 0;
	ft_atoi_long(str, &error);
	if (error == 1)
		return (0);
	return (1);
}
