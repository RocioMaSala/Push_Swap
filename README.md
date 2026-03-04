*This project has been created as part of the 42 curriculum by romarti2 and jgodino-.*

Work carried out as a team, with an equal contribution from each member.

# Push_Swap - Project
## Description

Project from 42 consisting of sorting a list of integers using two stacks and a limited set of operations. The main objective is to optimize the number of movements, prioritizing algorithmic efficiency.

The program receives a list of integers as arguments and outputs to the standard output the sequence of instructions required to sort them in ascending order.

## Stack Operations

sa / sb — swap the first two elements.

ss — simultaneous swap.

pa / pb — push between stacks.

ra / rb — rotate.

rr — simultaneous rotate.

rra / rrb — reverse rotate.

rrr — simultaneous reverse rotate.

## Algorithms Used

### 1. Simple Case: Bubble Sort

Time Complexity: O(n²)

Simple implementation with full control over swaps.

Ideal for very small lists where the overhead of more complex algorithms is not justified.

Allows quick detection of whether the stack is already sorted.

### 2. Intermediate Case: Sort_Three

Time Complexity: O(n √n)

Only 6 possible combinations exist.

Achieves the minimum number of movements.

Avoids unnecessary logic.

The relative positions are directly analyzed, and optimal combinations of sa, ra, and rra are applied.

This approach guarantees maximum efficiency for the most common small evaluation case.

### 3. Complex Case: KSort

Time Complexity: O(n log n)

K Sort is an algorithm based on:

Strategic division into ranges (dynamic chunks).

Progressive pushing to stack B.

Ordered reconstruction back to stack A.

## Instructions

To compile and use the program:

Clone the repository.

Compile the program using the make command.

Execute it with the desired arguments.

Clean temporary files using make fclean.

## Resources

Algorithm visualizers

Harvard University – CS50: https://cs50.harvard.edu/x/weeks/5/

Stack Overflow: https://stackoverflow.com/

Internal C manuals

University manuals

Peer-to-peer guidance

### Use of AI

For this project, AI was used as a support tool to explain complex C concepts.