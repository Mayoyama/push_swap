/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thours <thours@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 15:58:26 by thours            #+#    #+#             */
/*   Updated: 2026/05/01 20:39:41 by thours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <limits.h>

typedef struct s_node
{
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
	struct s_node	*target;
	int				index;
	int				above_med;
	int				push_cost;
	int				cheapest;
}	t_node;

typedef enum e_mod
{
	NONE,
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTATIVE,
}	t_mod;

typedef struct s_input
{
	t_node	*list;
	int		size;
	t_mod	mod;
	int		bench_mod;
	float	disorder;
}	t_input;

/**** USER INPUT PARSING ****/
int		check_input(int argc, char **argv);
int		is_valid_list(char *argv);
long	ft_atoi_long(char *nptr, int *error);
int		is_valid_int(char *str);
int		is_parameter(char *argv);

#endif
