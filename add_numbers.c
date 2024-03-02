/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 10:23:20 by smarsi            #+#    #+#             */
/*   Updated: 2024/02/27 22:48:54 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	add_numbers_into_linkedlist(char **numbers, t_stack	**stack_a)
{
	t_stack	*new_lst;
	int		i;
	int		nb;

	i = 0;
	while (numbers[i])
	{
		nb = ft_atoi(numbers[i]);
		printf("%d\n", nb);
		new_lst = ft_lstnew(nb);
		ft_lstadd_back(stack_a, new_lst);
		i++;
	}
}