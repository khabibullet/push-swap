/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 19:23:11 by anemesis          #+#    #+#             */
/*   Updated: 2022/03/19 15:11:44 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include "push_swap.h"

void	issorted_bonus(t_stack *a, t_stack *b);
void	check_rule(t_stack *a, t_stack *b, char *str);

void	pa_silent(t_stack *a, t_stack *b);
void	pb_silent(t_stack *a, t_stack *b);
void	sa_silent(t_stack *a);
void	sb_silent(t_stack *b);
void	ss_silent(t_stack *a, t_stack *b);
void	ra_silent(t_stack *a);
void	rb_silent(t_stack *b);
void	rr_silent(t_stack *a, t_stack *b);
void	rra_silent(t_stack *a);
void	rrb_silent(t_stack *b);
void	rrr_silent(t_stack *a, t_stack *b);

#endif
