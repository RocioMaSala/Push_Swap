void	assign_index(t_stack *a)
{
	t_node	*curr;
	t_node	*compare;
	int		index;

	if (!a || !a->front)
		return ;
	curr = a->front;
	while (curr)
	{
		index = 0;
		compare = a->front;
		while (compare)
		{
			if (curr->dato > compare->dato)
				index++;
			compare = compare->next;
		}
		curr->index = index;
		curr = curr->next;
	}
}


int	get_range(t_stack *s)
{
	if (s->size <= 100)
		return (15);
	return (35);
}


int	get_max_index_pos(t_stack *b)
{
	t_node	*tmp;
	int		max_idx;
	int		pos;
	int		i;

	tmp = b->front;
	max_idx = -1;
	pos = 0;
	i = 0;
	while (tmp)
	{
		if (tmp->index > max_idx)
		{
			max_idx = tmp->index;
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (pos);
}

void	push_back_to_a(t_stack *a, t_stack *b)
{
	int	max_pos;
	int	size_b;

	while (b->size > 0)
	{
		max_pos = get_max_index_pos(b);
		size_b = b->size;
		if (max_pos <= size_b / 2)
		{
			while (max_pos-- > 0)
				rb(b);
		}
		else
		{
			max_pos = size_b - max_pos;
			while (max_pos-- > 0)
				rrb(b);
		}
		pa(a, b);
	}
}



void	push_to_b_chunks(t_stack *a, t_stack *b)