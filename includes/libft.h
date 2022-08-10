/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knerini <knerini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 20:17:03 by knerini           #+#    #+#             */
/*   Updated: 2022/07/18 20:41:10 by knerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

// LIBFT

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);

void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);

void	ft_bzero(void *str, size_t n);
void	*ft_calloc(size_t nb, size_t mem);
void	*ft_memchr(void const *str, int c, size_t n);
void	*ft_memcpy(void *dest, void const *src, size_t n);
void	*ft_memmove(void *dest, char const *src, size_t n);
void	*ft_memset(void *str, int c, size_t n);
int		ft_memcmp(void const *s1, void const *s2, size_t n);

void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_base(long long int nb, size_t base, const char *str);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);

char	**ft_split(char const *s, char c);
char	*ft_strchr(char const *str, int c);
char	*ft_strdup(char const *s1);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strnstr(char const *str, char const *to_find, size_t n);
char	*ft_strrchr(char const *str, int c);
char	*ft_strtrim(const char *s1, const char *set);
char	*ft_substr(const char *s, unsigned int start, size_t len);
void	ft_striteri(char *s, void (*f)(unsigned int i, char*));
int		ft_nbrlen_base(long long int nb, size_t base, const char *str);
int		ft_strncmp(char const *s1, char const *s2, size_t n);
size_t	ft_strlcat(char *dest, char const *src, size_t destsize);
size_t	ft_strlcpy(char *dest, char const *src, size_t destsize);
size_t	ft_strlen(char const *str);

int		ft_atoi(char const *nbr);
int		ft_tolower(int c);
int		ft_toupper(int c);
char	*ft_itoa(int n);

//FT_PRINTF

typedef struct s_format
{
	int	len;
	int	width;
}	t_format;

const char	*ft_check_conversion(va_list args, const char *str, t_format *s);
const char	*ft_write_string(const char *str, t_format *s);

int	ft_printf(const char *str, ...);

void	ft_convert_c(va_list args, t_format *s);
void	ft_convert_di(va_list args, t_format *s, const char *str);
void	ft_convert_p(va_list args, t_format *s, const char *str);
void	ft_convert_s(va_list args, t_format *s);
void	ft_convert_u(va_list args, t_format *s, const char *str);
void	ft_convert_x(va_list args, t_format *s, const char *str);

//GET_NEXT_lINE

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5

#endif

char	*get_next_line(int fd);
char	*gnl_get_line(char *stock);
char	*gnl_read_and_join(int fd, char *stock);
char	*gnl_save(char *stock);
char	*gnl_strdup(char *str);
char	*gnl_strjoin(char *stock, char *temp);
char	*gnl_strchr(char *str, int c);

#endif
