This project has been created as part of the 42 curriculum by ealiman, mcalleja

# push_swap
This program take a set of integers values and sort them by ascending order using 4 specifc strategy based on the disorder.

## Description
We have a set of integers,  stack and a set of operations to manipulate both stacks.
The calculates and displays on the
standard output the smallest program, made of Push swap language operations, that
sorts the integers received as arguments.

## Instructions
To run the program type in the bash:
```bash
make
./push_swap [--simple | --medium | --complex | --adaptive] [--bench] numeri...
```
example:
```bash
./push_swap 3 1 2 5 4
./push_swap --complex 5 4 3 2 1
./push_swap --bench --adaptive 42 7 -3 15 0
ARG="4 67 3 87 23"; ./push_swap --adaptive $ARG | ./checker_linux $ARG
```

## Resources
- https://www.geeksforgeeks.org/c/implement-stack-in-c/
- https://www.geeksforgeeks.org/dsa/implement-a-stack-using-singly-linked-list/

## Architettura del progetto
- push_swap.c -> definition, structure, prototype
- main.c -> parsing, validation, orchestration
- stack.c -> double linked list and primitive operations
- stack_operations -> normal operations on stack
- operations_* -> every possible moves possible to sort numbers in ascending orders
- normalize.c -> normalization of the ranks(alias index of the numbers)
- disorder.c -> calculating how much the orders of the numbers are messed up
- sort_simple.c -> minimum cost selection
- sort_medium.c -> chunk selection
- sort_complex.c -> radix sort LSD
- sort_adaptive.c -> strategy selection based on disorder
- cost.c -> calculus of minimum rotations and paralles moves
- bench.c -> statistics printing
- utils_* -> support functions

## Data structure
The stack has:
- a pointer to the top of the stack, the only accessible point
- a ponter for the bottom of the stack
- the current dimension of the stack (`size`)

## Operations
- sa (swap a): Swap the first two elements at the top of stack a.
Do nothing if there is only one or no elements.
- sb (swap b): Swap the first two elements at the top of stack b.
Do nothing if there is only one or no elements.
- ss : sa and sb at the same time.
- pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.
- pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.
- ra (rotate a): Shift up all elements of stack a by one.
The first element becomes the last one.
- rb (rotate b): Shift up all elements of stack b by one.
The first element becomes the last one.
- rr : ra and rb at the same time.
- rra (reverse rotate a): Shift down all elements of stack a by one.
The last element becomes the first one.
- rrb (reverse rotate b): Shift down all elements of stack b by one.
The last element becomes the first one.
- rrr : rra and rrb at the same time

## Normalization
Before any sorting operation the value are converted in rank from 0 to n-1. The 0 rank  is assigned to the min value and n-1 to the max. This make the algorithm indipendent from the input value.
We copy the value in a temporaty array, then sort the array from min to max. Then we assign the rank to every node serching its value in the sorted array.

We have choose a double linked list because rotation and reverse rotation (`ra`, `rra`) cost O(1) no matter the size we just need to modify three pointer. Every node has 4 fields:
- value
- normalized rank
- pointer to the upper node (`next`)
- pointer to the bottom node (`prev`)

## The 4 strategies

### Simple O(n²)
At every turn find the element of stack `a` that cost less to move to stack `b`, considering parallel rotation with `rr` and `rrr`, Reapeat until emptying `a`, then recreate it extracting the max elements from `b`.

**Implementation**:
For each element in `a`, calculate the cost as the sum of the rotations required in `a` and `b`, taking advantage of double rotations when the directions match. Select the element with the lowest cost.

Every elements is moved to `b` then moved back to `a`.

### Medium O(n·√n)
Divide ranks in √n chunk of the size of √n. Move to `b` one chunk at time keeping the chunk max at the top. Then recreate `a` extracting the max in order from `b`.

**Implementation**: for each chunk, it scans `a` using `ra` looking for elements within the range `[chunk_min, chunk_max]`. Each element found is moved to `b` using `pb`, followed by `rb` if it is smaller than the node below it (to keep the largest elements on top). Phase 2 finds the absolute maximum of `b` and moves it to `a` using `pa`.

### Complex O(n·log n)
Using radix sort LSD to sort the ranks bit by bit starting from the less significant. In every passage the elements with bit=0 stay in `a` (rotated at the bottom), those with bit=1 goes to `b`.
At the end of every passaghe everything comeback to `a`.

**Implementation**: calculates the number of bits needed as ⌈log₂(n)⌉. For each bit, it scans all n elements of `a`: `(node->rank >> bit) & 1 == 1` → `pb`, otherwise `ra`. Then `pa` is repeated until `b` is empty.

### Adaptive
Measures the disorder of the initial configuration and selects the most efficient strategy for that level of disorder.

**Disorder metric**: ratio between inverted pairs and total pairs. A pair (i, j) is inverted if i appears before j in the stack but `rank[i] > rank[j]`. The value is 0 for a sorted input and 1 for the worst case.

**Thresholds and rationale**:
`disorder < 0.2` → **Simple O(n²)**
With less than 20% inverted pairs, most elements are already close to their final positions. The simple sort finds the minima with few rotations — its actual cost drops to O(n · disorder · n) = O(0.2 · n²), competitive with radix sort which still performs all passes. The experimental break‑even is around 18–22% disorder.

`0.2 ≤ disorder < 0.5` → **Medium O(n·√n)**
The distribution is uniform enough to fill the chunks in a balanced way. Simple sort degrades because the minima are buried, but radix sort wastes moves on bits that are already "almost sorted". Medium is the optimal trade‑off in this range.

`disorder ≥ 0.5` → **Complex O(n·log n)**
Above 50% inversions, the list is essentially random. Radix sort is the only one that guarantees O(n·log n) regardless of distribution. Simple and medium approaches approach their worst‑case behavior.

## Performance Test
```
Strategia   | n=100 media | n=500 media | target
------------|-------------|-------------|--------
simple      |     XXX     |    XXXXX    |
medium      |     XXX     |    XXXXX    |
complex     |     XXX     |    XXXXX    | <700 / <5500
adaptive    |     XXX     |    XXXXX    | eccellente
```

## Error Management
- Non-integer arguments
- Integer overflow (values outside [-2147483648, 2147483647])
- Duplicates
- Unrecognized flags

All produce `"Error\n"` on stderr and terminate with `exit(1)`.

## How AI was used
During this project, an AI assistant (DeepSeek) was used for the following tasks:

- Code debugging: understanding segmentation faults, memory leaks, and pointer errors.
- Explaining tricky concepts: function pointers, static keyword, header guards, and Makefile syntax.
- Reviewing logic: checking edge cases (empty strings, NULL parameters, allocation failures).

No code was copied directly from AI sources. Every line of code was written, understood, and tested manually.