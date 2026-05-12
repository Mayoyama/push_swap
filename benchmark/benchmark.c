/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thours <thours@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 10:41:36 by thours            #+#    #+#             */
/*   Updated: 2026/05/12 16:36:55 by thours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft.h"

static void	bench_lineone_opcounts(t_input *input)
{
	ft_putstr_fd("sa:  ", 2);
	padded_putnbr_fd(input->op_counts->sa, 2);
	ft_putstr_fd("  sb:  ", 2);
	padded_putnbr_fd(input->op_counts->sb, 2);
	ft_putstr_fd("  ss:  ", 2);
	padded_putnbr_fd(input->op_counts->ss, 2);
	ft_putstr_fd("  pa:  ", 2);
	padded_putnbr_fd(input->op_counts->pa, 2);
	ft_putstr_fd("  pb:  ", 2);
	padded_putnbr_fd(input->op_counts->pb, 2);
}

static void	bench_linetwo_opcounts(t_input *input)
{
	ft_putstr_fd("ra:  ", 2);
	padded_putnbr_fd(input->op_counts->ra, 2);
	ft_putstr_fd("  rb:  ", 2);
	padded_putnbr_fd(input->op_counts->rb, 2);
	ft_putstr_fd("  rr:  ", 2);
	padded_putnbr_fd(input->op_counts->rr, 2);
	ft_putstr_fd("  rra:  ", 2);
	padded_putnbr_fd(input->op_counts->rra, 2);
	ft_putstr_fd("  rrb:  ", 2);
	padded_putnbr_fd(input->op_counts->rrb, 2);
	ft_putstr_fd("  rrr:  ", 2);
	padded_putnbr_fd(input->op_counts->rrr, 2);
}

static void	bench_print_strategy(t_input *input)
{
	if (input->mod == ADAPTIVE || input->mod == NONE)
	{
		if (input->disorder < 0.2)
			ft_putstr_fd("Adaptive / O(n2)\n", 2);
		else if (input->disorder < 0.5)
			ft_putstr_fd("Adaptive / O(n√n)\n", 2);
		else
			ft_putstr_fd("Adaptive / O(n log n)\n", 2);
	}
	else if (input->mod == SIMPLE)
		ft_putstr_fd("Simple / O(n2)\n", 2);
	else if (input->mod == MEDIUM)
		ft_putstr_fd("Medium / O(n√n)\n", 2);
	else if (input->mod == COMPLEX)
		ft_putstr_fd("Complex O(n log n)\n", 2);
}

void	benchmark_mode(t_input *input)
{
	ft_putstr_fd("[bench] disorder:    ", 2);
	ft_putdouble_fd(input->disorder * 100, 2, 2);
	ft_putstr_fd("%\n", 2);
	ft_putstr_fd("[bench] strategy:    ", 2);
	bench_print_strategy(input);
	ft_putstr_fd("[bench] total_ops:   ", 2);
	ft_putnbr_fd(input->op_counts->total_ops, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("[bench] ", 2);
	bench_lineone_opcounts(input);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("[bench] ", 2);
	bench_linetwo_opcounts(input);
	ft_putstr_fd("\n", 2);
}
