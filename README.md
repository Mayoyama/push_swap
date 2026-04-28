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

### Available Operations

The following operations were made available:

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
1. a
1. a
1. a
1. a

### Optional Strategy Selector

The following flags can be used on the command prompt at time of execution.
- -- simple Forces the use of your O(n2) algorithm.
- --medium Forces the use of your O(n√n) algorithm.
- --complex Forces the use of your O(n log n) algorithm.
- --adaptive Forces the use of your adaptive algorithm based on disorder.

**Adaptive is the default behavior if no selector is given.**

### Benchmark Mode

The optional benchmark mode (--bench) displays, after sorting:
- The computed disorder (% with two decimals).
- The name of the strategy used and its theoretical complexity class.
- The total number of operations.
- The count of each operation type (sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr).

The benchmark output is sent to stderr and only appears when the flag is present.

#### Example Screenshots

Run with benchmark enabled; hide operations and show only metrics:
![Run with benchmark enabled; hide operations and show only metrics](https://i.imgur.com/PlJJeqz.png)

Pipe operations to the checker while saving benchmark to a file:
![Pipe operations to the checker while saving benchmark to a file](https://i.imgur.com/pdj3RJh.png)

[Back to top](#table-of-contents)

## Usage Examples

Below are some examples of command prompt inputs that can be used to alter the behaviour of the program:

Default selection (--adaptive) and operation count:
~~~
$> ARG="4 67 3 87 23"; ./push_swap --adaptive $ARG | wc -l
~~~

Force the simple (O(nˆ2)) strategy:
~~~
$> ./push_swap --simple 5 4 3 2 1
~~~

Force the complex (O(n log n)) strategy and verify with the checker:
~~~ 
$> ARG="4 67 3 87 23"; ./push_swap --complex $ARG | ./checker_linux $ARG 
OK
~~~

Push_swap with a large input:
~~~
$> shuf -i 0-9999 -n 500 > args.txt ; ./push_swap $(cat args.txt) | wc -l
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

### Decision Behind Sorting Algorithms Choices

> text explaining which algorithms we chose and why

Decision should relate to the following targets

For 100 random numbers, your program should use:
- Less than 2000 operations to pass (minimum requirement)
- Less than 1500 operations for good performance
- Less than 700 operations for excellent performance
- For 500 random numbers, your program should use:
- Less than 12000 operations to pass (minimum requirement)
- Less than 8000 operations for good performance
- Less than 5500 operations for excellent performance

### Considerations Regarding the Disorder Metric

Disorder is a number between 0 and 1 that tells how far the initial stack a is from being sorted. If the numbers are already in the right order, the disorder is 0. If they are in the worst
possible order, the disorder is 1.

When operating under the --adaptive flag, the following complexity targets per regime will be applied.

- Low disorder: if disorder < 0.2, the XXX sort method will be applied (in O(n2) time).
- Medium disorder: if 0.2 ≤ disorder < 0.5, the XXX sort method will be applied (in O(n√n) time).
- High disorder: if disorder ≥ 0.5, the XXX sort method will be applied (in O(n log n) time)

~~~
You must document in your repository (e.g., README.md) the rationale for your
thresholds, the internal techniques used in each regime, and a brief complexity
argument (upper bounds) for time and space within the Push_swap model.
~~~

[Back to top](#table-of-contents)

## Resources

### Documentation & References

- a
- a
- a
- a

### Use of AI

AI tools were used selectively during the development of this project for:

- a
- a
- a

AI was not used to generate final implementations directly. All logic and code structure for this project are of our own making.

[Back to top](#table-of-contents)

## Contributions

The following sections were contributed by *thours*.

- Makefile
- push_swap.h

The following sections were contributed by *speterse*.

-  README.md
- a

[Back to top](#table-of-contents)