/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:50:45 by smarsi            #+#    #+#             */
/*   Updated: 2024/03/05 19:19:35 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"
# include "push_swap.h"

char	*get_next_line(int fd);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strjoin_next(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
char	*read_all(int fd, char *last);

#endif