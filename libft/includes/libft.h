/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 15:27:37 by lazrossi          #+#    #+#             */
/*   Updated: 2018/09/04 11:29:33 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <inttypes.h>
# include "printf.h"

# define BUFF_SIZE 4096
# define RESET_PRINTF "\x1B[0m"
# define BLD "\x1B[1m"
# define ITA "\x1B[3m"
# define BLK "\x1B[6m"
# define SWP "\x1B[7m"
# define UND "\x1B[4m"
# define RED "\x1B[31m"
# define GRN "\x1B[32m"
# define YEL "\x1B[33m"
# define BLU "\x1B[34m"
# define MAG "\x1B[35m"
# define CYN "\x1B[36m"
# define WHT "\x1B[37m"
# define BCK "\x1B[40m"
# define FRM "\x1B[51m"

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_str
{
	int		position;
	char	str[BUFF_SIZE];
}					t_str;

typedef struct		s_printf
{
	int				arg_len;
	int				activate_precision;
	char			percentage_presence;
	char			type;
	char			zeros_width;
	char			modifier[3];
	char			sign[3];
	char			left_align_output;
	char			show_sign;
	char			sharp;
	int				width;
	int				precision;
	t_str			*argument_str;
}					t_printf;

typedef struct		s_color_compound
{
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
	int				rgb;
}					t_color_compound;

typedef	struct		s_gnl
{
	char			*rest;
	int				fd;
	struct s_gnl	*next;
}					t_gnl;

int					get_next_line(const int fd, char **line, char tofind);
int					get_char_len(va_list ap, t_printf *argument);
int					get_number_len(va_list ap, t_printf *argument);
void				update_str(t_str *argument, void *to_cpy, int mem_op_size);
int					get_precision(va_list ap, t_printf *argument,
		const char *format);
int					get_width(va_list ap, t_printf *argument,
		const char *format);
int					get_flags(t_printf *argument, const char	*format);
int					get_modifier(t_printf *argument, const char	*format);
int					ft_printf(const char *restrict format, ...);
void				store_char_data(va_list ap, t_printf *argument,
		t_str *argument_str);
void				store_number_data(va_list ap, t_printf *argument);
const char			*parse(const char *format, t_printf *argument, va_list ap);
void				get_hex_ptr_adr(va_list ap, t_printf *argument);
void				apply_width(t_printf *argument, t_str *argument_str);
void				apply_flag_padding(t_printf *argument, t_str *argument_str);
void				apply_plus_minus_flags(t_printf *argument,
		t_str *argument_str);
void				apply_precision(t_printf *argument, t_str *argument_str);
void				apply_sharp(t_printf *argument_specs, t_str *argument_str);
void				printf_u_base_converter(int base_size, uintmax_t number,
		int sizeof_var, t_printf *argument);
int					u_base_converter_len(int base_size,
		uintmax_t number, int sizeof_var, t_printf *argument);
int					s_base_converter_len(int base_size,
		intmax_t number, int sizeof_var, t_printf *argument);
unsigned long long	take_out_bits(uintmax_t to_change, int sizeof_var);
intmax_t			convert_overflow(int sizeof_var, intmax_t number);
void				printf_s_base_converter(int base_size, intmax_t number,
		int sizeof_var, t_printf *argument);
int					set_get_return(int action);
void				store_unicode_str(wchar_t *data, t_str *argument_str,
		t_printf *argument);
void				store_unicode(wint_t data, int precision,
		t_str *argument_str);
const char			*terminal_formatting(const char	*format, t_str *argument);
int					launch_string_print(const char *format, va_list ap,
		t_str *argument_str, int flush);
int					set_get_fd(int action);
const char			*choose_set_file_descriptor(const char *format,
		t_str *argument);
void				apply_precision_width(t_printf *argument_specs,
		t_str *argument_str);
t_printf			initialize_elem(void);
void				treat_and_store_argument(va_list ap,
		t_printf *argument_specs,
					t_str *argument_str);
const char			*store_string(const char *format, t_str *argument_str);

void				ft_putstr(char *str);
char				*ft_strdiff(char *str, char c, int size);
int					ft_str_is_printable(char *str);
char				*ft_itoa(int nbr);
char				*ft_ltoa(intmax_t nbr);
int					ft_atoi(const char *str);
double				ft_atof(const char *nptr);
void				ft_putchar(char c);
char				*ft_strdup(const char *s1);
char				*ft_strndup(const char *s1, size_t n);
char				*ft_strndup_free(char **src, size_t n);
char				*ft_strncpy(char *dest, char *src, unsigned int n);
char				*ft_strcat(char *dest, char *src);
size_t				ft_strlen(const char *str);
char				*ft_strcpy(char *dest, char *src);
char				*ft_strncat(char *dest, char *src, int nb);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *haystack, \
		const char *needle, size_t n);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strstrchr(char *haystack, char *needle, char stop);
char				*ft_strstrstr(char *haystack, char *needle, char *stop);
char				*ft_strstr_whilestr(char *haystack, char *needle, char *go);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
void				*ft_memmove(void *dst, const void *src, size_t len);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_str_isalpha(char *str);
void				ft_str_mins_to_caps(char *c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				ft_striter(char *s, void (*f)(char *));
void				ft_mystriter(char **s, char (*f)(char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
void				ft_putend(char const *s);
void				ft_putnbr(int n);
char				**ft_strsplit(char const *str, char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_int_size(int nbr);
int					ft_double_size(double nbr);
char				**ft_split_whitespaces(char *str);
char				**ft_split_char(char *str, char c);
char				**ft_split_whitespaces_nokots(char *str);
char				*ft_strjoinfree(char **s1, char **s2, char a);
void				ft_putabs(char**str, char separator);
int					get_next_line(const int fd, char **line, char tofind);
int					ft_advance_str_for_quotes(char *str, int i);
char				*ft_strdup_to_quote(char *src, char *dst);
char				*ft_make_blocks_for_quotes(char *str, int *i);
void				ft_tabdel(void	***str);
char				**ft_tabdup(char **str, int size);
int					ft_tabsize(char **tab);
void				ft_putwhites(int i);
char				**ft_tabdup_and_add(char **tab, char *str);
char				**ft_tabdup_add_free(char ***tab, char **str, char which);
char				*ft_strjoinfree_str_char(char **s1, char s2);
char				*ft_strjoinfree_one(char **s1, char *s2, char where);
char				*ft_strjoinfree_char_str(char s2, char **s1);
char				*ft_joinfree_heapstr_stackstr(char **s1, char *s2,
		char where);
char				*ft_strdupfrom_free(const char **str, int from);
char				**ft_tab_replacestr(char ***tab, char **str, char *cmp);
int					int_ft_putchar(int c);
void				debug();
int					ft_put_fatal_error(char *str);
void				*ft_put_error_return_null(char *error_msg,
		char *function_name);
void				ft_myexit(char	*str);
void				ft_del_tab_str(void	***tab, void	**str);
char				*ft_s_base_converter(int base_size, intmax_t number);
char				*ft_u_base_converter(int base_size,
		uintmax_t number, int sizeof_var);
char				ft_mins_to_caps(char c);
void				*ft_symetric_byte_swap(void	*ptr, int size);
int					ft_check_endianness(void);
char				*print_bits(void *ptr, int size);
t_color_compound	ft_decompose_color(int color);
void				find_arg_len(va_list ap, t_printf *argument_specs);
void				parsing_handler(const char *format,
		va_list ap, t_str *argument_str);
int					ft_dprintf(int fd, const char *restrict format, ...);
#endif
