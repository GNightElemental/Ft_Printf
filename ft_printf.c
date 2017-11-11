/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuery <sjuery@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 13:31:04 by sjuery            #+#    #+#             */
/*   Updated: 2017/11/11 02:22:35 by sjuery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "ft_printf.h"

int flag_handler(char flag, va_list args)
{
	int itmp;
	long unsigned int luitmp;
	char ctmp, *cptmp;
	wchar_t wctmp, *wcptmp;

	if(flag == 's')
	{
		cptmp = va_arg(args, char *);
		if(cptmp == NULL)
			ft_putstr("(null)");
		else
			ft_putstr(cptmp);
	}
	else if(flag == 'S')
	{
		wcptmp = va_arg(args, wchar_t *);
		cptmp = wstr_to_str(wcptmp);
		ft_putstr(cptmp);
	}
	else if (flag == 'c')
	{
		ctmp = va_arg(args, int);
		ft_putchar(ctmp);
	}
	else if (flag == 'C')
	{
		wctmp = va_arg(args, wchar_t);
		cptmp = wint_to_str(wctmp);
		ft_putstr(cptmp);
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
		cptmp = ft_itoa_base(luitmp, 16, 1);
		ft_putstr(cptmp);
	}
	else if (flag == 'o')
	{
		luitmp = va_arg(args, long unsigned int);
		cptmp = ft_itoa_base(luitmp, 8, 0);
		ft_putstr(cptmp);
	}
	else if (flag == 'u')
	{
		luitmp = va_arg(args, long unsigned int);
		cptmp = ft_itoa_base(luitmp, 10, 0);
		ft_putstr(cptmp);
	}
	else if (flag == 'X')
	{
		luitmp = va_arg(args, long unsigned int);
		cptmp = ft_itoa_base(luitmp, 16, 0);
		ft_putstr(cptmp);
	}
	else if (flag == 'x')
	{
		luitmp = va_arg(args, long unsigned int);
		cptmp = ft_itoa_base(luitmp, 16, 1);
		ft_putstr(cptmp);
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
		if(orgstr[i] == flagprefix)
		{
			i++;
			while (orgstr[i] == '#' || orgstr[i] == '0' || orgstr[i] == '-' ||
					orgstr[i] == '+' || orgstr[i] == ' ' || orgstr[i] == 'h' ||
					orgstr[i] == 'l' || orgstr[i] == 'j' || orgstr[i] == 'z')
				i++;
			if(orgstr[i-1] == 'l' && orgstr[i] == 's')
				flag_handler('S', args);
			flag_handler(orgstr[i], args);
		}
		else
			ft_putchar(orgstr[i]);
		i++;
	}
	va_end(args);
	return (0);
}
