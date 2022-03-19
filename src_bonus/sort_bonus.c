/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 14:35:13 by anemesis          #+#    #+#             */
/*   Updated: 2022/03/19 16:23:11 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

void	issorted_bonus(t_stack *a, t_stack *b)
{
	t_node	*ptr;

	ptr = a->head;
	while (ptr->next)
	{
		if (ptr->val > ptr->next->val)
		{
			ft_printf("KO\n");
			exit_success(a, b);
		}
		ptr = ptr->next;
	}
	if (!b->size)
	{
		ft_printf("OK\n");
		exit_success(a, b);
	}
}

void	check_rule(t_stack *a, t_stack *b, char *str)
{
	if (!ft_strncmp(str, "ra\n", 3))
		ra_silent(a);
	else if (!ft_strncmp(str, "rb\n", 3))
		rb_silent(b);
	else if (!ft_strncmp(str, "rr\n", 3))
		rr_silent(a, b);
	else if (!ft_strncmp(str, "rra\n", 4))
		rra_silent(a);
	else if (!ft_strncmp(str, "rrb\n", 4))
		rrb_silent(b);
	else if (!ft_strncmp(str, "rrr\n", 4))
		rrr_silent(a, b);
	else if (!ft_strncmp(str, "pa\n", 3))
		pa_silent(a, b);
	else if (!ft_strncmp(str, "pb\n", 3))
		pb_silent(a, b);
	else if (!ft_strncmp(str, "sa\n", 3))
		sa_silent(a);
	else if (!ft_strncmp(str, "sb\n", 3))
		sb_silent(b);
	else if (!ft_strncmp(str, "ss\n", 3))
		ss_silent(a, b);
	else
		exit_error();
}
