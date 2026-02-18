/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarti2 <romarti2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 16:56:00 by romarti2          #+#    #+#             */
/*   Updated: 2026/02/18 18:20:29 by romarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h> // Para malloc y free
# include <unistd.h>
# include <stddef.h> // Para size_t y NULL

/*typedef struct stack
{
    int val;
    struct _stack *next;
}				stacka;*/

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;


int						ft_lstsize(t_list *lst);
void 					bubble_sort (t_list *stack);
int						ft_strlen(char const *str);
char					*ft_strdup(const char *s);
t_list				*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new);


#endif
