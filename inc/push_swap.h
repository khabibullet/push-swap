/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 18:59:43 by anemesis          #+#    #+#             */
/*   Updated: 2022/03/13 21:12:36 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define BUFFER_SIZE 128
# include "../libft/libft.h"

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
** sort functions
*/
void	presort_stack(t_stack *a);

#endif
