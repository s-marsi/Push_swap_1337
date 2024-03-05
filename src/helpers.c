/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 13:25:41 by smarsi            #+#    #+#             */
/*   Updated: 2024/03/05 19:21:25 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_free(char **s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		free(s[i]);
		s[i++] = NULL;
	}
	free(s);
	s = NULL;
}

void	check_dup(char **numbers)
{
	int	i;
	int	j;

	i = 0;
	if (numbers[i])
	{
		while (numbers[i])
		{
			j = i + 1;
			while (numbers[j])
			{
				if (ft_atoi(numbers[j]) == ft_atoi(numbers[i]))
				{
					write(2, "Error\n", 6);
					ft_free(numbers);
					exit(1);
				}
				j++;
			}
			i++;
		}
	}
}

static char	*remove_tab(char *str)
{
	char	*new;
	char	**str_split;
	char	*tmp;
	int		i;

	str_split = ft_split(str, '\t');
	if (!str_split)
		return (NULL);
	free(str);
	new = NULL;
	i = 0;
	while (str_split[i])
	{
		tmp = ft_strjoin(new, " ");
		new = ft_strjoin(tmp, str_split[i++]);
	}
	ft_free(str_split);
	return (new);
}

char	**get_args(int ac, char *av[])
{
	char	**split_numbers;
	char	*numbers;
	int		i;

	numbers = NULL;
	if (ac >= 2)
	{
		i = 1;
		while (i < ac)
		{
			numbers = ft_strjoin(numbers, " ");
			numbers = ft_strjoin(numbers, av[i]);
			i++;
		}
	}
	numbers = remove_tab(numbers);
	split_numbers = ft_split(numbers, ' ');
	free(numbers);
	numbers = NULL;
	return (split_numbers);
}

int	is_sort(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->content > stack->next->content)
			return (1);
		stack = stack->next;
	}
	return (0);
}
