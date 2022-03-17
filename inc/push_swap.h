/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 18:59:43 by anemesis          #+#    #+#             */
/*   Updated: 2022/03/17 21:14:25 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define BUFFER_SIZE 128
# include "../libft/libft.h"

typedef struct t_rules
{
	int		opt_i;
	int		opt_j;
	int		steps;
	int		cases;
	int		rr;
	int		rrr;
	int		ra_rrb;
	int		rra_rb;
}	t_rules;

typedef struct t_node
{
	int				val;
	int				order;
	struct t_node	*next;
	struct t_node	*prev;
}	t_node;

typedef struct t_stack
{
	int		size;
	t_node	*head;
	t_node	*tail;
}	t_stack;
/*
** elementary functions
*/
t_stack	*create_stack(void);
void	delete_stack(t_stack **stack);
void	push_stack_front(t_stack *stack, int data);
int		pop_stack_front(t_stack *stack);
void	push_stack_back(t_stack *stack, int data);
int		pop_stack_back(t_stack *stack);
t_node	*get_nth_node(t_stack *stack, int index);
void	push_stack_nth(t_stack *stack, int index, int data);
int		pop_nth_node(t_stack *stack, int index);
/*
** parser functions
*/
t_stack	*parse_args(int argc, char **argv);
void	validate_args(int argc, char **argv);
char	*concatenate_args(char **argv);
t_stack	*fill_stack(char **strs);
void	check_doubles(t_stack *a);
/*
** presort
*/
void	presort_stack(t_stack *a);
/*
** rules
*/
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
/*
** sort algorithm functions
*/
void	push_median(t_stack *a, t_stack *b);
void	launch_algo(t_stack *a, t_stack *b);
void	sort_to_b(t_stack *a, t_stack *b);
void	sort_to_a(t_stack *a, t_stack *b);

void	push_optimal_to_a(t_stack *a, t_stack *b, t_rules *rule);
void	rot_differ_direction(t_stack *a, t_stack *b, t_rules *rule);
void	rot_a_down_b_down(t_stack *a, t_stack *b, t_rules *rule);
void	rot_a_up_b_up(t_stack *a, t_stack *b, t_rules *rule);
t_rules	count_rules_for_j(int sza, int szb, int i, int j);
int		min_four(int a, int b, int c, int d);
int		find_i_in_a(t_stack *a, int order);
/*
** mini sort
*/
void	mini_sort(t_stack *a, t_stack *b);
void	sort_three(t_stack *a);
void	sort_four(t_stack *a, t_stack *b);
void	sort_five(t_stack *a, t_stack *b);

void	exit_success(t_stack *a, t_stack *b);
void	issorted(t_stack *a, t_stack *b);

#endif
