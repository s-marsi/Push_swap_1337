/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:50:24 by smarsi            #+#    #+#             */
/*   Updated: 2024/03/05 18:56:03 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	check_is_number_no_dup(char	**numbers)
{
	long long	num;
	int			i;
	int			j;

	i = 0;
	check_dup (numbers);
	while (numbers[i])
	{
		check_int(numbers[i]);
		j = 0;
		while (numbers[i] && numbers[i][j])
		{
			num = numbers[i][j];
			if ((num == '-' || num == '+') && numbers[i][j + 1])
				j++;
			if (!ft_isdigit(num))
			{
				ft_free(numbers);
				write(2, "Error\n", 6);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

static char	**check_args(int ac, char *av[])
{
	char	**split_numbers;
	int		i;
	int		j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j] && (av[i][j] == ' ' || av[i][j] == '\t'))
			j++;
		if (!av[i][j])
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
	split_numbers = get_args(ac, av);
	check_is_number_no_dup(split_numbers);
	return (split_numbers);
}

static void	check_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	flag;

	flag = 1;
	if (stack_b)
		flag = 0;
	while (stack_a && stack_a->next)
	{
		if (stack_a->content > stack_a->next->content)
		{
			flag = 0;
			break ;
		}
		stack_a = stack_a->next;
	}
	if (flag == 1)
		write(1, "OK\n", 3);
	else
		write(0, "KO\n", 3);
}

void	get_do_move(t_stack **stack_a, t_stack **stack_b)
{
	char	*buff;
	t_stack	*a;
	t_stack	*b;

	buff = NULL;
	while (1)
	{
		buff = get_next_line(0);
		if (!buff)
			break ;
		do_move(stack_a, stack_b, buff);
		a = *stack_a;
		b = *stack_b;
		free(buff);
		buff = NULL;
	}
	check_sort(*stack_a, *stack_b);
}

int	main(int ac, char *av[])
{
	char	**split_numbers;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac >= 2)
	{
		stack_a = NULL;
		stack_b = NULL;
		split_numbers = check_args(ac, av);
		if (!split_numbers)
			return (0);
		add_numbers_into_linkedlist(split_numbers, &stack_a);
		ft_free(split_numbers);
		get_do_move(&stack_a, &stack_b);
		ft_lstclear(&stack_a, NULL);
		ft_lstclear(&stack_b, NULL);
	}
	return (0);
}
