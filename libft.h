/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:32:07 by echavez-          #+#    #+#             */
/*   Updated: 2023/03/09 19:50:39 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef unsigned char	t_byte;
typedef unsigned char	t_bool;

typedef struct s_doubly
{
	void			*obj;
	size_t			size;
	struct s_doubly	*prev;
	struct s_doubly	*next;
}					t_doubly;

typedef struct s_list
{
	void			*obj;
	size_t			size;
	struct s_list	*next;
}					t_list;

int			ft_isint(char *nb);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
size_t		ft_strlen(const char *str);
void		*ft_memset(void *s, int c, size_t n);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
int			ft_toupper(int c);
int			ft_tolower(int c);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strchr_pos(char *str, char c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_strcmp(char *s1, char *s2);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
char		*ft_strnstr(const char *s1, const char *s2, size_t len);
int			ft_atoi(const char *str);
void		*ft_calloc(size_t nmemb, size_t size);
char		*ft_strdup(const char *src);
char		*ft_fstrdup(char **fsrc, const char *src);
char		*ft_strndup(char const *src, int size);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
void		ft_freejoin(char **str);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		**ft_split_args(const char *s);
void		*ft_free_split(char ***split);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_putchar_fd(char c, int fd);
int			ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
int			ft_putnbr_base(int nbr, char *base);
uintmax_t	ft_uputnbr_base(uintmax_t nbr, char *base);
char		*ft_get_next_line(int fd);
int			ft_isspace(char c);
int			ft_puterror(char *start, char *cmd, char *end);
t_list		*ft_listnew(void *content, size_t size);
void		ft_listdel(t_list **head);
t_doubly	*ft_new_doubly(void *content, size_t size);
void		ft_push_doubly(t_doubly *new, t_doubly **start);
void		ft_append_doubly(t_doubly *new, t_doubly **start);
int			ft_perror(char *e, int n);
void		ft_deldoubly(t_doubly **start);
void		ft_decap_doubly(t_doubly **start);
void		ft_pop_doubly(t_doubly **start);

#endif
