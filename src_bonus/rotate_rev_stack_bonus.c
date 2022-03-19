/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_rev_stack_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:15:03 by anemesis          #+#    #+#             */
/*   Updated: 2022/03/19 14:55:52 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

void	rra_silent(t_stack *a)
{
	int	buf_val;
	int	buf_order;

	buf_order = a->tail->order;
	buf_val = pop_stack_back(a);
	push_stack_front(a, buf_val);
	a->head->order = buf_order;
}

void	rrb_silent(t_stack *b)
{
	int	buf_val;
	int	buf_order;

	buf_order = b->tail->order;
	buf_val = pop_stack_back(b);
	push_stack_front(b, buf_val);
	b->head->order = buf_order;
}

void	rrr_silent(t_stack *a, t_stack *b)
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
}
