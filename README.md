*This project has been created as part of the 42 curriculum by thours[, speterse].*

# push_swap

## Table of Contents
1. [Description](#description)
2. [Instructions](#instructions)
3. [Program Overview](#program-overview)
4. [Features](#features)
	- [Sort Algorithms](#sort-algorithms)
	- [Strategy Selector](#strategy-selector)
	- [Benchmark Mode](#benchmark-mode)
	- [Bonus: Checker](#bonus-checker)
5. [Usage Examples](#usage-examples)
6. [Technical Choices](#technical-choices)
	- [Considerations](#considerations)
	- [Adaptive Mode: Sorting Stacks Less Than Ten Elements](#adaptive-mode-sorting-stacks-less-than-ten-elements)
	- [Simple Algorithm: Selection Sort Adaptation](#simple-algorithm-selection-sort-adaptation)
	- [Medium Algorithm: Chunk Sort Adaptation](#medium-algorithm-chunk-sort-adaptation)
	- [Complex Algorithm: Pure LSD Radix](#complex-algorithm-pure-lsd-radix)
7. [Resources](#resources)
8. [Contributions](#contributions)

## Description

The objective of this project was to write a C program which sorts integers received as arguments, using sorting algorithms of various complexities that make use of push swap language operations.

The primary goals of this project were to:

1. Learn about Big-O notation and its importance when designing code
2. Gain a deeper understanding of algorithmic complexities in a very concrete way.
3. Discover how the choice of algorithm can make the difference between efficient code and an endless scroll of operations.

[Back to top](#table-of-contents)

## Instructions

### Compilation

To compile the project and generate the static library, use:

> make

This will generate the program:

> push_swap

To compile the bonus for this project use:

> make bonus

This will generate the program:

> checker

### Available Makefile Rules

- make (all): Compile all mandatory source files and create the program
- make bonus: Compiles the bonus files
- make clean: Remove object files
- make fclean: Remove object files and program
- make re: Rebuild the program from scratch

[Back to top](#table-of-contents)

## Program Overview

- There are 2 stacks named a and b.
- At the beginning:
	- Stack `a` contains a random amount of negative and/or positive numbers without any duplicates.
	- Stack `b` is empty.
- The goal is to sort, in ascending order, numbers into stack `a`.
- The stack must be sorted using *at least* 3 separate sorting algorithms of varying complexities ($O(n^2)$, $O(n\sqrt{n})$ and $O(n \log n)$). For a more detailed explanation of each algorithm, see [Technical Choices](#technical-choices).

### Available Operations

The following operations were made available to sort the stack:

| Instruction | Description |
| :--- | :--- |
| **sa** (swap a) | Swap the first two elements at the top of stack a. Do nothing if there is only one or no elements. |
| **sb** (swap b) | Swap the first two elements at the top of stack b. Do nothing if there is only one or no elements. |
| **ss** | sa and sb at the same time. |
| **pa** (push a) | Take the first element at the top of b and put it at the top of a. Do nothing if b is empty. |
| **pb** (push b) | Take the first element at the top of a and put it at the top of b. Do nothing if a is empty. |
| **ra** (rotate a) | Shift up all elements of stack a by one. The first element becomes the last one. |
| **rb** (rotate b) | Shift up all elements of stack b by one. The first element becomes the last one. |
| **rr** | ra and rb at the same time. |
| **rra** (reverse rotate a) | Shift down all elements of stack a by one. The last element becomes the first one. |
| **rrb** (reverse rotate b) | Shift down all elements of stack b by one. The last element becomes the first one. |
| **rrr** | rra and rrb at the same time. |

[Back to top](#table-of-contents)

## Features

### Sort Algorithms

The following algorithms were implemented in this program:
- Adaptive mode sort algorithm for stacks less than 10 elements
- Selection Sort Adaptation $O(n^2)$
- Chunk sort adaptation $O(n\sqrt{n})$
- LSD Radix Adaptation $O(n \log n)$

### Strategy Selector

The following flags can be used on the command prompt at time of execution.
- -- simple: Forces the use of the $O(n^2)$ algorithm
- --medium: Forces the use of the $O(n\sqrt{n})$ algorithm
- --complex: Forces the use of the $O(n \log n)$ algorithm
- --adaptive: Forces the use of the adaptive algorithm based on disorder
- --bench: Enables the benchmark mode (see below)

**NB: Adaptive is the default behavior if no selector is given.**

### Benchmark Mode

The optional benchmark mode (--bench) displays, after sorting:
- The computed disorder (% with two decimals).
- The name of the strategy used and its theoretical complexity class.
- The total number of operations.
- The count of each operation type (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`).

The benchmark output is sent to stderr and only appears when the flag is present.

### Bonus: Checker

Checker is a program that takes the stack, as an argument, formatted
as a list of integers. If no argument is given, it stops and displays nothing.

It will read operations from the standard input, with each push_swap operation instruction, followed by `\n`. Once all the instructions have been read, the program executes them on the stack (stack `a`) received as an argument.

The following will be displayed on the standard output followed by a `\n`:
- "OK": If stack `a` is actually sorted and stack `b` is empty.
- "KO": Either stack `a` is not sorted or `b` is not completely empty.
- "Error": In case of an error. Errors include: some arguments are not integers, some arguments are bigger than an integer, there are duplicates, an instruction doesn’t exist and/or is incorrectly formatted.

[Back to top](#table-of-contents)

## Usage Examples

Below are some examples of command prompt inputs that can be used to alter the behaviour of the program:

Default selection (--adaptive):
~~~
$> ARG="4 67 3 87 23"; ./push_swap --adaptive $ARG
~~~

Force the simple $O(n^2)$ strategy:
~~~
$> ./push_swap --simple 5 4 3 2 1
~~~

Force the complex $O(n \log n)$ strategy and verify with the checker:
~~~
$> ARG="4 67 3 87 23"; ./push_swap --complex $ARG | ./checker_linux $ARG
OK
~~~

Push_swap with a large input:
~~~
$> shuf -i 0-9999 -n 500 > args.txt ; ./push_swap $(cat args.txt)
6784
~~~

Error management examples:
~~~
$> ./push_swap --adaptive 0 one 2 3
Error
$> ./push_swap --simple 3 2 3
Error
~~~

[Back to top](#table-of-contents)

## Technical Choices

### Considerations

#### Regarding the Disorder Metric

The program evaluates the **disorder** of stack `a`: a value between 0 and 1 representing how far the stack is from being sorted (0 being perfectly sorted, 1 being the worst possible order). When operating under the `--adaptive` flag, the following regimes are applied to stay within optimal operation counts:

- Low Disorder (disorder < 0.2): Applies an $O(n^2)$ sort method (Selection Sort Adaptation). This regime is optimized for nearly sorted stacks where simple swaps and rotations are more efficient than complex partitioning.
- Medium Disorder (0.2 ≤ disorder < 0.5): Applies an $O(n\sqrt{n})$ sort method (Chunk Sort Adaptation). This provides a balanced middle ground to handle moderate entropy without the full overhead of bitwise sorting.
- High Disorder (disorder ≥ 0.5): Applies an $O(n \log n)$ sort method (LSD Radix Sort). This ensures that even the most chaotic datasets are sorted within the strict operation limits of the push_swap model.

#### Decisions Behind Sorting Algorithms Choices

Decisions were based on the following targets whereever feasible:

1. For 100 random numbers, your program should use:
	- Less than 2000 operations to pass (minimum requirement)
	- Less than 1500 operations for good performance
	- Less than 700 operations for excellent performance
2. For 500 random numbers, your program should use:
	- Less than 12000 operations to pass (minimum requirement)
	- Less than 8000 operations for good performance
	- Less than 5500 operations for excellent performance

	
### Adaptive Mode: Sorting Stacks Less Than Ten Elements

In the interest of optimisation, it was decided that two additional algorithms would be used to sort a stack of 3 elements, and a stack of four to nine elements.

A stack of three is the simplest to sort and requires at most two operations to sort.

For stacks of four to nine elements, a variation of the simple algorith was used to ensure efficient sorting.
	
	
### Simple Algorithm: Selection Sort Adaptation $O(n^2)$

The simple algorithm is a selection sort adaptation. At each iteration, it finds the smallest remaining value in stack `a` and moves it to the top of stack `b`, repeating until only the maximum value remains in `a`. Once `b` contains all other values in descending order, every element is pushed back to `a`, reconstructing the stack in ascending order.

#### How extraction works
To move the smallest node to the top of `a`, the algorithm checks whether the node is above or below the median of the stack:
- **Above the median** -> series of `ra` (rotate) operations to bring it up from the top
- **Below the median** -> series of `rra` (reverse rotate) operations to bring it up from the bottom

This avoids always rotating in the same direction, halving the worst-case rotation cost per extraction.

#### Limitations

This strategy is efficient for small inputs but degrades quickly as `n` grows — each extraction can require up to `n/2` rotations, and there are `n` extractions. For inputs above ~20 elements or with higher disorder, other algorithms strategy will typically outperform it.

### Medium Algorithm: Chunk Sort Adaptation $O(n\sqrt{n})$

The medium algorithm uses a **chunk-based greedy sort** operating in two phases.

#### Phase 1: Distributing to Stack B

All elements of `a` are pushed to `b` in **two chunks** of equal size, determined by their normalized index (rank in sorted order). Elements are pushed from the top or bottom of `a` (using `ra` or `rra`) to minimize rotations.

#### Phase 2: Reinserting into Stack A

Each element of B is reinserted into `a` at its correct position using a **cost-based greedy strategy**:

1. For each node in `b`, find its **target** in `a` — the smallest element in `a` strictly greater than the node (or the minimum of `a` if none exists).
2. Compute the **push cost** — the total rotations needed to bring both the node and its target to the top of their respective stacks. Simultaneous rotations (`rr` / `rrr`) are used when both are on the same side.
3. Select the **cheapest** node and execute the moves, then `pa`.

Once `b` is empty, the minimum of `a` is rotated to the top with `ra` or `rra`.

#### Complexity

| Case | Operations (n = 500) |
|---|---|
| Average (~50% disorder) | ~4400 - 4800 |
| Worst case | < 5 500 |


### Complex Algorithm: Pure LSD Radix $O(n \log n)$

At first, a Mechanical Turk style sorting algorithm was considered, as it can have potentially quite good results according to the research. However, after evaluating it's complexity, it was found to not comply with the $O(n \log n)$ specification (at worst it is ($O(n^2)$)). Therefore a decision was made to use a pure LSD based radix sorting algorithm.

LSD Radix Sort is a non-comparative sorting algorithm that processes integers by individual digits or bits. In the context of push_swap, it is implemented using a binary (base-2) approach to efficiently partition elements between stack `a` and stack `b`. By evaluating the stack multiple times, once for each bit, it organises the numbers into a fully sorted sequence.

#### How bitwise partitioning works
Since push_swap only allows two stacks, the algorithm treats each number as a binary string. It iterates through each bit position (from the least significant to the most significant):

- Bit is 0 -> The number is pushed to stack `b` (`pb`).
- Bit is 1 -> The number remains in stack a and is rotated to the bottom (`ra`).

After checking all elements for the current bit, everything in stack `b` is pushed back to stack a (`pa`), and the process moves to the next bit.

#### Limitations
While Radix Sort is highly consistent and "stable", its rigid nature means it does not take advantage of partially sorted data. It will *always* perform the same number of operations **regardless of the initial order and disorder**.

1. Preprocessing required: Numbers must be "indexed" (simplified to a range of 0 to N-1) to handle negative values and large gaps between numbers. Radix by nature cannot process negative numbers, and must therefore rely on indexing instead
2. Fixed operation count: The number of passes is determined by the maximum number of bits $ (\log n)$, making it predictable but sometimes less efficient than optimized Quick Sort variants for certain distributions. The place that LSD radix really outperforms other sorting algorithms is with large data sets with high levels of disorder
3. High instruction count: For small sets (like 5 or 100 elements), the overhead of bit-by-bit shifting often exceeds the cost of more direct "search and push" methods
4. Due to the nature of sorting based on bits (0/1), attempts to optimise the code, such as using log<sub>4</sub> or log<sub>8</sub> bases, did not produce significant improvements in performance, and in many cases actually worsened the total number of operations

#### Reason for Choosing LSD Radix

Despite its limitations, and inability to be meaningfully optimised, LSD radix is a very stable algorithm, meaning that it's performance is not greatly affected by factors such as disorder, and it is very fast in sorting large stacks. LSD radix was also chosen because it provided an opportunity to learn more about bit shifting and bit operations.

#### Complexity

| Case (n = ?)| Expected Operations Count |
|---|---|
| 100 | 1084 |
| 500 | 6784 |
| 5000 | 100196 |

[Back to top](#table-of-contents)

## Resources

### Documentation & References

- https://medium.com/@ayogun/push-swap-c1f5d2d41e97
- https://www.youtube.com/watch?v=wRvipSG4Mmk&t=4s
- https://www.geeksforgeeks.org/dsa/radix-sort/
- https://www.geeksforgeeks.org/c/extract-bits-in-c/
- https://satyadeepmaheshwari.medium.com/sorting-large-datasets-with-limited-memory-the-chunked-merge-sort-approach-318275275c81
- https://eng.libretexts.org/Bookshelves/Computer_Science/Programming_and_Computation_Fundamentals/Algorithm_Design_and_Analysis_(Justo)/03%3A_Sorting_Algorithms

### Use of AI

AI tools were used selectively during the development of this project for:

- Verifying understanding of concepts related to the project, such as bit shifting, differences between sorting algorithms in relation to BigO category requirements of the project, etc
- Edge case testing and data sets: AI was used to generate large data sets (500 elements) with varying disorder to stress test the code and confirm that acceptable total numbers of push operation results were being achieved. INT_MIN and INT_MAX were also included in these stress tests
- Brainstorming potential methods for optimising sorting algorithms

AI was not used to generate final implementations directly. All logic and code structure for this project are of our own making.

[Back to top](#table-of-contents)

## Contributions

The following sections were contributed by *thours*.

- Makefile
- Main.c
- push_swap.h
- Input parser (check, extract, get_index, etc)
- Algo Helpers
- Libft
- Low disorder mode ($O(n^2)$)
- Medium disorder mode ($O(n\sqrt{n})$)
- Benchmark mode (debugging and final implementation)
- Short list handler
- Bonus part: Checker

The following sections were contributed by *speterse*.

- README
- Disorder checker
- Adaptive mode
- Benchmark mode (inital design)
- ft_putdouble_fd
- Push operations (pa, pb, ra, rb, etc)
- High disorder ($O(n \log n)$)

We also collaborated together on various things and held regular discussions, both in person and via discord, relating to our progress and implementations of our relevant tasks. We decided, mostly upfront, which sections would be handled by whom, and with each of us picking up additional tasks the project progressed.
Git tools, such as branches and merges, were used extensively in this project to facilitate collabortion and avoid any potential types of coding conflicts.

[Back to top](#table-of-contents)
