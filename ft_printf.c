/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuery <sjuery@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 13:31:04 by sjuery            #+#    #+#             */
/*   Updated: 2017/10/26 01:34:42 by sjuery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

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
	else if (flag == 'd' || flag == 'i')
	{
		itmp = va_arg(args, int);
		ft_putnbr(itmp);
	}
	else if (flag == 'p')
	{
		itmp = va_arg(args, int);
		ft_putstr("0x");
		pctmp = ft_itoa_base(itmp, 16, 1);
		printf("%s\n", pctmp);
		ft_putstr(pctmp);
	}
	else if (flag == 'o')
	{
		itmp = va_arg(args, int);
		pctmp = ft_itoa_base(itmp, 8, 0);
		ft_putstr(pctmp);
	}
	else if (flag == 'u')
	{
		itmp = va_arg(args, int);
		pctmp = ft_itoa_base(itmp, 10, 0);
		ft_putstr(pctmp);
	}
	else if (flag == 'X')
	{
		itmp = va_arg(args, int);
		pctmp = ft_itoa_base(itmp, 16, 0);
		ft_putstr(pctmp);
	}
	else if (flag == 'x')
	{
		itmp = va_arg(args, int);
		pctmp = ft_itoa_base(itmp, 16, 1);
		ft_putstr(pctmp);
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
	ft_printf("hello%s", "OAHGFISEUKH FVBSUEIKHVOSEILKHVOEISHiughfbveuishbvweoisvhnOIHVNEOIBHSVNESOIHVNAoihncreoiskhncwpeosjvnwoieKAh	nipkjanifkhanpiogjme9probjvmeirsbkjvnisk eproesljgvpoJLMPO;");
	ft_printf("\n");
	printf("hello%s", "OAHGFISEUKHFVBSUEIKH VOSEILKHVOEISHiughfbveuishbvweoisvhnOIHVNEOIBHSVNESOIHVNAoihncreoiskhncwpeosjvnwoieKAh	nipkjanifkhanpiogjme9probjvmeirsbkjvnisk eproesljgvpoJLMPO;");
	return 0;
}
