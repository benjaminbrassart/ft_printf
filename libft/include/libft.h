/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 09:37:02 by bbrassar          #+#    #+#             */
/*   Updated: 2021/06/23 00:54:25 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>

void		*ft_memset(void *b, int c, size_t len);

void		ft_bzero(void *s, size_t n);

void		*ft_memcpy(void *dst, void const *src, size_t len);

void		*ft_memccpy(void *dst, void const *src, int c, size_t n);

void		*ft_memmove(void *dst, void const *src, size_t len);

void		*ft_memchr(void const *s, int c, size_t n);

void		*ft_memrchr(void const *s, int c, size_t n);

void		*ft_rawmemchr(void const *s, int c);

int			ft_memcmp(void const *s1, void const *s2, size_t n);

size_t		ft_strlen(char const *s);

int			ft_isalpha(int c);

int			ft_isalnum(int c);

int			ft_isascii(int c);

int			ft_iscntrl(int c);

int			ft_isdigit(int c);

int			ft_isgraph(int c);

int			ft_islower(int c);

int			ft_isprint(int c);

int			ft_isspace(int c);

int			ft_isupper(int c);

int			ft_isxdigit(int c);

int			ft_tolower(int c);

int			ft_toupper(int c);

int			ft_strcmp(char const *s1, char const *s2);

char		*ft_strcpy(char *dst, char const *src);

char		*ft_strcat(char *dst, char const *src);

char		*ft_strstr(char const *haystack, char const *needle);

char		*ft_strchr(char const *s, int c);

char		*ft_strrchr(char const *s, int c);

size_t		ft_strcspn(char const *s, char const *set);

size_t		ft_strnlen(char const *s, size_t n);

int			ft_strncmp(char const *s1, char const *s2, size_t n);

char		*ft_strncpy(char *dst, char const *src, size_t n);

char		*ft_strncat(char *dst, char const *src, size_t n);

char		*ft_strndup(char const *s, size_t n);

size_t		ft_strlcpy(char *dst, char const *src, size_t dstsize);

size_t		ft_strlcat(char *dst, char const *src, size_t dstsize);

char		*ft_strnstr(char const *haystack, char const *needle, size_t len);

int			ft_atoi(char const *s);

long long	ft_atoll(char const *s);

int			ft_patoi(char const **s);

void		*ft_calloc(size_t count, size_t size);

char		*ft_strdup(char const *s);

char		*ft_substr(char const *s, unsigned int start, size_t len);

char		*ft_strjoin(char const *s1, char const *s2);

char		*ft_strtrim(char const *s, char const *set);

char		**ft_split(char const *s, char c);

char		*ft_itoa(int n);

char		*ft_lltoa(long long n);

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));

void		ft_putchar(char c);

void		ft_putchar_fd(char c, int fd);

void		ft_putstr(char const *s);

void		ft_putstr_fd(char const *s, int fd);

void		ft_putendl(char const *s);

void		ft_putendl_fd(char const *s, int fd);

void		ft_putnbr(int n);

void		ft_putnbr_fd(int n, int fd);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list		*ft_lstnew(void *content);

void		ft_lstadd_front(t_list **alst, t_list *elem);

int			ft_lstsize(t_list *lst);

t_list		*ft_lstlast(t_list *lst);

void		ft_lstadd_back(t_list **alst, t_list *elem);

void		ft_lstdelone(t_list *lst, void (*del)(void *));

void		ft_lstclear(t_list **lst, void (*del)(void *));

void		ft_lstiter(t_list *lst, void (*f)(t_list *));

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

char		*ft_strrepeat(char const *s, int times);

#endif
