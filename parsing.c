#include "push_swap.h"

static void	free_split(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	parse_to_stack(int argc, char **argv, t_stack *a)
{
	int		i;
	int		j;
	char	**temp;

	i = 1;
	while (i < argc)
	{
		temp = ft_split(argv[i], ' ');
		if (!temp)
			return ;
		j = 0;
		while (temp[j])
		{
			add_back(a, ft_atoi(temp[j]));
			j++;
		}
		free_split(temp);
		i++;
	}
}
