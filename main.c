#include "push_swap.h"

void	error_exit(t_stack *a, t_stack *b)
{
	free_stack(a);
	free_stack(b);
	write(2, "Error\n", 6);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	char	*forced_algo;
	int		offset;

	if (argc < 2)
		return (0);
	initializer_stack(&a);
	initializer_stack(&b);
	forced_algo = NULL;
	offset = 1;
	if (argv[1][0] == '-' && argv[1][1] == '-')
	{
		forced_algo = argv[1];
		offset = 2;
	}
	parse_to_stack(argc - offset + 1, &argv[offset - 1], &a);
	if (a.size > 1)
	{
		assign_index(&a);
		adaptive_algorithm(&a, &b, forced_algo);
	}
	free_stack(&a);
	free_stack(&b);
	return (0);
}
