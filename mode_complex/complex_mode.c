#include "../push_swap.h"

void	start_complex_mode(t_input *input)
{
	t_stack *stack_a;
	t_stack *stack_b;

	stack_a = create_stack_struct(input);
	stack_b = create_stack_struct(NULL);
	if (!stack_a || !stack_b)
	{
		write(2, "error\n", 6);
		if (stack_a)
			free(stack_a);
		if (stack_b)
			free(stack_b);
		return;
	}
	if (!is_sorted(stack_a))
	{
		set_radix_index(stack_a->list);
		radix(input, stack_a, stack_b);
	}
	///////////////////////////////////////////// DEBUGING
	ft_printf("\n");
	print_stack(stack_a->list);
	ft_printf("Total of operations: %d\n", input->op_counts->total_ops);
	/////////////////////////////////////////////
	mem_cleanup(input, stack_a, stack_b);
}

void	mem_cleanup(t_input *input, t_stack *a, t_stack *b)
{
	free_stack(a->list);
	free(a);
	free(b);
	free(input);
}

int	is_sorted(t_stack *a)
{
	t_node	*temp;

	temp = a->list;
	while (temp && temp->next)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	set_radix_index(t_node *head)
{
	t_node	*current;
	t_node	*comparison;
	int		rank;

	current = head;
	while (current)
	{
		comparison = head;
		rank = 0;
		while (comparison)
		{
			if (current->value < comparison->value)
				rank++;
			comparison = comparison->next;
		}
		current->index = rank;
		current = current->next;
	}
}

int	get_max_bitsize(int size)
{
	int	bits;
	int n;

	bits = 0;
	n = size -1;
	while (n > 0)
	{
		n /= 2;
		bits++;
	}
	return (bits);
}

//input → stack A → (radix distribution) → stack B → (Turk reconstruction) → sorted A
void	radix(t_input *input, t_stack *a, t_stack *b)
{
	int	bit;
	int	bitsize;
	int size;

	bit = 0;
	bitsize = get_max_bitsize(input->size);

	while (bit < bitsize)
	{
		size = input->size;
		while (size--)
		{
			if (((a->list->index >> bit) & 1) == 0)
				pb(input, a, b);
			else
				ra(input, a);
		}
		while (b->size > 0)
			pa(input, a, b);
		bit++;
	}
}