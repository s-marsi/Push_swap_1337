/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:05:40 by smarsi            #+#    #+#             */
/*   Updated: 2024/03/05 19:21:11 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	if (!s1 || !s2)
		return (1);
	while ((*s1 && *s2) && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	ft_error(t_stack **stack_a, t_stack **stack_b)
{
	write(2, "Error\n", 6);
	ft_lstclear(stack_a, NULL);
	ft_lstclear(stack_b, NULL);
	exit (1);
}

void	do_move(t_stack **stack_a, t_stack **stack_b, char *buff)
{
	if (ft_strcmp(buff, "sa\n") == 0)
		swap(stack_a, 'k');
	else if (ft_strcmp(buff, "sb\n") == 0)
		swap(stack_b, 'k');
	else if (ft_strcmp(buff, "ss\n") == 0)
		swap_s(stack_a, stack_b, 'k');
	else if (ft_strcmp(buff, "pa\n") == 0)
		push_stack(stack_b, stack_a, 'k');
	else if (ft_strcmp(buff, "pb\n") == 0)
		push_stack(stack_a, stack_b, 'k');
	else if (ft_strcmp(buff, "ra\n") == 0)
		rotate(stack_a, 'k');
	else if (ft_strcmp(buff, "rb\n") == 0)
		rotate(stack_b, 'k');
	else if (ft_strcmp(buff, "rr\n") == 0)
		rotate_r(stack_a, stack_b, 'k');
	else if (ft_strcmp(buff, "rra\n") == 0)
		r_rotate(stack_a, 'k');
	else if (ft_strcmp(buff, "rrb\n") == 0)
		r_rotate(stack_b, 'k');
	else if (ft_strcmp(buff, "rrr\n") == 0)
		r_rotate_r(stack_a, stack_b, 'k');
	else
		ft_error(stack_a, stack_b);
}
