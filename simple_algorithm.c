/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarti2 <romarti2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 11:27:26 by romarti2          #+#    #+#             */
/*   Updated: 2026/02/24 19:01:48 by romarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* int simple_algorithm (char *stacka)

 Pasos para replicar el algoritmo bubble sort:

1. Primero, limpiar la cadena con split y atoi. 
2. Determinar el número de índice del array (número de números que hay).
3. Hacer rondas de repaso del array.
    2.1 En la primera ronda, el número más alto, llegará al fina del índice del array, será su posición correcta. 
    2.2 En sucesivas rondas, habrá que recorrer el array len - i (i++) veces. Cada vez que lo recorremos, se 
    va ajustando la "última posición" del recorrido.
4. El máximo de veces a recorrer el string será índice del string -1.
*/

#include "push_swap.h"
/*
int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}*/

int	find_min(t_stack *stack)
{
	node	*current;
	int		min;
	int		i;

	if (!stack || stack->size == 0)
		return (0); 
	current = stack->front;
	min = current->dato;
	i = 0;
	while (i < stack->size && current->dato != NULL)
	{
		if (current->dato < min) // la primera vez no se cumple porque el dato va a ser el mismo, por lo que current pasa al siguiente dígito.
			min = current->dato;
		current = current->next;
		i++;
	}
	return (min);
}


void bubble_sort (t_stack *stacka) // Voy a pasar el menor al stack B
{
	t_stack *stackb;
	node *firsta;
	node *seconda;

	stackb = malloc(sizeof(t_stack));
	stackb -> front = NULL;
	stackb -> last = NULL;
	stackb -> size = 0;
	firsta = stacka -> front;
	seconda = firsta -> next;
	pb (*stacka, *stackb);
	while ((stacka->size) > 0)
	{
		if ((firsta->dato) > (seconda->dato)) 
			sa(stacka);
		else	
			pb(stacka, stackb);
	}	
}

/*
void bubble_sort (t_list *stack)
{
    int i;
    int j;
    int tmp;
    int len;

    len = ft_lstsize (stack);
    while (len > 0)
    {
        i = 0;
        j = i + 1;
        while (j < len) // Hay que cambiarlo para listas
        {
            if ((stack->content) > (stack -> next->content))
            {
              tmp = stack -> content;
              (stack -> content) = (stack -> next -> content)
              (stack -> next -> content) = tmp;
            }
            i++;
        }
        len--;
    } 
    return(stack);
}

int	ft_strlen(char const *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*s2;
	int		i;

	i = 0;
	s2 = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!s2)
		return (NULL);
	while (s[i] != '\0')
	{
		s2[i] = s[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

t_list	*ft_lstnew(void *content)
{
	t_list	*l;

	l = malloc(sizeof(t_list));
	if (!l)
		return (NULL);
	l->content = content;
	l->next = NULL;
	return (l);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (*lst == NULL)
	{
		*lst = new;
	}
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
}

int	main(void)
{
	t_list	*first;
	t_list  *temp;
	t_list  *new;

	first = malloc(sizeof(t_list));
	first -> next = malloc(sizeof(t_list));
	first -> next -> next = malloc(sizeof(t_list));
	first -> next -> next -> next = malloc(sizeof(t_list));
	first -> next -> next -> next -> next = NULL;

	first -> content = ft_strdup("2");
	first -> next -> content = ft_strdup("1");
	first -> next -> next -> content = ft_strdup("5");
	first -> next -> next -> next -> content = ft_strdup("3");

	new = ft_lstnew ("4");

	ft_lstadd_back(&first, new);

	temp = first;
	while (temp)
	{
		printf("%s\n", (int *)temp-> content);
		temp = temp->next;
	}
		return (0);
}  