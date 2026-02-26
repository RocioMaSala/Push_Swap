void sb(t_stack *b) { swap_silent(b); write(1, "sb\n", 3); }
void rb(t_stack *b) { rotate_silent(b); write(1, "rb\n", 3); }
void rrb(t_stack *b) { reverse_rotate_silent(b); write(1, "rrb\n", 4); }