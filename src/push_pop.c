/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elementaries_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 18:58:49 by anemesis          #+#    #+#             */
/*   Updated: 2022/03/13 13:44:40 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack	*create_stack(void)
{
	t_stack	*tmp;

	tmp = malloc(sizeof(t_stack));
	if (tmp == NULL)
		exit(EXIT_FAILURE);
	tmp->size = 0;
	tmp->head = NULL;
	tmp->tail = NULL;
	return (tmp);
}

void	delete_stack(t_stack **stack)
{
	t_node	*tmp;
	t_node	*next;

	tmp = (*stack)->head;
	next = NULL;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	free(*stack);
	(*stack) = NULL;
}

void	push_stack_front(t_stack *stack, int data)
{
	t_node	*tmp;

	tmp = malloc(sizeof(t_node));
	if (tmp == NULL)
		exit(EXIT_FAILURE);
	tmp->val = data;
	tmp->next = stack->head;
	tmp->prev = NULL;
	if (stack->head)
		stack->head->prev = tmp;
	stack->head = tmp;
	if (stack->tail == NULL)
		stack->tail = tmp;
	stack->size++;
}

int	pop_stack_front(t_stack *stack)
{
	t_node	*prev;
	int		data;

	if (stack->head == NULL)
		exit(EXIT_FAILURE);
	prev = stack->head;
	stack->head = stack->head->next;
	if (stack->head)
		stack->head->prev = NULL;
	if (prev == stack->tail)
		stack->tail = NULL;
	data = prev->val;
	free(prev);
	stack->size--;
	return (data);
}

void	push_stack_back(t_stack *stack, int data)
{
	t_node	*tmp;

	tmp = malloc(sizeof(t_node));
	if (tmp == NULL)
		exit(EXIT_FAILURE);
	tmp->val = data;
	tmp->next = NULL;
	tmp->prev = stack->tail;
	if (stack->tail)
		stack->tail->next = tmp;
	stack->tail = tmp;
	if (stack->head == NULL)
		stack->head = tmp;
	stack->size++;
}
