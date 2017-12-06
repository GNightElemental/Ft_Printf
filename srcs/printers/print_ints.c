/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ints.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuery <sjuery@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 23:43:19 by sjuery            #+#    #+#             */
/*   Updated: 2017/12/05 08:09:50 by sjuery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	ft_size_precision(char *arg, int i, t_printf *prtf, char c)
{
	int j;

	j = prtf->precision > i ? prtf->precision - i : 0;
	while (i < prtf->size - j)
	{
		ft_putchar(c);
		i++;
	}
	while (prtf->precision > (int)ft_strlen(arg))
	{
		ft_putchar('0');
		prtf->precision--;
	}
	return (i);
}

static int	ft_size(char *arg, t_printf *prtf, int excep)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	if (!prtf->precise)
		c = prtf->zero == 1 ? '0' : ' ';
	else
		c = ' ';
	i = excep ? 0 : ft_strlen(arg);
	if ((prtf->sharp || prtf->spec == 'p') && c == '0' && !excep)
		ft_putnstr(arg, 0, 2);
	j = prtf->precision > i ? prtf->precision - i : 0;
	i = ft_size_precision(arg, i, prtf, c);
	if ((prtf->sharp || prtf->spec == 'p') && c == '0' && !excep)
		ft_putnstr(arg, 2, ft_strlen(arg));
	else if (!excep)
		ft_putstr(arg);
	else if (!(ft_strcmp("0", arg)))
		return (i);
	return (i + j);
}

static int	ft_precision(char *arg, t_printf *prtf, int excep, int octa)
{
	int i;
	int a;

	i = 0;
	a = ft_strlen(arg);
	i = (prtf->sharp || prtf->spec == 'p') ? a - octa - 1 : a;
	if (excep && !prtf->sharp && octa)
		i = 2;
	if (((prtf->sharp || prtf->spec == 'p') && !excep) ||
		((prtf->sharp && !excep) || prtf->spec == 'p'))
		ft_putnstr(arg, 0, !octa ? 1 : 2);
	while (!octa ? (i < prtf->precision - prtf->sharp) : (i < prtf->precision
		&& (prtf->sharp + excep) != 2))
	{
		ft_putchar('0');
		i++;
	}
	i = !octa ? (prtf->sharp ? 1 + i : i) : ((prtf->sharp || prtf->spec == 'p')
		&& !excep ? i + 2 : i);
	if ((prtf->sharp || prtf->spec == 'p') && !excep)
		ft_putnstr(arg, !octa ? 1 : 2, a);
	else if (!octa ? (!(ft_strcmp("0", arg)) && !prtf->sharp)
		: !(ft_strcmp("0", arg)))
		return (0);
	else if ((!excep || prtf->precision < (int)ft_strlen(arg)) && !octa)
		ft_putstr(arg);
	else if ((excep && prtf->sharp && !(ft_strcmp("0", arg))) && !octa)
		ft_putstr(arg);
	else if (!excep && octa)
		ft_putstr(arg);
	return (i);
}

static int	ft_minus(char *arg, t_printf *prtf, int excep)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (prtf->precise)
	{
		j = ft_strlen(arg);
		while (j < prtf->precision)
		{
			ft_putchar('0');
			j++;
		}
		i += ft_strlen(arg);
	}
	else
		i = j ? -1 : (int)ft_strlen(arg) - 1;
	if (!excep)
		ft_putstr(arg);
	if (prtf->size)
	{
		while (++i < prtf->size)
			ft_putchar(' ');
	}
	return (i);
}

int			print_ints(char *arg, t_printf *prtf, int octa)
{
	int i;
	int excep;

	i = 0;
	excep = (prtf->precise && prtf->precision == 0) ? 1 : 0;
	if (prtf->minus && ((prtf->precision < prtf->size && prtf->precise)\
			|| !prtf->precision))
		i += ft_minus(arg, prtf, excep);
	else if (prtf->precise && (prtf->precision >= prtf->size || !prtf->size))
		i += ft_precision(arg, prtf, excep, octa);
	else if (prtf->size)
		i += ft_size(arg, prtf, excep);
	else
	{
		if (!excep)
		{
			ft_putstr(arg);
			i = ft_strlen(arg);
		}
	}
	return (i);
}
