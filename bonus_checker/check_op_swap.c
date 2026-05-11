#include "../push_swap.h"

void	checker_sa(t_input *input, t_stack *a)
{
	swap_top_two(a);
	input->op_counts->sa++;
	input->op_counts->total_ops++;
}

void	checker_sb(t_input *input, t_stack *b)
{
	swap_top_two(b);
	input->op_counts->sb++;
	input->op_counts->total_ops++;
}

void	checker_ss(t_input *input, t_stack *a, t_stack *b)
{
	swap_top_two(a);
	swap_top_two(b);
	input->op_counts->ss++;
	input->op_counts->total_ops++;
}
