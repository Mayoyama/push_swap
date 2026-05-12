/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thours <thours@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 19:02:21 by thours            #+#    #+#             */
/*   Updated: 2026/05/12 16:38:22 by thours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_parameter(char *argv)
{
	if (ft_strncmp(argv, "--simple", 12) == 0)
		return (1);
	if (ft_strncmp(argv, "--medium", 12) == 0)
		return (1);
	if (ft_strncmp(argv, "--complex", 12) == 0)
		return (1);
	if (ft_strncmp(argv, "--adaptive", 12) == 0)
		return (1);
	if (ft_strncmp(argv, "--bench", 12) == 0)
		return (1);
	return (0);
}
