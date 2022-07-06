/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:11:07 by evanha-p          #+#    #+#             */
/*   Updated: 2021/12/16 20:15:23 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>

# define INT_MAX_LEN 12

typedef struct s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void	*ft_memset(void *source, int c, size_t len);
void	ft_bzero(void *source, size_t len);
void	*ft_memcpy(void *dest, const void *source, size_t len);
void	*ft_memccpy(void *dest, const void *source, int c, size_t len);
void	*ft_memmove(void *destination, const void *source, size_t length);
void	*ft_memchr(const void *str, int wanted, size_t length);
int		ft_memcmp(const void *s1, const void *s2, size_t length);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *source);
char	*ft_strcpy(char *dest, const char *source);
char	*ft_strncpy(char *dest, const char *source, size_t len);
char	*ft_strcat(char *dest, const char *source);
char	*ft_strncat(char *dest, const char *source, size_t len);
size_t	ft_strlcat(char *dest, const char *source, size_t destSize);
char	*ft_strchr(const char *str, int wanted);
char	*ft_strrchr(const char *str, int wanted);
char	*ft_strstr(const char *picture, const char *waldo);
char	*ft_strnstr(const char *picture, const char *waldo, size_t length);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t length);
int		ft_atoi(const char *str);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
void	*ft_memalloc(size_t size);
void	ft_memdel(void **ap);
char	*ft_strnew(size_t size);
void	ft_strdel(char **as);
void	ft_strclr(char *str);
void	ft_striter(char *str, void (*f)(char *));
void	ft_striteri(char *str, void (*f)(unsigned int, char *));
char	*ft_strmap(char const *str, char (*f)(char));
char	*ft_strmapi(char const *str, char (*f)(unsigned int, char));
int		ft_strequ(char const *str1, char const *str2);
int		ft_strnequ(char const *str1, char const *str2, size_t len);
char	*ft_strsub(char const *string, unsigned int start, size_t len);
char	*ft_strjoin(char const *str1, char const *str2);
char	*ft_strtrim(char const *str);
char	**ft_strsplit(char const *str, char deli);
char	*ft_itoa(int nb);
void	ft_putchar(char c);
void	ft_putstr(char const *str);
void	ft_putendl(char const *str);
void	ft_putnbr(int nb);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char const *str, int fd);
void	ft_putendl_fd(char const *str, int fd);
void	ft_putnbr_fd(int nb, int fd);
t_list	*ft_lstnew(void const *content, size_t content_size);
void	ft_lstdelone(t_list **node, void (*del)(void *, size_t));
void	ft_lstdel(t_list **node, void (*del)(void *, size_t));
void	ft_lstadd(t_list **first, t_list *new);
void	ft_lstiter(t_list *list, void (*f)(t_list *elem));
t_list	*ft_lstmap(t_list *list, t_list *(*f)(t_list *elem));
int		ft_iswspace(char c);
void	ft_lstpurge(t_list *list);
t_list	*ft_lstcleaner(t_list *list);
int		ft_countnodes(t_list *list);
char	**ft_arrclean(char **arr);

#endif
