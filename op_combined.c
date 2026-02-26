void ss(t_stack *a, t_stack *b)
{
    swap_silent(a);
    swap_silent(b);
    write(1, "ss\n", 3);
}

void rr(t_stack *a, t_stack *b)
{
    rotate_silent(a);
    rotate_silent(b);
    write(1, "rr\n", 3);
}

void rrr(t_stack *a, t_stack *b)
{
    reverse_rotate_silent(a);
    reverse_rotate_silent(b);
    write(1, "rrr\n", 4);
}