/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 19:40:19 by anemesis          #+#    #+#             */
/*   Updated: 2022/03/13 21:12:37 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	presort_stack(t_stack *a)
{
	int		index;
	int		min;
	t_node	*ptr;

	index = 0;
	while (index < a->size)
	{
		ptr = a->head;
		while ((ptr->order != -1) && (index < a->size))
			ptr = ptr->next;
		min = ptr->val;
		while (ptr && (index < a->size))
		{
			if ((ptr->order == -1) && (ptr->val < min))
			{
				min = ptr->val;
				ptr->order = index;
				index++;
			}
			ptr = ptr->next;
		}
	}
}
