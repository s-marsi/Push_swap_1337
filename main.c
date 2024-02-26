/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:35:23 by smarsi            #+#    #+#             */
/*   Updated: 2024/02/26 12:27:14 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	ft_free(char **s)
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

void	check_is_number_no_dup(char	**numbers)
{
	int	i;
	int	j;

	i = 0;
	check_dup(numbers);
	while (numbers[i])
	{
		j = 0;
		while (numbers[i] && numbers[i][j])
		{
			if (!isdigit(numbers[i][j]) &&
				!(numbers[i][j++] == '-' && isdigit(numbers[i][j]) &&
				numbers[i][j] != '0'))
			{
				write(2, "Error: Please enter a valid number.\n", 36);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

static char	*remove_tab(char *str)
{
	char	*new;
	char	**tmp;
	int		i;

	tmp = ft_split(str, '\t');
	free(str);
	new = NULL;
	i = 0;
	while (tmp[i])
	{
		new = ft_strjoin(new, " ");
		new = ft_strjoin(new, tmp[i++]);
	}
	ft_free(tmp);
	return (new);
}

static char	**get_args(int ac, char *av[])
{
	char	**split_numbers;
	char	*numbers;
	int		i;

	numbers = ft_strdup(av[1]);
	if (ac > 2)
	{
		i = 2;
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

int	main(int ac, char *av[])
{
	char	**split_numbers;
	t_stack	*stack_a;

	stack_a = NULL;
	if (ac < 2)
	{
		write(2, "need more that 1 args", ft_strlen("need more that 1 args"));
		exit(1);
	}
	split_numbers = get_args(ac, av);
	if (!split_numbers)
	{
		write(2, "at least one numbern", 23);
		exit(1);
	}
	check_is_number_no_dup(split_numbers);
	add_numbers_into_linkedlist(split_numbers, &stack_a);
	while (stack_a)
	{
		printf("%d\n", stack_a->content);
		stack_a = stack_a->next;
	}
	ft_free(split_numbers);
	return (0);
}
