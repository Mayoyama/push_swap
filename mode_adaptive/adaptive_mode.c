#include "../push_swap.h"

void	adaptive_modeset(t_input *input, t_stack *a, t_stack *b)
{

	input->disorder = compute_disorder(input->list);
	if (input->disorder < 0.2)
		//INSERT: Low disorder mode function here
	else if (input->disorder < 0.5)
		//INSERT: Mid disorder mode function here
	else
		//INSERT: High disorder mode function here
}

/*Low disorder: if disorder < 0.2, your chosen method must run in O(n2) time.
Medium disorder: if 0.2 ≤ disorder < 0.5, your chosen method must run in O(n√n) time.
High disorder: if disorder ≥ 0.5, your chosen method must run in O(n log n) time*/