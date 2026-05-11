#ifndef CHECKER_H
# define CHECKER_H

void	start_checker(t_input *input);
void	execute_operations(t_input *inp, t_stack *a, t_stack *b);
int		handle_line(char *line, t_input *inp, t_stack *a, t_stack *b);
void	checker_pa(t_input *input, t_stack *a, t_stack *b);
void	checker_pb(t_input *input, t_stack *a, t_stack *b);
void	checker_rra(t_input *input, t_stack *a);
void	checker_rrb(t_input *input, t_stack *b);
void	checker_rrr(t_input *input, t_stack *a, t_stack *b);
void	checker_ra(t_input *input, t_stack *a);
void	checker_rb(t_input *input, t_stack *b);
void	checker_rr(t_input *input, t_stack *a, t_stack *b);
void	checker_sa(t_input *input, t_stack *a);
void	checker_sb(t_input *input, t_stack *b);
void	checker_ss(t_input *input, t_stack *a, t_stack *b);

#endif