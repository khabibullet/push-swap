/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_rev_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:15:03 by anemesis          #+#    #+#             */
/*   Updated: 2022/03/16 14:00:03 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rra(t_stack *a)
{
	int	buf_val;
	int	buf_order;

	buf_order = a->tail->order;
	buf_val = pop_stack_back(a);
	push_stack_front(a, buf_val);
	a->head->order = buf_order;
	ft_printf("rra\n");
}

void	rrb(t_stack *b)
{
	int	buf_val;
	int	buf_order;

	buf_order = b->tail->order;
	buf_val = pop_stack_back(b);
	push_stack_front(b, buf_val);
	b->head->order = buf_order;
	ft_printf("rrb\n");
}

void	rrr(t_stack *a, t_stack *b)
{
	int	buf_val;
	int	buf_order;

	buf_order = a->tail->order;
	buf_val = pop_stack_back(a);
	push_stack_front(a, buf_val);
	a->head->order = buf_order;
	buf_order = b->tail->order;
	buf_val = pop_stack_back(b);
	push_stack_front(b, buf_val);
	b->head->order = buf_order;
	ft_printf("rrr\n");
}
