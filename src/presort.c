/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 19:40:19 by anemesis          #+#    #+#             */
/*   Updated: 2022/03/14 19:26:16 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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
