/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:29:06 by ioztimur          #+#    #+#             */
/*   Updated: 2024/02/08 20:45:59 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
#include <stdbool.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_vector
{
	uint32_t	size;
	void		(*del)(void *);
	void		*(*cpy)(void *);
	void		(*print)(void *);
	void		**array;
}	t_vector;

int			ft_isalpha(int c);
int			ft_isdigit(int c);
size_t		ft_strlen(const char *s);
int			ft_atoi(const char *str);
void		ft_bzero(void *s, size_t n);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memset(void *b, int c, size_t len);
void		*ft_memmove(void *dst, const void *src, size_t len);
char		*ft_strchr(const char *s, int c);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_strrchr(const char *s, int c);
int			ft_tolower(int c);
int			ft_toupper(int c);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
int			ft_atoi(const char *str);
void		*ft_calloc(size_t count, size_t size);
char		*ft_strdup(const char *s1);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_strtrim(char const *s1, char const *set);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_putstr_fd(char	*s, int fd);
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
char 		**ft_split(char const *s, char c);
char		*ft_itoa(int    n);
t_list		*ft_lstnew(void *content);
void 		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void		ft_putnbr_fd(int n, int fd);
int			ft_clamp(int n, int min, int max);
void		ft_free(void *ptr);
void		ft_vector_clear(t_vector *vector);
void		ft_vector_delete(t_vector *vector);
t_vector	*ft_vector_new(void *(*cpy)(), void (*del)(void *), void (*print)(void *));
void		ft_vector_pop(t_vector *vector);
void		ft_vector_push(t_vector *vector, void *element);
void		ft_matrix_delete(void *matrix, void (*del)(void *));
size_t		ft_matrix_size(void *matrix);
void		*ft_matrix_append(void *matrix, void *data, void *(*copy)(void *));
void		*ft_matrix_new(size_t lines, size_t columns);
int			ft_strcmp(char *s1, char *s2);
int			ft_count(char *str, char c);
double		ft_atod(char *str);
bool		ft_isnum(char *str, char *delims);
size_t		ft_strclen(char *str, char *delim);
void		*ft_vector_at(t_vector *vector, uint32_t i);

#endif
