/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:36:30 by anemesis          #+#    #+#             */
/*   Updated: 2022/03/18 21:03:10 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push_median(t_stack *a, t_stack *b)
{
	int		median_pos;
	t_node	*ptr;

	median_pos = 0;
	ptr = a->head;
	while (ptr->order != a->size / 2)
	{
		ptr = ptr->next;
		median_pos++;
	}
	if (median_pos <= a->size / 2)
	{
		median_pos++;
		while (--median_pos > 0)
			ra(a);
	}
	else
	{
		median_pos--;
		while (++median_pos < a->size)
			rra(a);
	}
	pb(a, b);
}

void	sort_to_b(t_stack *a, t_stack *b)
{
	int	median;
	int	max_order;

	median = b->head->val;
	max_order = a->size;
	while (a->size > 2)
	{
		if (a->head->order != 0 && a->head->order != max_order)
		{
			pb(a, b);
			if (b->head->val > median)
				rb(b);
		}
		else
			ra(a);
	}
}

void	sort_to_a(t_stack *a, t_stack *b)
{
	t_node	*ptr;
	t_rules	rule;

	while (b->size)
	{
		ptr = b->head;
		rule.j = 0;
		while (ptr)
		{
			rule.i = find_i_in_a(a, ptr->order);
			count_steps_for_j(a->size, b->size, &rule);
			if (ptr == b->head || rule.min_steps > rule.steps)
			{
				rule.min_steps = rule.steps;
				rule.best_case = rule.cases;
				rule.opt_j = rule.j;
				rule.opt_i = rule.i;
			}
			rule.j++;
			ptr = ptr->next;
		}
		push_optimal_to_a(a, b, &rule);
	}
}

void	final_rotate(t_stack *a)
{
	if (a->head->order > a->size / 2)
	{
		while (a->head->order != 0)
			ra(a);
	}
	else
	{
		while (a->head->order != 0)
			rra(a);
	}
}
