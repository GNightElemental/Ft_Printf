/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_hexa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuery <sjuery@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 23:42:00 by sjuery            #+#    #+#             */
/*   Updated: 2017/12/06 02:55:32 by sjuery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char		*conv_hexa(t_printf *prtf)
{
	char	*dst;
	int		i;

	i = (prtf->spec == 'x' || prtf->spec == 'p' || prtf->spec == 'a') ? 1 : 0;
	dst = ft_itoa_base(prtf->uvals.ulli, 16, i);
	if (prtf->spec == 'A' || prtf->spec == 'a')
	{
		dst = ft_strjoin("1.0", dst);
		dst = ft_strsub(dst, 0, 7);
		dst = ft_strjoin(dst, "7FP-1042");
	}
	if ((prtf->uvals.ulli && prtf->sharp && prtf->spec == 'x') ||
			(prtf->spec == 'p') || (prtf->spec == 'a'))
		dst = ft_strjoin("0x", dst);
	else if ((prtf->uvals.ulli && prtf->sharp && prtf->spec == 'X')
			|| prtf->spec == 'A')
		dst = ft_strjoin("0X", dst);
	return (dst);
}
