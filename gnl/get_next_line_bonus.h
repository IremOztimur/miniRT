/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioztimur <ioztimur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:35:59 by ioztimur          #+#    #+#             */
/*   Updated: 2023/04/26 22:25:46 by ioztimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*get_next_line(int fd);
char	*gnl_strjoin(char *s1, char const *s2);
char	*gnl_strchr(char *s, int c);
size_t	gnl_strlen(const char *s);
char	*ft_get_line(char *left_str);
char	*ft_next_line(char	*left_str);
char	*ft_read_left(int fd, char *left_str);
char	*ft_error_check(char *left_str, char *buffer);

#endif
