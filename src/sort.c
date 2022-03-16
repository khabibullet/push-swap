/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:36:30 by anemesis          #+#    #+#             */
/*   Updated: 2022/03/16 01:46:24 by anemesis         ###   ########.fr       */
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

int	count_steps(t_stack *a, t_stack *b, t_node *ptr, int *direction)
{
	int	count;

	count = 0;
	(void)a;
	(void)b;
	(void)ptr;
	(void)direction;
	return (count);
}

void	sort_to_a(t_stack *a, t_stack *b)
{
	t_node	*ptr;
	t_node	*ptr_min;
	int		min_steps;
	int		steps;
	int		direction;

	ptr = b->head;
	ptr_min = ptr;
	min_steps = count_steps(a, b, ptr, &direction);
	while (ptr)
	{
		steps = count_steps(a, b, ptr, &direction);
		if (min_steps > steps)
		{
			min_steps = steps;
			ptr_min = ptr;
		}
		ptr = ptr->next;
	}

}

void	launch_algo(t_stack *a, t_stack *b)
{
	push_median(a, b);
	sort_to_b(a, b);
	sort_to_a(a, b);
}
