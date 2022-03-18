/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 20:57:27 by anemesis          #+#    #+#             */
/*   Updated: 2022/03/18 21:01:44 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	exit_success(t_stack *a, t_stack *b)
{
	delete_stack(&a);
	delete_stack(&b);
	exit(EXIT_SUCCESS);
}

void	print_stacks(t_stack *a, t_stack *b)
{
	t_node	*tmp;

	tmp = a->head;
	ft_printf("a:");
	while (tmp)
	{
		ft_printf("%d(%d) ", tmp->val, tmp->order);
		tmp = tmp->next;
	}
	tmp = b->head;
	ft_printf("\nb:");
	while (tmp)
	{
		ft_printf("%d(%d) ", tmp->val, tmp->order);
		tmp = tmp->next;
	}
	ft_printf("\n");
}

void	presort_stack(t_stack *a)
{
	int		index;
	t_node	*ptr;
	t_node	*ptr_min;

	index = 0;
	while (index < a->size)
	{
		ptr = a->head;
		while (ptr->order != -1)
			ptr = ptr->next;
		ptr_min = ptr;
		while (ptr)
		{
			if ((ptr->order == -1) && (ptr->val < ptr_min->val))
				ptr_min = ptr;
			ptr = ptr->next;
		}
		ptr_min->order = index;
		index++;
	}
}
