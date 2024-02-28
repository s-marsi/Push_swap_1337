/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:37:00 by smarsi            #+#    #+#             */
/*   Updated: 2024/02/28 13:43:55 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"

void	add_numbers_into_linkedlist(char **numbers, t_stack	**stack_a);
void	check_dup(char **numbers);
void	push_stack(t_stack **src, t_stack **dst, char c);
void	swap(t_stack **stack, char c);
void	swap_s(t_stack **stack_a, t_stack **stack_b);
void	rotate(t_stack **stack, char c);
void	rotate_r(t_stack **stack_a, t_stack **stack_b);
void	r_rotate(t_stack **stack, char c);
void	r_rotate_r(t_stack **stack_a, t_stack **stack_b);
#endif