/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thours <thours@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 15:58:26 by thours            #+#    #+#             */
/*   Updated: 2026/05/04 20:54:16 by thours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

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
}							t_node;

typedef enum e_mod
{
	NONE,
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTATIVE,
}				t_mod;

// Keeps track of push operation usage counts
typedef struct s_opcount
{
	int	pa;
	int	pb;
	int	sa;
	int	sb;
	int	ss;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	total_ops;
}				t_opcount;

typedef struct s_input
{
	t_node		*list;
	int			size;
	t_mod		mod;
	int			bench_mod;
	t_opcount	*op_counts;
	double		disorder;
}	t_input;

typedef struct s_stack
{
	t_node			*list;
	t_node			*tail;
	int				size;
	struct s_stack	*twin_stack;
}				t_stack;

/* ************************************************************************** */
/* *********************		INPUT PARSING		************************* */
/* ************************************************************************** */

/**** USER INPUT CHECKING ****/
int			check_input(int argc, char **argv);
int			is_valid_list(char *str);
long		ft_atoi_long(char *nptr, int *error);
int			is_valid_int(char *str);
int			is_parameter(char *argv);

/**** INPUT STRUCT FUNCTIONS ****/
t_input		*create_input_struct(void);
t_opcount	*create_opcounts_struct(void);
void		free_input(t_input *input);

/**** NUM STRUCT FUNCTIONS ****/
t_node		*create_num_node(int num);
void		addback_node(t_node **head, int num, int *malloc_error);
void		free_stack(t_node *head);
void		print_stack(t_node *head);
int			get_list_size(t_node *head);

/**** EXTRACT USER INPUT ****/
t_input		*extract_user_input(char **argv);
void		get_parameter(t_input *input, char *argv);
void		get_num_list(t_input *input, char *argv);
int			check_for_duplicate(t_node *head);

/**** GET INDEX AND TARGET ****/
void		get_index(t_node *list);

/**** DISORDER CHECKER ****/
double		compute_disorder(t_node *lst);

/* ************************************************************************** */
/* *********************			MODES			************************* */
/* ************************************************************************** */

void		adaptive_modeset(t_input *input, t_stack *a, t_stack *b);

void		start_complex_mode(t_input *input);
void		set_radix_index(t_node *head);
int			get_max_bitsize(int size);
void		radix(t_input *input, t_stack *a, t_stack *b);
void		mem_cleanup(t_input *input, t_stack *a, t_stack *b);
int			is_sorted(t_stack *a);

void		benchmark_mode(t_input *input);

/* ************************************************************************** */
/* *********************	  PUSH OPERATIONS		************************* */
/* ************************************************************************** */

/**** PUSH ****/
int			push_to_dest(t_stack *dest, t_stack *src);
void		pa(t_input *input, t_stack *a, t_stack *b);
void		pb(t_input *input, t_stack *a, t_stack *b);
/**** SWAP ****/
int			swap_top_two(t_stack *stack);
void		sa(t_input *input, t_stack *a);
void		sb(t_input *input, t_stack *b);
void		ss(t_input *input, t_stack *a, t_stack *b);
/**** ROTATE ****/
int			rotate_list(t_stack *stack);
void		ra(t_input *input, t_stack *a);
void		rb(t_input *input, t_stack *b);
void		rr(t_input *input, t_stack *a, t_stack *b);
/**** REVERSE ****/
int			rev_rotate_list(t_stack *stack);
void		rra(t_input *input, t_stack *a);
void		rrb(t_input *input, t_stack *b);
void		rrr(t_input *input, t_stack *a, t_stack *b);

/* ************************************************************************** */
/* *********************	 HELPER FUNCTIONS		************************* */
/* ************************************************************************** */

void		ft_putdouble_fd(double d, int fd, int decimalplaces);
void		padded_putnbr_fd(int num, int fd);

/* ************************************************************************** */
/* *********************		ALGORITHM HELPERS		********************* */
/* ************************************************************************** */

/**** CREATE STACK STRUCTURE ****/
t_stack	*create_stack_struct(t_input *input);

/**** COST CALCULATION ****/
void	calculate_cost(t_stack *stack, t_stack *target_stack);
t_node	*get_target(t_stack *stack, t_node *node);
int		get_push_cost(t_stack *target_stack, t_node *node);
void	get_cheapest(t_node *list);

/**** UTILS *****/
void	get_above_med(t_stack *a, t_stack *b);
int		algorithm_has_end(t_stack *a, t_stack *b);
t_node	*find_smallest_value(t_node *list);
int		get_pos(t_node *node, t_node *list);
int		ft_max(int a, int b);
void	reset_cost_flags(t_node *list);

/* ************************************************************************** */
/* *********************		SIMPLE ALGORITHM		********************* */
/* ************************************************************************** */

void	do_simple_algo(t_input *input);
void	run_simple_algo(t_input *input, t_stack *a, t_stack *b);
void	push_to_b(t_input *input, t_stack *a, t_stack *b, t_node *node);

/* ************************************************************************** */
/* *********************		MEDIUM ALGORITHM		********************* */
/* ************************************************************************** */

/**** MEDIUM MODE ****/
void	do_medium_algo(t_input *input);
void	run_medium_algo(t_input *input, t_stack *a);
void	run_phase_one(t_input *input, t_stack *a);

/**** MANAGE CHUNKS ****/
void	manage_chunk(t_input *input, t_stack *a, int start, int end);
int		is_in_chunk(t_node *node, int start, int end);
void	optimize_b_insertion(t_input *input, t_stack *b, int start, int end);
int		chunk_has_element_in_a(t_stack *a, int start, int end);

/**** CHUNK REINSERTION ****/
void	handle_chunk_reinsertion(t_stack *a, t_stack *b, t_input *input);
void	reinsert_chunk_node(t_stack *a, t_stack *b, t_input *input);
void	put_on_top_double(t_node *tar, t_node *node, t_stack *a, t_input *inp);
void	put_on_top_a(t_node *node, t_stack *a, t_input *inp);
void	put_on_top_b(t_node *node, t_stack *b, t_input *inp);

/**** UTILS ****/
int		get_chunk_size(t_stack *stack);
int		get_chunk_count(int chunk_size, t_stack *stack);
t_node	*find_node_index(t_node *list, int index);

#endif
