/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 18:59:34 by anemesis          #+#    #+#             */
/*   Updated: 2022/03/19 14:56:07 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

void	ra_silent(t_stack *a)
{
	int	buf_val;
	int	buf_order;

	buf_order = a->head->order;
	buf_val = pop_stack_front(a);
	push_stack_back(a, buf_val);
	a->tail->order = buf_order;
}

void	rb_silent(t_stack *b)
{
	int	buf_val;
	int	buf_order;

	buf_order = b->head->order;
	buf_val = pop_stack_front(b);
	push_stack_back(b, buf_val);
	b->tail->order = buf_order;
}

void	rr_silent(t_stack *a, t_stack *b)
{
	int	buf_val;
	int	buf_order;

	buf_order = a->head->order;
	buf_val = pop_stack_front(a);
	push_stack_back(a, buf_val);
	a->tail->order = buf_order;
	buf_order = b->head->order;
	buf_val = pop_stack_front(b);
	push_stack_back(b, buf_val);
	b->tail->order = buf_order;
}
