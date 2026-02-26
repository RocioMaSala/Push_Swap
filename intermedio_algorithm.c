/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodino- <jgodino-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 16:19:58 by jgodino-          #+#    #+#             */
/*   Updated: 2026/02/23 17:12:40 by jgodino-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	find_min_pos(t_stack *s)
{
	t_node	*tmp;
	int		min_val;
	int		min_pos;
	int		i;

	if (!s || !s->front)
		return (-1);
	tmp = s->front;
	min_val = tmp->dato;
	min_pos = 0;
	i = 0;
	while (tmp)
	{
		if (tmp->dato < min_val)
		{
			min_val = tmp->dato;
			min_pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (min_pos);
}

void	intermediate_algorithm(t_stack *a, t_stack *b)
{
	int	min_pos;


	while (a->size > 3)
	{
		min_pos = find_min_pos(a);

		if (min_pos <= a->size / 2)
		{
			while (min_pos-- > 0)
				ra(a);
		}

		else
		{
			min_pos = a->size - min_pos;
			while (min_pos-- > 0)
				rra(a);
		}
		pb(a, b);
	}

	sort_three(a);

	while (b->size > 0)
		pa(a, b);
}


void	sort_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	if (a->size != 3)
		return ;
	first = a->front->dato;
	second = a->front->next->dato;
	third = a->last->dato;

	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}