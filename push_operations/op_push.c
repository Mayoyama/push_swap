#include "../push_swap.h"

void pa(t_input *a, t_input *b)
{
	t_node	*new_top_a;

	if (!b || !b->list)
		return ;
	new_top_a = b->list;
	b->list = new_top_a->next;
	if (b->list)
		b->list->prev = NULL;
	b->size--;
	new_top_a->next = a->list;
	if (a->list)
		a->list->prev = new_top_a;
	a->list = new_top_a;
	a->list->prev = NULL;
	a->size++;
	write(1, "pa\n", 3);
}

void pb(t_input *a, t_input *b)
{
	t_node *new_top_b;

	if (!a || !a->list)
		return;
	new_top_b = a->list;
	a->list = new_top_b->next;
	if (a->list)
		a->list->prev = NULL;
	a->size--;
	new_top_b->next = b->list;
	if (b->list)
		b->list->prev = new_top_b;
	b->list = new_top_b;
	b->list->prev = NULL;
	b->size++;
	write(1, "pb\n", 3);
}