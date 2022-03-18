/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 18:59:34 by anemesis          #+#    #+#             */
/*   Updated: 2022/03/18 21:01:58 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	int	buf_val;
	int	buf_order;

	if (b->head)
	{
		buf_order = b->head->order;
		buf_val = pop_stack_front(b);
		push_stack_front(a, buf_val);
		a->head->order = buf_order;
		ft_printf("pa\n");
	}
}

void	pb(t_stack *a, t_stack *b)
{
	int	buf_val;
	int	buf_order;

	if (a->head)
	{
		buf_order = a->head->order;
		buf_val = pop_stack_front(a);
		push_stack_front(b, buf_val);
		b->head->order = buf_order;
		ft_printf("pb\n");
	}
}

void	sa(t_stack *a)
{
	int	buf;

	if (a->size > 1)
	{
		buf = a->head->val;
		a->head->val = a->head->next->val;
		a->head->next->val = buf;
		buf = a->head->order;
		a->head->order = a->head->next->order;
		a->head->next->order = buf;
		ft_printf("sa\n");
	}
}

void	sb(t_stack *b)
{
	int	buf;

	if (b->size > 1)
	{
		buf = b->head->val;
		b->head->val = b->head->next->val;
		b->head->next->val = buf;
		buf = b->head->order;
		b->head->order = b->head->next->order;
		b->head->next->order = buf;
		ft_printf("sb\n");
	}
}

void	ss(t_stack *a, t_stack *b)
{
	int	buf;

	if (a->size > 1 && b->size > 1)
	{
		buf = a->head->val;
		a->head->val = a->head->next->val;
		a->head->next->val = buf;
		buf = a->head->order;
		a->head->order = a->head->next->order;
		a->head->next->order = buf;
		buf = b->head->val;
		b->head->val = b->head->next->val;
		b->head->next->val = buf;
		buf = b->head->order;
		b->head->order = b->head->next->order;
		b->head->next->order = buf;
		ft_printf("ss\n");
	}
}
