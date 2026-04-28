# Push_Swap Project Notes

NB: As we progress through the project we can start deleting sections of this to make it easier to keep track of what still needs to be done

|
|-----|------|
| Program Name | push_swap |
| Files to Submit | Makefile, *.h, *.c |
| Makefile | NAME, all, clean, fclean, re |
| Arguments | stack a: A list of integers |
|External Function | <ul><li>read, write, malloc, free, exit</li><li>ft_printf or any equivalent YOU coded</li></ul> |

## Main Task

You must write a program named push_swap that takes as arguments:
- The stack a formatted as a list of integers (the first argument is the top of the
stack).
- The program must display the smallest list of Push_swap operations possible to sort stack a, the smallest number being at the top.
- Operations must be separated by a \n and nothing else.
- The complexity class claimed for each algorithm must be valid in this model.
- The strategy selection must work for all valid inputs. Any selector flag should work regardless of input size or disorder.
- All strategies are implemented in C and must generate sequences of Push_swap operations to perform the sorting. This means:
	- Your C algorithms analyze the input and generate the appropriate sequence of operations: sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr.
	- The output of your strategy is the sequence of these operations that sorts the stack.
	- When you state a complexity class, it must reflect the cost measured in number of Push_swap operations generated, not the theoretical complexity of a classical array-based algorithm
- An optional strategy selector:
	- -- simple Forces the use of your O(n2) algorithm.
	- --medium Forces the use of your O(n√n) algorithm.
	- --complex Forces the use of your O(n log n) algorithm.
	- --adaptive Forces the use of your adaptive algorithm based on disorder.

**Adaptive is the default behavior if no selector is given.**

- During the defense, both learners must be present and able to explain any part of
the code.
- The project submission should include both learners’ logins in the repository.

## Required Strategies

1. Simple algorithm (O(n2)): Implement at least one baseline algorithm in the O(n2) class. Examples include:
	- Insertion sort adaptation
	- Selection sort adaptation
	- Bubble sort adaptation
	- Simple min/max extraction methods
2. Medium algorithm (O(n√n)): Implement at least one algorithm in the O(n√n) class. Examples include:
	- Chunk-based sorting (divide into √n chunks)
	- Block-based partitioning methods
	- Bucket sort adaptations with √n buckets
	- Range-based sorting strategies
3. Complex algorithm (O(n log n)): Implement at least one algorithm in the O(n log n) class. Examples include:
	- Radix sort adaptation (LSD or MSD)
	- Merge sort adaptation using two stacks
	- Quick sort adaptation with stack partitioning
	- Heap sort adaptation
	- Binary indexed tree approaches
4. Custom adaptive algorithm (learner’s design): 
- Design an adaptive strategy
that selects different internal methods depending on the measured disorder. 
- You are not constrained to any specific named algorithm; the internal techniques are entirely up to you. 
- However, your design must respect the following complexity targets per regime (in the Push_swap operation model):
	- Low disorder: if disorder < 0.2, your chosen method must run in O(n2) time.
	- Medium disorder: if 0.2 ≤ disorder < 0.5, your chosen method must run in O(n√n) time.
	- High disorder: if disorder ≥ 0.5, your chosen method must run in O(n log n) time.
- You must document in your repository (e.g., README.md) the rationale for your
thresholds, the internal techniques used in each regime, and a brief complexity
argument (upper bounds) for time and space within the Push_swap model

## The Rules

- You have 2 stacks named a and b.
- At the beginning:
	- The stack a contains a random amount of negative and/or positive numbers without any duplicate.
	- The stack b is empty.
- The goal is to sort in ascending order numbers into stack a. To do so you have the following operations at your disposal:

|
|-|-|
|sa (swap a) | Swap the first two elements at the top of stack a. Do nothing if there is only one or no elements.|
|sb (swap b) | Swap the first two elements at the top of stack b. Do nothing if there is only one or no elements.|
|ss | sa and sb at the same time.|
|pa (push a) | Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.|
|pb (push b) | Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.|
|ra (rotate a) | Shift up all elements of stack a by one. The first element becomes the last one.|
|rb (rotate b) | Shift up all elements of stack b by one. The first element becomes the last one.|
|rr | ra and rb at the same time.|
|rra (reverse rotate a) | Shift down all elements of stack a by one. The last element becomes the first one.|
|rrb (reverse rotate b) | Shift down all elements of stack b by one. The last element becomes the first one.|
|rrr | rra and rrb at the same time.|

## Additional Requirements

- The program must display the smallest list of Push_swap operations possible to sort stack a, the smallest number being at the top.
- Operations must be separated by a \n and nothing else.
- The complexity class claimed for each algorithm must be valid in this model.
- The strategy selection must work for all valid inputs. Any selector flag should work regardless of input size or disorder.

## Benchmarking

- Your binary must embed all four strategies (Simple O(n2), Medium O(n√n), Complex O(n log n), and Adaptive). The selected strategy name and complexity class must be available in --bench mode.

The optional benchmark mode (--bench) must display, after sorting:
- The computed disorder (% with two decimals).
- The name of the strategy used and its theoretical complexity class.
- The total number of operations.
- The count of each operation type (sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb,
rrr).
The benchmark output must be sent to stderr and only appear when the flag is
present

### Required benchmark Results

- For 100 random numbers, your program should use:
	- Less than 2000 operations to pass (minimum requirement)
	- Less than 1500 operations for good performance
	- Less than 700 operations for excellent performance

- For 500 random numbers, your program should use:
	- Less than 12000 operations to pass (minimum requirement)
	- Less than 8000 operations for good performance
	- Less than 5500 operations for excellent performance

## Error Handling

- If no parameters are specified, the program must not display anything and give the prompt back.
- In case of error, it must display "Error" followed by a \n on the standard error.
- Errors include, for example: arguments that are not integers, integers outside the valid range, or duplicate values.
 
## Disorder metric

In this subject, disorder is a number between 0 and 1 that tells how far your initial
stack a is from being sorted.

If the numbers are already in the right order, the disorder is 0. If they are in the worst
possible order, the disorder is 1. Anything in between means your stack is partly sorted,
but still messy.

To calculate it, you can think of looking at all the possible pairs of numbers in the stack.
Each time a bigger number appears before a smaller one, that pair counts as a mistake.

The more mistakes you have, the closer the disorder is to 1

~~~
function compute_disorder(stack a):
mistakes = 0
total_pairs = 0
for i from 0 to size(a)-1:
for j from i+1 to size(a)-1:
total_pairs += 1
if a[i] > a[j]:
mistakes += 1
return mistakes / total_pairs
~~~
You must measure the disorder before doing any moves



## Command Prompt: Usage Examples

Notation: lines prefixed with [bench] represent messages printed by the optional bench-
mark mode (to stderr). The operation stream remains on stdout.

~~~
$>./push_swap 2 1 3 6 5 8
ra
pb
rra
pb
pb
ra
pb
ra
pb
pb
pa
pa
pa
pa
pa
pa
~~~

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