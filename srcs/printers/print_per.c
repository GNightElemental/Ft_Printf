/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_per.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuery <sjuery@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 23:42:52 by sjuery            #+#    #+#             */
/*   Updated: 2017/12/03 07:35:16 by sjuery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int			print_per(va_list pargs, t_printf *prtf)
{
	int i;

	i = 0;
	if (prtf->size && !prtf->zero && !prtf->minus)
		i = zero_minus_space(prtf->size, prtf->spec, ' ');
	else if (prtf->size && prtf->zero && !prtf->minus)
		i = zero_minus_space(prtf->size, prtf->spec, '0');
	else if (prtf->size && prtf->minus)
		i = zero_minus_space(prtf->size, prtf->spec, '-');
	else
	{
		i = 1;
		ft_putchar(prtf->spec);
	}
	return (i);
}
