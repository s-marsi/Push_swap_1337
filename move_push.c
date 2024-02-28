/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 23:49:18 by smarsi            #+#    #+#             */
/*   Updated: 2024/02/28 08:48:44 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_stack(t_stack **src, t_stack **dst, char c)
{
	t_stack	*new;
	t_stack	*tmp;

	if (*src)
	{
		new = ft_lstnew((*src)->content);
		ft_lstadd_front(dst, new);
		tmp = *src;
		*src = (*src)->next;
		ft_lstdelone(tmp, NULL);
		if (c == 'a')
			write(1, "pa\n", 3);
		else
			write(1, "pb\n", 3);
	}
}
