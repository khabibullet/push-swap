/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:21:58 by anemesis          #+#    #+#             */
/*   Updated: 2022/03/16 13:59:13 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	mini_sort(t_stack *a, t_stack *b)
{
	if (a->size == 2 && a->head->val > a->tail->val)
		sa(a);
	else if (a->size == 3)
		sort_three(a);
	else if (a->size == 4)
		sort_four(a, b);
	else if (a->size == 5)
		sort_five(a, b);
}

void	sort_three(t_stack *a)
{
	if (a->head->next->val > a->head->val
		&& a->head->next->val > a->tail->val)
		rra(a);
	if (a->head->val > a->head->next->val
		&& a->head->val < a->tail->val)
		sa(a);
	if (a->head->next->val < a->head->val
		&& a->head->next->val < a->tail->val)
		ra(a);
	if (a->head->val > a->head->next->val
		&& a->head->val > a->tail->val)
	{
		sa(a);
		rra(a);
	}
}

void	sort_four(t_stack *a, t_stack *b)
{
	t_node	*ptr;
	t_node	*ptr_min;

	ptr = a->head;
	ptr_min = ptr;
	while (ptr)
	{
		if (ptr->val < ptr_min->val)
			ptr_min = ptr;
		ptr = ptr->next;
	}
	if (ptr_min != a->tail)
	{
		while (ptr_min != a->head)
			ra(a);
	}
	else
		rra(a);
	pb(a, b);
	sort_three(a);
	pa(a, b);
}

void	sort_five(t_stack *a, t_stack *b)
{
	t_node	*ptr;

	ptr = a->head;
	while (ptr->order != 0)
		ptr = ptr->next;
	if (ptr == a->tail || ptr == a->tail->prev)
	{
		while (a->head->order != 0)
			rra(a);
	}
	else
	{
		while (a->head->order != 0)
			ra(a);
	}
	pb(a, b);
	sort_four(a, b);
	pa(a, b);
}
