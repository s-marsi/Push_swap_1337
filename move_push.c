/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 23:49:18 by smarsi            #+#    #+#             */
/*   Updated: 2024/03/04 07:40:46 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	push_stack(t_stack **src, t_stack **dst, char c)
// {
// 	t_stack	*tmp;

// 	if (*src)
// 	{
// 		tmp = (*src)->next;
// 		tmp = NULL;
// 		ft_lstadd_front(dst, tmp);
// 		*src = (*src)->next;
// 		if (c == 'a')
// 			write(1, "pa\n", 3);
// 		else
// 			write(1, "pb\n", 3);
// 	}
// }

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
        else
            write(1, "pb\n", 3);
    }
}