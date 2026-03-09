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

## Algorithms Used - Sorting Strategy

The program implements different sorting strategies depending on the size of the input set. This approach minimizes the number of operations within the push_swap model by using specialized algorithms for small inputs and more scalable algorithms for larger datasets.

### Simple Algorithm

This algorithm is used for small or medium-sized inputs.

First, the values are normalized using assign_index, assigning each element an index corresponding to its position in the sorted order.

Then, elements are moved from stack_a to stack_b using a fixed chunk strategy:

16 if n ≤ 100

35 if n > 100

Elements are pushed to stack_b depending on their index relative to the current range. Once all elements have been processed, stack_a is reconstructed by pushing elements back from stack_b in sorted order.

Time Complexity: Approximately O(n²) due to the rotations required to locate elements.

### Medium Algorithm

The medium algorithm is a variation of the chunk-based strategy but with dynamic chunk sizes.

The chunk size is defined as:

√n 

Using √n helps balance the number of rotations and the distribution of elements in stack_b, improving performance for larger inputs.

The rest of the process is similar to the simple algorithm.

Time Complexity: Approximately O(n sqrt n).

### Complex Algorithm

For large datasets, the program uses a binary Radix Sort adapted to the push_swap operation model.

After normalizing the values with assign_index, the algorithm processes the bits of the indices from the least significant bit to the most significant one.

For each bit:

if the bit is 1 → rotate stack_a (ra)

if the bit is 0 → push the element to stack_b (pb)

After processing all elements for a given bit, the elements stored in stack_b are pushed back to stack_a using pa.

This process is repeated for all bits required to represent the maximum index.

Time Complexity: O(n log n)

### Threshold Justification

The chunk sizes (15, 35, and √n) were chosen to balance:

the number of rotations required

the distribution of elements in stack_b

the total number of operations produced

Chunks that are too small cause excessive rotations in stack_a, while chunks that are too large lead to poor distribution in stack_b.

Using √n in the medium algorithm provides a scalable heuristic that adapts the chunk size to the input size, keeping the number of operations within efficient limits for the project.

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