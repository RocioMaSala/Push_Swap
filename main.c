#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		return (0);
	initializer_stack(&a);
	initializer_stack(&b);
	parse_to_stack(argc, argv, &a);
	if (a.size > 1)
	{
		assign_index(&a);
		adaptive_algorithm(&a, &b);
	}
	free_stack(&a);
	free_stack(&b);
	return (0);
}
