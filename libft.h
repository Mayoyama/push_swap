/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thours <thours@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 10:54:07 by thours            #+#    #+#             */
/*   Updated: 2026/05/02 12:41:46 by thours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/**** INCLUDES ****/
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

/**** CHAINED LIST STRUCT ****/
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/**** FLAGS STRUCT FOR PRINTF ****/
typedef struct s_flags
{
	int	aff_left;
	int	fill_zero;
	int	aff_sign;
	int	spc_for_pos;
	int	prefix;
	int	precision;
	int	width;
	int	sign_written;
}	t_flags;

/**** LIBC FUNCTIONS ****/
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
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
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
char		*ft_strnstr(const char *big, const char *little, size_t len);
int			ft_atoi(const char *nptr);
void		*ft_calloc(size_t nmemb, size_t size);
char		*ft_strdup(const char *s);

/*** ADDITIONNAL FUNCTIONS ****/
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

/**** CHAINED LIST FUNCTIONS ****/
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/*************************************/
/******** FT_PRINTF FUNCTIONS ********/
/*************************************/

/**** PRINT INPUT ****/
int			parse_str(const char *str, va_list *ap);
int			handle_arg(char c, t_flags *flags, va_list *ap);
int			ft_printf(const char *str, ...);

/**** FLAG UTILS FUNCTIONS ****/
int			is_flag(char c);
int			is_param(char c);
int			is_conversion(char c);

/**** GET FLAGS FUNCTIONS ****/
t_flags		*initialize_flags(void);
t_flags		*create_flag_struct(char *str);
t_flags		*get_params(t_flags *flags, char *str);
t_flags		*get_flag(t_flags *flags, char c);

/**** MANAGE INTS ****/
int			get_int_len(int n);
int			get_int_expr_size(int num, t_flags *flags);
int			print_int(int num, t_flags *flags);

/**** MANAGE UNSIGNED INTS ****/
int			get_unsigned_int_len(unsigned int n);
int			get_unsigned_expr_size(unsigned int num, t_flags *flags);
int			print_unsigned_int(unsigned int num, t_flags *flags);

/**** MANAGE HEX NUMS ****/
int			get_hexnum_len(unsigned int n);
int			get_hex_expr_size(unsigned int num, t_flags *flags);
int			print_hexa(unsigned int num, t_flags *flags, int upper);

/**** MANAGE CHARS ****/
int			print_char(char c, t_flags *flags);

/**** MANAGE STRS ****/
int			print_str(char *str, t_flags *flags);

/**** MANAGE MEMORY ****/
int			print_mem(void *ptr, t_flags *flags);

/**** STD LIB FUNCTIONS ****/
int			ft_isspace(char c);
int			ft_strlen_int(char *str);

/**** PRINT FUNCTIONS ****/
void		ft_putnbr(int n);
void		ft_putnbr_unsigned(unsigned int nb);
void		ft_putstr(char *str);
void		put_hex_nbr(unsigned long n, int upper);

/*************************************/
/********** FT_GNL FUNCTIONS *********/
/*************************************/

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char		*get_next_line(int fd);
char		*get_file_content(char *stored, int fd);
char		*clear_prev_line(char *stored);

/**** UTILS ****/
int			contain_full_line(char *stored);
char		*ft_strjoin_gnl(char *stored, char *buffer);
char		*ft_extract_line(char *str);
char		*ft_strcpy(char *dest, char *src);

#endif
