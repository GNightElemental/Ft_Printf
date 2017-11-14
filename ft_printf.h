/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuery <sjuery@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 13:30:59 by sjuery            #+#    #+#             */
/*   Updated: 2017/11/13 17:26:54 by sjuery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include "libft/libft.h"

typedef union   uval
{
	char					chr;
	char					*str;
    wchar_t                 *wchar;
	intmax_t				super;
	uintmax_t				super_u;
    void					*ptr;
}               uval;

int ft_printf(const char *orgstr, ...);
char	*wint_to_str(wchar_t wint);
char	*wstr_to_str(wchar_t *wstr);

#endif
