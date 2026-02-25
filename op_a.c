
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
    write(1, "sb\n", 3)
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
    write(1, "pb\n", 3);
    return (1);
       
}
int ra(t_stack *a)
{
    t_node *first;

    if (!a || a->size < 2)
        return(0);
    first = a->front;
    a->front = first->next;
    a->front->prev = NULL;
    first->next = NULL;
    first->prev = a->last;
    a->last->next = first;
    a->last = first;
    write(1, "rb\n", 3);
    return (1);
}

int rra(t_stack *a) 
{
    t_node *last;

    if (!a || a->size < 2)
        return ;
    last = a->last;
    a->last = last->prev;
    a->last->next = NULL;
    last->prev = NULL;
    last->next = a->front;
    a->front->prev = last;
    a->front = last;
    write(1, "rrb\n", 4);
    return (1);
}