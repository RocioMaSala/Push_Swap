/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarti2 <romarti2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 16:59:37 by romarti2          #+#    #+#             */
/*   Updated: 2026/02/24 16:31:34 by romarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void initializer_stack(stack *a)
{
    s -> front = NULL;
    s -> size = 0;
}
void initializer_stack(stack *b)
{
    s -> front = NULL;
    s -> size = 0;
}

int isempty (stack *verify)
{
    if (verify->front = NULL)
        return (1);
    return (0);
}

int push (stack *add, int x)
{
    node *new;
    
    new = malloc(sizeof(node));
    if (!new)
        return(0)
    new -> dato = x;
    new -> next = add -> front;
    add -> front = new;
    add -> size++;
    return (1);    
}


int peek(stack *top) // Para saber qué nodo está en el top de la lista 
{
    if (!top || top->front == NULL)
        return 0;
    return (top->front->data);  
}


int pop (stack *delete) // Elimina y devuelve el elemento encima pila
{ 
    node *tmp;
    int datatemp;
    
    if(!delete ||delete->front == NULL) // Comprobar que la lista no esté vacía
        return (0);
    tmp = delete->front;
    datatemp = delete->front->dato;
    delete->front = tmp->next;
    free (tmp);
    delete -> size--; 
    return (datatemp);
}


int swap (stack *swap)
{
    node *first;
    node *second;

    if (!swap || swap -> size < 2)
        return(0);
    first = swap -> front;
    second = first -> next;// En un nodo si que hay next, pero en una pila no, por eso poner swapa -> next, no tiene sentido 
    first -> next = second -> next;
    second -> next = first;
    swap -> front = second;
    return (1);
}

int pushab(stack *pusha, stack *pushb)
{
    node *firsta;
    node *firstb;

    if (!pushb)
        return (0);
    firstb = pushb -> front;
    pushb -> front = firstb -> next; 
    firstb -> next = pusha-> front;
    pusha-> front = firstb;
    return (1);
       
}

int rotate(stack *rotate)
{
    node *last;
    node *first;
    node *second;

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

int reverse_rotate(stack *rr) 
{
    node *last;
    node *prev; // Para gestionar el antepenúltimo

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

node *new_node(int dato)
{
    node *n;
    
    n = malloc(sizeof(node));
    if (!n)
        return (NULL);
    n->dato = dato;
    n->next = NULL;
    return (n);
}

void add_back(stack *s, int dato)
{
    node *n = new_node(dato);
    node *tmp;

    if (!s->front)
        s->front = n;
    else
    {
        tmp = s->front;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = n;
    }
    s->size++;
}

void print_stack(stack *s)
{
    node *tmp = s->front;

    while (tmp)
    {
        printf("%d ", tmp->dato);
        tmp = tmp->next;
    }
    printf("\n");
}
// ---------- MAIN ----------

int main(void)
{
    stack a;
    stack b;

    a.front = NULL;
    a.size = 0;
    b.front = NULL;
    b.size = 0;

    add_back(&a, 10);
    add_back(&a, 20);
    add_back(&a, 30);
    add_back(&a, 40);
    add_back(&b, 50);
    add_back(&b, 60);
    add_back(&b, 70);

    printf("Antes:\n");
    print_stack(&a);
    print_stack(&b); 

    reverse_rotate(&a);

    printf("Después:\n");
    print_stack(&a);
    print_stack(&b);

    return (0);
}

