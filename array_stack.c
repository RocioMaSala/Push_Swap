/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarti2 <romarti2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 16:19:58 by romarti2          #+#    #+#             */
/*   Updated: 2026/02/24 17:12:40 by romarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Aquí deberíamos meter la limpieza del array de entrada hasta la pila.

t_stack array_stack (int *ar) // Función para insertar array en pila a.
{
    t_stack stacka;
    int i;
    
    while (!ar)
    {
        push(stacka, ar[i]);   
    }
    return (stacka);
}  