/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuery <sjuery@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 13:31:04 by sjuery            #+#    #+#             */
/*   Updated: 2017/11/02 15:38:41 by sjuery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "ft_printf.h"

int flag_handler(char flag, va_list args)
{
	int itmp;
	long unsigned int luitmp;
	char ctmp, *pctmp;
	wchar_t wctmp;

	if(flag == 's')
	{
		pctmp = va_arg(args, char *);
		ft_putstr(pctmp);
	}
	if(flag == 'C')
	{
		wctmp = va_arg(args, wchar_t);
		pctmp = ft_uni2utf8(wctmp);
		ft_putstr(pctmp);
	}
	else if (flag == 'c')
	{
		ctmp = va_arg(args, int);
		ft_putchar(ctmp);
	}
	else if (flag == 'd' || flag == 'i')
	{
		itmp = va_arg(args, int);
		ft_putnbr(itmp);
	}
	else if (flag == 'p')
	{
		luitmp = va_arg(args, long unsigned int);
		ft_putstr("0x");
		pctmp = ft_itoa_base(luitmp, 16, 1);
		ft_putstr(pctmp);
	}
	else if (flag == 'o')
	{
		luitmp = va_arg(args, long unsigned int);
		pctmp = ft_itoa_base(luitmp, 8, 0);
		ft_putstr(pctmp);
	}
	else if (flag == 'u')
	{
		luitmp = va_arg(args, long unsigned int);
		pctmp = ft_itoa_base(luitmp, 10, 0);
		ft_putstr(pctmp);
	}
	else if (flag == 'X')
	{
		luitmp = va_arg(args, long unsigned int);
		pctmp = ft_itoa_base(luitmp, 16, 0);
		ft_putstr(pctmp);
	}
	else if (flag == 'x')
	{
		luitmp = va_arg(args, long unsigned int);
		pctmp = ft_itoa_base(luitmp, 16, 1);
		ft_putstr(pctmp);
	}
	else if (flag == '%')
		ft_putchar('%');
	return (1);
}

int ft_printf(const char *orgstr, ...)
{
	va_list args;
	char flagprefix;
	int i;

	flagprefix = '%';
	i = 0;
	va_start(args, orgstr);
	while(orgstr[i])
	{
		if (orgstr[i] == flagprefix)
		{
			flag_handler(orgstr[i+1], args);
			i++;
		}
		else
			ft_putchar(orgstr[i]);
		i++;
	}
	va_end(args);
	return (0);
}
