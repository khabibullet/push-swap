# **PUSH_SWAP**

**Push_swap** calculates and displays on the standard output the smallest program, made of Push swap language instructions, that sorts the integers received as arguments.

We have 2 **stacks** named **a** and **b**. At the beginning: the stack **a** contains a random amount of negative and/or positive numbers which cannot be duplicated, the stack **b** is empty.

The goal is to sort in ascending order numbers into stack **a**. To do so we have the
following operations at our disposal:

**sa** (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.

**sb** (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.

**ss** : sa and sb at the same time.

**pa** (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.

**pb** (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.

**ra** (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.

**rb** (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.

**rr** : ra and rb at the same time.

**rra** (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.

**rrb** (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.

**rrr** : rra and rrb at the same time.

<img src="readme/pushswap.gif" alt="drawing" width="750" title="room.rt"/>

## **Platform**
macOS (x86).
<br><br>

## **Instruments**

Self-written libc functions library **"libft"** is used due to educational subject restrictions as well as readline analogue **"get_next_line"** and simplified version of printf **"ft_printf"**.

Source files are lintered by "**42 Norminette**" linter.

[Visualizer by o-reo](https://github.com/o-reo/push_swap_visualizer) is also used to visualize instructions given by push_swap output.
<br><br>

## **Usage**

Building push_swap binary (mandatory).

```console
host@name:~$ make
host@name:~$ ./push_swap random_set_of_unique_integers
```

Building checker which checks if push_swap given instructions are correct (bonus).

```console
host@name:~$ make bonus
host@name:~$ ./checker set_of_integers | ./checker the_same_set
```
<br><br>