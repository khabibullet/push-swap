/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_optimal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 20:49:41 by anemesis          #+#    #+#             */
/*   Updated: 2022/03/18 20:52:23 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push_optimal_to_a(t_stack *a, t_stack *b, t_rules *rule)
{
	if (rule->best_case == 1)
		rot_a_up_b_up(a, b, rule);
	else if (rule->best_case == 2)
		rot_a_down_b_down(a, b, rule);
	else if (rule->best_case == 3)
		rot_a_up_b_down(a, b, rule);
	else
		rot_a_down_b_up(a, b, rule);
	pa(a, b);
}

void	rot_a_up_b_up(t_stack *a, t_stack *b, t_rules *rule)
{
	while (rule->opt_i > 0 && rule->opt_j > 0)
	{
		rr(a, b);
		rule->opt_i--;
		rule->opt_j--;
	}
	if (rule->opt_j > 0)
	{
		while (rule->opt_j > 0)
		{
			rb(b);
			rule->opt_j--;
		}
	}
	if (rule->opt_i > 0)
	{
		while (rule->opt_i > 0)
		{
			ra(a);
			rule->opt_i--;
		}
	}
}

void	rot_a_down_b_down(t_stack *a, t_stack *b, t_rules *rule)
{
	while (rule->opt_i < a->size && rule->opt_j < b->size)
	{
		rrr(a, b);
		rule->opt_i++;
		rule->opt_j++;
	}
	if (rule->opt_j != b->size)
	{
		while (++rule->opt_j - 1 < b->size)
			rrb(b);
	}
	if (rule->opt_i != a->size)
	{
		while (++rule->opt_i - 1 < a->size)
			rra(a);
	}
}

void	rot_a_up_b_down(t_stack *a, t_stack *b, t_rules *rule)
{
	while (rule->opt_i > 0)
	{
		ra(a);
		rule->opt_i--;
	}
	while (rule->opt_j < b->size)
	{
		rrb(b);
		rule->opt_j++;
	}
}

void	rot_a_down_b_up(t_stack *a, t_stack *b, t_rules *rule)
{
	while (rule->opt_i < a->size)
	{
		rra(a);
		rule->opt_i++;
	}
	while (rule->opt_j > 0)
	{
		rb(b);
		rule->opt_j--;
	}
}
