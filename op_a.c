
#include "push_swap.h"


int sa(t_stack *swap)
{
    t_node *first;
    t_node *second;

    if (!swap || swap -> size < 2)
        return(0);
    first = swap -> front;
    second = first -> next;// En un nodo si que hay next, pero en una pila no, por eso poner swapa -> next, no tiene sentido 
    first -> next = second -> next;
    second -> next = first;
    swap -> front = second;
    return (1);
}

int pa(t_stack *pusha, t_stack *pushb)
{
    t_node *firsta;
    t_node *firstb;

    if (!pushb)
        return (0);
    firstb = pushb -> front;
    pushb -> front = firstb -> next; 
    firstb -> next = pusha-> front;
    pusha-> front = firstb;
    return (1);
       
}

int ra(t_stack *rotate)
{
    t_node *last;
    t_node *first;
    t_node *second;

    if (!rotate)
        return (0);
    first = rotate -> front;
    second = first -> next;
    last = rotate -> front;
    rotate -> front = second;
    while (last->next != NULL)
         last = last -> next;
    last -> next = first;
    first -> next = NULL;
    return (1);
}

int rra(t_stack *rr) 
{
    t_node *last;
    t_node *prev; // Para gestionar el antepenúltimo

    prev = NULL;
    last = rr -> front;
    while (last->next != NULL)
    {
        prev = last;
        last = last -> next;
    }    
    prev -> next = NULL;
    last -> next = rr -> front;
    rr -> front = last;
    return (1);
}