/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuery <sjuery@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 13:31:04 by sjuery            #+#    #+#             */
/*   Updated: 2017/11/13 17:27:56 by sjuery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "ft_printf.h"

int		flag_handler(char *flags, char conversion_id)
{
	while(*flags)
	{
		if (*flags == '#')
		{
			if (conversion_id == 'o')
				ft_putchar('0');
			else if (conversion_id == 'x')
				ft_putstr("0x");
			else if (conversion_id == 'X')
				ft_putstr("0X");
		}
		else if (*flags == '0')
		{

		}
		else if (*flags == '-')
		{

		}
		else if (*flags == '+')
		{

		}
		else if (*flags == 'h')
		{
			if(*flags++ == 'h')
			{
				flags++;
			}
		}
		else if (*flags == 'l')
		{
			if(*flags++ == 'l')
			{
				flags++;
			}
		}
		else if (*flags == 'j')
		{

		}
		else if (*flags == 'z')
		{

		}
		flags++;
	}
	return (0);
}

int conversion_handler(char convert_id, char *flags, va_list args)
{
	union uval uval;

	if(convert_id == 's')
	{
		uval.str = va_arg(args, char *);
		flag_handler(flags, 's');
		if(uval.str == NULL)
			ft_putstr("(null)");
		else
			ft_putstr(uval.str);
	}
	else if(convert_id == 'S')
	{
		uval.wchar = va_arg(args, wchar_t *);
		uval.str = wstr_to_str(uval.wchar);
		flag_handler(flags, 'S');
		ft_putstr(uval.str);
	}
	else if (convert_id == 'c')
	{
		uval.chr = va_arg(args, intmax_t);
		flag_handler(flags, 'c');
		ft_putchar(uval.chr);
	}
	else if (convert_id == 'C')
	{
		uval.chr = va_arg(args, intmax_t);
		flag_handler(flags, 'C');
		ft_putchar(uval.chr);
	}
	else if (convert_id == 'd' || convert_id == 'i')
	{
		uval.super = va_arg(args, intmax_t);
		flag_handler(flags, 'd');
		ft_putnbr(uval.super);
	}
	else if (convert_id == 'p')
	{
		uval.super_u = va_arg(args, uintmax_t);
		flag_handler(flags, 'p');
		ft_putstr("0x");
		uval.str = ft_itoa_base(uval.super_u, 16, 1);
		ft_putstr(uval.str);
	}
	else if (convert_id == 'o')
	{
		uval.super_u = va_arg(args, uintmax_t);
		uval.str = ft_itoa_base(uval.super_u, 8, 0);
		flag_handler(flags, 'o');
		ft_putstr(uval.str);
	}
	else if (convert_id == 'u')
	{
		uval.super_u = va_arg(args, uintmax_t);
		uval.str = ft_itoa_base(uval.super_u, 10, 0);
		flag_handler(flags, 'u');
		ft_putstr(uval.str);
	}
	else if (convert_id == 'X')
	{
		uval.super_u = va_arg(args, uintmax_t);
		uval.str = ft_itoa_base(uval.super_u, 16, 0);
		flag_handler(flags, 'X');
		ft_putstr(uval.str);
	}
	else if (convert_id == 'x')
	{
		uval.super_u = va_arg(args, uintmax_t);
		uval.str = ft_itoa_base(uval.super_u, 16, 1);
		flag_handler(flags, 'x');
		ft_putstr(uval.str);
	}
	else if (convert_id == '%')
		ft_putchar('%');
	return (1);
}

int ft_printf(const char *orgstr, ...)
{
	va_list args;
	char flagprefix;
	char *flags;

	flagprefix = '%';
	va_start(args, orgstr);
	while(*orgstr)
	{
		if(*orgstr == flagprefix)
		{
			orgstr++;
			flags = ft_strnew(0);
			while (*orgstr == '#' || *orgstr == '0' || *orgstr == '-' ||
					*orgstr == '+' || *orgstr == ' ' || *orgstr == 'h' ||
					*orgstr == 'l' || *orgstr == 'j' || *orgstr == 'z')
				flags = ft_strjoin(flags, ft_chartostr(*orgstr++));
			conversion_handler(*orgstr, flags, args);
		}
		else
			ft_putchar(*orgstr);
		orgstr++;
	}
	va_end(args);
	return (0);
}
