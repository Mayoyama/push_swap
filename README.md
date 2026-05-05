TO BE COMPLETED: NB: Links are broken, sorry!
- [# Other?](other?) needed?
- Line 94: Update medium mode name
- [Simple Algorithm — Selection Sort Adaptation O(n²)](simple-algorithm---selection-sort-adaptation-$o(n^2)$) - Proofreading and update limitations
- [# (Medium)]((medium)) - Update with your medium algorithm information
- [RADIX STUFF](LSD-radix)
- [# Considerations: Regarding the Disorder Metric](considerations:-regarding-the-disorder-metric) Update medium name
- [# Documentation & References](documentation-&-References): update
- Final formatting check to ensure consistency
- Consider adding a few subsections to the TOC for longer sections

~~~
You must document in your repository (e.g., README.md) the rationale for your
thresholds, the internal techniques used in each regime, and a brief complexity
argument (upper bounds) for time and space within the Push_swap model.
~~~


*This project has been created as part of the 42 curriculum by thours[, speterse[...]].*

# push_swap

## Table of Contents
1. [Description](#description)
2. [Instructions](#instructions)
3. [Program Overview](#program-overview)
4. [Features](#features)
5. [Usage Examples](#usage-examples)
6. [Technical Choices](#technical-choices)
7. [Resources](#resources)
8. [Contributions](#contributions)

## Description

The objective of this project is to Write a C program which calculates and displays on the standard output the smallest program, made of Push swap language operations, that sorts the integers received as arguments.
The primary goals of this project were to:

1. Learn about Big-O notation to help talk about how algorithms scale.
2. Gain a deeper understanding of algorithmic complexities in a very concrete way.
3. Discover how the choice of algorithm can make the difference between a quick win and an endless scroll of operations.

[Back to top](#table-of-contents)

## Instructions

### Compilation

To compile the project and generate the static library, use:

> make

This will generate the program:

> push_swap

### Available Makefile Rules

- make (all) — Compile all mandatory source files and create the program
- make bonus - Compiles the bonus files
- make clean — Remove object files
- make fclean — Remove object files and library
- make re — Rebuild the library from scratch

[Back to top](#table-of-contents)

## Program Overview

### Provided Guidelines

- There are 2 stacks named a and b.
- At the beginning:
	- Stack `a` contains a random amount of negative and/or positive numbers without any duplicate(s).
	- Stack `b` is empty.
- The goal is to sort in ascending order numbers into stack `a`.
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



### Other?

[Back to top](#table-of-contents)

## Features

### Sort Algorithms

The following algorithms were implemented in this program:
- Selection Sort Adaptation $O(n^2)$ 
- CHUNK? $O(n\sqrt{n})$
- LSD Radix Adaptation $O(n \log n)$


### Optional Strategy Selector

The following flags can be used on the command prompt at time of execution.
- -- simple Forces the use of the $O(n^2)$ algorithm.
- --medium Forces the use of the $O(n\sqrt{n})$ algorithm.
- --complex Forces the use of the $O(n \log n)$ algorithm.
- --adaptive Forces the use of the adaptive algorithm based on disorder.

**Adaptive is the default behavior if no selector is given.**

### Benchmark Mode

The optional benchmark mode (--bench) displays, after sorting:
- The computed disorder (% with two decimals).
- The name of the strategy used and its theoretical complexity class.
- The total number of operations.
- The count of each operation type (sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr).

The benchmark output is sent to stderr and only appears when the flag is present.

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

### Decisions Behind Sorting Algorithms Choices

Decisions were based on the following targets:

1. For 100 random numbers, your program should use:
	- Less than 2000 operations to pass (minimum requirement)
	- Less than 1500 operations for good performance
	- Less than 700 operations for excellent performance
2. For 500 random numbers, your program should use:
	- Less than 12000 operations to pass (minimum requirement)
	- Less than 8000 operations for good performance
	- Less than 5500 operations for excellent performance

#### Simple Algorithm — Selection Sort Adaptation $O(n^2)$

The simple algorithm is a selection sort adaptation. At each iteration, it finds the smallest remaining value in stack `a` and moves it to the top of stack `b`, repeating until only the maximum value remains in `a`. Once `b` contains all other values in descending order, every element is pushed back to `a`, reconstructing the stack in ascending order.

##### How extraction works
To move the smallest node to the top of `a`, the algorithm checks whether the node is above or below the median of the stack:
- **Above the median** -> series of `ra` (rotate) operations to bring it up from the top
- **Below the median** -> series of `rra` (reverse rotate) operations to bring it up from the bottom

This avoids always rotating in the same direction, halving the worst-case rotation cost per extraction.

##### Limitations

This strategy is efficient for small inputs but degrades quickly as `n` grows — each extraction can require up to `n/2` rotations, and there are `n` extractions. For inputs above ~20 elements, the medium or complex strategy will always outperform it.

1. a
1. a
1. a

#### (Medium)

> text explaining which algorithm we chose and why

#### LSD radix + Turk optimisation layer

At first, a Mechanical Turk style sorting algorithm was considered, as it potentially can have quite good results according to the research. However, after evaluating it's complexity, it was found to not comply with the $O(n \log n)$ specification (at worst it is ($O(n^2)$).

However, I decided to use Mechanical Turk optimisations of a LSD Radix method, in order to lower push_swap operations

### Considerations: Regarding the Disorder Metric

The program evaluates the **disorder** of Stack A—a value between 0 and 1 representing how far the stack is from being sorted (0 being perfectly sorted, 1 being the worst possible order). When operating under the `--adaptive` flag, the following regimes are applied to stay within optimal operation counts:

*   **Low Disorder (Disorder < 0.2):** Applies an **$O(n^2)$ sort method** (Selection Sort Adaptation). This regime is optimized for nearly sorted stacks where simple swaps and rotations are more efficient than complex partitioning.
*   **Medium Disorder (0.2 ≤ Disorder < 0.5):** Applies an **$O(n\sqrt{n})$ sort method** (NAME OF MID). This provides a balanced middle ground to handle moderate entropy without the full overhead of bitwise sorting.
*   **High Disorder (Disorder ≥ 0.5):** Applies an **$O(n \log n)$ sort method** (Radix Sort). This ensures that even the most chaotic datasets are sorted within the strict operation limits of the push_swap model.

[Back to top](#table-of-contents)

## Resources

### Documentation & References

- https://medium.com/@ayogun/push-swap-c1f5d2d41e97
- https://www.youtube.com/watch?v=wRvipSG4Mmk&t=4s
- https://www.geeksforgeeks.org/dsa/radix-sort/
- https://www.geeksforgeeks.org/c/extract-bits-in-c/

### Use of AI

AI tools were used selectively during the development of this project for:

- Verifying understanding of concepts related to the project, such as bit shifting, differences between sorting algorithms in relation to BigO category requirements of the project, etc.
- Edge case testing and data sets: AI was used to generate large data sets (500 elements) with varying disorder to stress test the code and confirm that acceptable total numbers of push operation results were being achieved. INT_MIN and INT_MAX were also included in these stress tests.

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

The following sections were contributed by *speterse*.

- README
- Disorder checker
- Adaptive mode
- Benchmark mode (inital design)
- ft_putdouble_fd
- Push operations (pa, pb, ra, rb, etc)
- High disorder ($O(n \log n)$) 

We also collaborated together and held regular discussions relating to our progress and implementations of our relevant tasks. We decided upfront mostly which sections would be handled by whom, with each of us picking up additional tasks the project progressed.

[Back to top](#table-of-contents)
