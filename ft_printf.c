/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuery <sjuery@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 13:31:04 by sjuery            #+#    #+#             */
/*   Updated: 2017/10/24 19:26:58 by sjuery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int base_change(int org, int base_change) {
	int tmp;
	char ltr;
	char *fnl;

	ltr = 'a';
	tmp = 0;
	fnl = ft_strnew(0);
	while(org != 0)
	{
		if(((org % base_change) >= 10 && (org % base_change) <= 35) && base_change == 16)
		{
			ltr = ltr + ((org % base_change) - 10);
			fnl = ft_strjoin(fnl, &ltr);
			ltr = 'a';
		}
		else
		{
			fnl = ft_strjoin(fnl, ft_itoa(org % base_change));
		}
		org /= base_change;
		//
		// if(org == 0)
		// {
		// 	org = tmp;
		// 	tmp = 0;
		// 	while (org != 0)
		// 	{
		// 		tmp *= 10;
		// 		tmp += (org % 10);
		// 		org /= 10;
		// 	}
		// }
	}
	printf("%s\n", fnl);
	return (10000);
}

int flag_handler(char flag, va_list args)
{
	int itmp;
	char ctmp, *pctmp;

	if(flag == 's')
	{
		pctmp = va_arg(args, char *);
		ft_putstr(pctmp);
	}
	else if (flag == 'c')
	{
		ctmp = va_arg(args, int);
		ft_putchar(ctmp);
	}
	else if (flag == 'd')
	{
		itmp = va_arg(args, int);
		ft_putnbr(itmp);
	}
	else if (flag == 'o')
	{
		itmp = va_arg(args, int);
		itmp = base_change(itmp, 8);
		ft_putnbr(itmp);
	}
	else if (flag == 'x')
	{
		itmp = va_arg(args, int);
		itmp = base_change(itmp, 16);
		ft_putnbr(itmp);
	}
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
			flag_handler(orgstr[i+1], args);
		else if (orgstr[i-1] != flagprefix)
			ft_putchar(orgstr[i]);
		i++;
	}
	va_end(args);
	return (0);
}

int main(int argc, char const *argv[]) {
	ft_printf("hello%x", 590);
	ft_printf("\n");
	printf("hello%x", 590);
	return 0;
}
