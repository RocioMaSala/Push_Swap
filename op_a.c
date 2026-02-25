
#include "push_swap.h"

int sa(t_stack *a)
{
    t_node *first;
    t_node *second;

    if (!a || a -> size < 2)
        return(0);
    first = a -> front;
    second = first -> next;// En un nodo si que hay next, pero en una pila no, por eso poner swapa -> next, no tiene sentido 
    first -> next = second -> next;
    second -> next = first;
    a -> front = second;
    write(1, "sa\n", 3);
    return (1);
}

int pa(t_stack *a, t_stack *b) // Diferente versión José y yo. Me gusta más la mía (Ro).
{
    t_node *firsta;
    t_node *firstb;

    if (!b || b->size == 0 || !b -> front)
        return (0);
    firstb = b -> front;
    b -> front = firstb -> next; 
    firstb -> next = a-> front;
    a-> front = firstb;
    write(1, "pa\n", 3);
    return (1);
       
}

int ra(t_stack *a)
{
    t_node *last;
    t_node *first;
    t_node *second;

    if (!a)
        return (0);
    first = a -> front;
    second = first -> next;
    last = a -> front;
    a -> front = second;
    while (last->next != NULL)
         last = last -> next;
    last -> next = first;
    first -> next = NULL;
    write(1, "ra\n", 3);
    return (1);
}

int rra(t_stack *a) 
{
    t_node *last;
    t_node *prev; // Para gestionar el antepenúltimo

    prev = NULL;
    last = a -> front;
    while (last->next != NULL)
    {
        prev = last;
        last = last -> next;
    }    
    prev -> next = NULL;
    last -> next = a -> front;
    a -> front = last;
    write(1, "rra\n", 4);
    return (1);
}
