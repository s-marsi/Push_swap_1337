/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 23:49:18 by smarsi            #+#    #+#             */
/*   Updated: 2024/03/05 19:11:18 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_stack(t_stack **src, t_stack **dst, char c)
{
	t_stack	*new;
	t_stack	*tmp;

	if (*src)
	{
		new = *src;
		tmp = (*src)->next;
		ft_lstadd_front(dst, new);
		*src = tmp;
		if (c == 'a')
			write(1, "pa\n", 3);
		else if (c == 'b')
			write(1, "pb\n", 3);
	}
}
