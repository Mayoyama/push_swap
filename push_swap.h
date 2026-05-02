/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thours <thours@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 15:58:26 by thours            #+#    #+#             */
/*   Updated: 2026/05/02 19:09:27 by thours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <limits.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

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
	double	disorder;
}	t_input;

typedef struct s_stack
{
	t_node	*list;
	t_node	*tail;
	int		size;
}	t_stack;

/* ************************************************************************** */
/* *********************		INPUT PARSING		************************* */
/* ************************************************************************** */

/**** USER INPUT CHECKING ****/
int		check_input(int argc, char **argv);
int		is_valid_list(char *str);
long	ft_atoi_long(char *nptr, int *error);
int		is_valid_int(char *str);
int		is_parameter(char *argv);

/**** INPUT STRUCT FUNCTIONS ****/
t_input	*create_input_struct(void);
void	free_input(t_input *input);

/**** NUM STRUCT FUNCTIONS ****/
t_node	*create_num_node(int num);
void	addback_node(t_node **head, int num, int *malloc_error);
void	free_stack(t_node *head);
void	print_stack(t_node *head);
int		get_list_size(t_node *head);

/**** EXTRACT USER INPUT ****/
t_input	*extract_user_input(char **argv);
void	get_parameter(t_input *input, char *argv);
void	get_num_list(t_input *input, char *argv);
int		check_for_duplicate(t_node *head);

/**** GET INDEX AND TARGET ****/
void	get_index_and_target(t_node *list);
void	get_index(t_node *list);
void	get_target(t_node *list);

#endif
