/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nth_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 20:33:30 by anemesis          #+#    #+#             */
/*   Updated: 2022/03/18 21:00:47 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	pop_stack_back(t_stack *stack)
{
	t_node	*next;
	int		data;

	if (stack->tail == NULL)
		exit(EXIT_FAILURE);
	next = stack->tail;
	stack->tail = stack->tail->prev;
	if (stack->tail)
		stack->tail->next = NULL;
	if (next == stack->head)
		stack->head = NULL;
	data = next->val;
	free(next);
	stack->size--;
	return (data);
}

t_node	*get_nth_node(t_stack *stack, int index)
{
	t_node	*tmp;
	int		i;

	tmp = stack->head;
	i = 0;
	while (tmp && i < index)
	{
		tmp = tmp->next;
		i++;
	}
	return (tmp);
}

void	push_stack_nth(t_stack *stack, int index, int data)
{
	t_node	*elm;
	t_node	*ins;

	elm = NULL;
	ins = NULL;
	elm = get_nth_node(stack, index);
	if (elm == NULL)
		exit(EXIT_FAILURE);
	ins = malloc(sizeof(t_node));
	ins->val = data;
	ins->prev = elm;
	ins->next = elm->next;
	if (elm->next)
		elm->next->prev = ins;
	elm->next = ins;
	if (!elm->prev)
		stack->head = elm;
	if (!elm->next)
		stack->tail = elm;
	stack->size++;
}

int	pop_nth_node(t_stack *stack, int index)
{
	t_node	*elm;
	int		tmp;

	elm = NULL;
	tmp = 0;
	elm = get_nth_node(stack, index);
	if (elm == NULL)
		exit(EXIT_FAILURE);
	if (elm->prev)
		elm->prev->next = elm->next;
	if (elm->next)
		elm->next->prev = elm->prev;
	tmp = elm->val;
	if (!elm->prev)
		stack->head = elm->next;
	if (!elm->next)
		stack->tail = elm->prev;
	free(elm);
	stack->size--;
	return (tmp);
}
