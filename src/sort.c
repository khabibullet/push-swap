/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:36:30 by anemesis          #+#    #+#             */
/*   Updated: 2022/03/17 21:34:02 by anemesis         ###   ########.fr       */
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

int	find_i_in_a(t_stack *a, int order)
{
	t_node	*ptr;
	int		i;

	ptr = a->head;
	i = 0;
	while (order > ptr->order)
	{
		ptr = ptr->next;
		i++;
	}
	return (i);
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

t_rules	count_rules_for_j(int sza, int szb, int i, int j)
{
	t_rules	rule;

	rule.rr = ft_max(i, j);
	rule.rrr = ft_max(sza - i, szb - j);
	rule.ra_rrb = szb - j + i;
	rule.rra_rb = sza - i + j;
	rule.steps = min_four(rule.rr, rule.rr, rule.ra_rrb, rule.rra_rb);
	if (rule.steps == rule.rr)
		rule.cases = 1;
	else if (rule.steps == rule.rrr)
		rule.cases = 2;
	else if (rule.steps == rule.ra_rrb)
		rule.cases = 3;
	else
		rule.cases = 4;
	return (rule);
}

void	rot_a_up_b_up(t_stack *a, t_stack *b, t_rules *rule)
{
	while (rule->opt_i-- + 1 > 0 && rule->opt_j-- + 1 > 0)
		rr(a, b);
	if (rule->opt_j != 0)
	{
		while (rule->opt_j-- + 1)
			rb(b);
	}
	if (rule->opt_i != 0)
	{
		while (rule->opt_i-- + 1)
			ra(b);
	}
}

void	rot_a_down_b_down(t_stack *a, t_stack *b, t_rules *rule)
{
	while (rule->opt_i++ - 1 < a->size && rule->opt_j++ - 1 < b->size)
		rrr(a, b);
	if (rule->opt_j != b->size)
	{
		while (rule->opt_j++ - 1 < b->size)
			rrb(b);
	}
	if (rule->opt_i != a->size)
	{
		while (rule->opt_i++ - 1 < a->size)
			rra(b);
	}
}

void	rot_differ_direction(t_stack *a, t_stack *b, t_rules *rule)
{
	if (rule->cases == 3)
	{
		while (rule->opt_i-- + 1 > 0)
			ra(a);
		while (rule->opt_j++ - 1 < b->size)
			rrb(b);
	}
	else
	{
		while (rule->opt_i++ - 1 < a->size)
			rra(a);
		while (rule->opt_j-- + 1 > 0)
			rb(b);
	}
}

void	push_optimal_to_a(t_stack *a, t_stack *b, t_rules *rule)
{
	if (rule->cases == 1)
		rot_a_up_b_up(a, b, rule);
	else if (rule->cases == 2)
		rot_a_down_b_down(a, b, rule);
	else
		rot_differ_direction(a, b, rule);
	pa(a, b);
}

void	sort_to_a(t_stack *a, t_stack *b)
{
	t_node	*ptr;
	t_rules	rule;
	int		i;
	int		j;
	int		min_steps;

	while (b->size)
	{
		ptr = b->head;
		j = 0;
		while (ptr)
		{
			i = find_i_in_a(a, ptr->order);
			ft_printf("%d - %d\n", i, ptr->order);
			rule = count_rules_for_j(a->size, b->size, i, j);
			if (ptr == b->head || min_steps > rule.steps)
			{
				min_steps = rule.steps;
				rule.opt_j = j;
				rule.opt_i = i;
			}
			j++;
			ptr = ptr->next;
		}
		ft_printf("%d - %d\n", rule.opt_i, rule.opt_j);
		return ;
		push_optimal_to_a(a, b, &rule);
	}
}

void	launch_algo(t_stack *a, t_stack *b)
{
	issorted(a, b);
	push_median(a, b);
	sort_to_b(a, b);
	sort_to_a(a, b);
}
