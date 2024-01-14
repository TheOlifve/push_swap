# Push_swap

Push_swap is a project from 42 School that involves sorting a stack of integers using only two stacks and a set of predefined operations. The goal of this project is to implement an efficient algorithm that can sort a stack of any size using the smallest number of operations possible.

## Instruction Set

To use the push_swap program, simply run it with a list of integers as arguments. This will output a list of operations that can be used to sort the stack. The operations are as follows:

* sa: swap the first two elements of stack A
* sb: swap the first two elements of stack B
* ss: do sa and sb at the same time
* pa: take the first element from stack B and put it at the top of stack A
* pb: take the first element from stack A and put it at the top of stack B
* ra: rotate stack A so that the first element becomes the last
* rb: rotate stack B so that the first element becomes the last
* rr: do ra and rb at the same time
* rra: reverse rotate stack A so that the last element becomes the first
* rrb: reverse rotate stack B so that the last element becomes the first
* rrr: do rra and rrb at the same time
