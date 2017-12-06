/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuery <sjuery@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 04:03:38 by sjuery            #+#    #+#             */
/*   Updated: 2017/12/05 04:31:14 by sjuery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../srcs/libft/libft.h"
# include <stdarg.h>
# include <limits.h>
# include <stdint.h>
# include <wchar.h>
# include <unistd.h>
# include <stdlib.h>

typedef union				u_values
{
	char					c;
	char					*cp;
	int						i;
	long int				li;
	long long int			lli;
	unsigned long long int	ulli;
}							t_values;

typedef struct				s_printf
{
	int						len;
	int						ret;
	int						minus;
	int						plus;
	int						sharp;
	int						space;
	int						zero;
	int						size;
	int						precision;
	int						precise;
	int						per_cent;
	int						hh;
	int						h;
	int						ll;
	int						l;
	int						j;
	int						z;
	char					spec;
	char					*tmpstr;
	char					*str;
	char					c;
	long long int			arg;
	t_values				uvals;
}							t_printf;

typedef	struct				s_fpointer
{
	int						(*converter[126])(va_list args, t_printf *prtf);
}							t_fpointer;

int							ft_printf(const char *format, ...);
int							parse_input(va_list args, t_printf *prtf,
													t_fpointer *fptr);
char						*ft_itoa_base(unsigned long long int value,
													int base, int lowercase);
int							parse_flags(char *orgstr, t_printf *prtf);
void						flags_to_converter(t_fpointer *fptr);
int							parse_per(va_list args, t_printf *prtf);
int							print_ints(char *arg, t_printf *prtf, int octa);
int							print_sints(long long int arg,
													t_printf *prtf);
int							ft_print_unsigned_o_number(char *arg,
													t_printf *prtf);
int							parse_str(va_list args, t_printf *prtf);
int							parse_deci(va_list args, t_printf *prtf);
int							parse_char(va_list args, t_printf *prtf);
int							parse_octa(va_list args, t_printf *prtf);
int							parse_hexa(va_list args, t_printf *prtf);
int							parse_udeci(va_list args, t_printf *prtf);
int							print_char(char arg, t_printf *prtf);
int							print_str(t_printf *prtf);
char						*conv_octa(t_printf *prtf);
char						*conv_hexa(t_printf *prtf);
int							zero_minus_space(int size, char c, char zms);
char						*ft_strjoin_c(char c);
void						ft_putstr_n(char *s, int start, int len);
int							ft_strcmp(const char *s1, const char *s2);
char						*ft_strcat(char *s1, const char *s2);
char						*ft_strncpy(char *dst, const char *src, size_t n);
char						*ft_strnew(size_t size);
char						*conv_uni(wchar_t arg);
int							print_per(va_list pargs, t_printf *prtf);
int							size_sints(long long int arg, t_printf *prtf,
													int excep);

#endif
