/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 20:59:47 by anemesis          #+#    #+#             */
/*   Updated: 2022/03/18 21:38:39 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	issorted(t_stack *a, t_stack *b)
{
	t_node	*ptr;

	ptr = a->head;
	while (ptr->next)
	{
		if (ptr->val > ptr->next->val)
			return ;
		ptr = ptr->next;
	}
	exit_success(a, b);
}

static int	new_min_delta(int *min_del_i, int i, int ptr_order, int order)
{
	int	min_delta;

	min_delta = ptr_order - order;
	*min_del_i = i;
	return (min_delta);
}

int	find_i_in_a(t_stack *a, int order)
{
	t_node	*ptr;
	int		i;
	int		min_delta_index;
	int		min_delta;

	ptr = a->head;
	i = 0;
	while (ptr->order - order < 0)
	{
		ptr = ptr->next;
		i++;
	}
	min_delta = new_min_delta(&min_delta_index, i, ptr->order, order);
	ptr = ptr->next;
	i++;
	while (ptr)
	{
		if (ptr->order - order > 0 && ptr->order - order < min_delta)
			min_delta = new_min_delta(&min_delta_index, i, ptr->order, order);
		ptr = ptr->next;
		i++;
	}
	return (min_delta_index);
}

int	min_four(int a, int b, int c, int d)
{
	int	min;
	int	min1;
	int	min2;

	min1 = ft_min(a, b);
	min2 = ft_min(c, d);
	min = ft_min(min1, min2);
	return (min);
}

void	count_steps_for_j(int sza, int szb, t_rules *rule)
{
	int	rr;
	int	rrr;
	int	ra_rrb;
	int	rra_rb;

	rr = ft_max(rule->i, rule->j);
	rrr = ft_max(sza - rule->i, szb - rule->j);
	ra_rrb = szb - rule->j + rule->i;
	rra_rb = sza - rule->i + rule->j;
	rule->steps = min_four(rr, rrr, ra_rrb, rra_rb);
	if (rule->steps == rr)
		rule->cases = 1;
	else if (rule->steps == rrr)
		rule->cases = 2;
	else if (rule->steps == ra_rrb)
		rule->cases = 3;
	else
		rule->cases = 4;
}
