/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 13:25:41 by smarsi            #+#    #+#             */
/*   Updated: 2024/02/25 13:41:09 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_dup(char	**numbers)
{
	int	i;
	int	j;

	i = 0;
	while (numbers[i])
	{
		j = i + 1;
		while (numbers[j])
		{
			if (ft_atoi(numbers[j]) == ft_atoi(numbers[i]))
			{
				write(2, "Error: Duplicate number ", 24);
				write(2, numbers[j], ft_strlen(numbers[j]));
				write(2, " found\n", 7);
				exit(1);
			}
			j++;
		}
		i++;
	}
}
