/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putwchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuery <sjuery@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:37:55 by sjuery            #+#    #+#             */
/*   Updated: 2017/11/09 14:38:44 by sjuery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_putwchar(wchar_t wc)
{
	if ((unsigned int)wc <= 127)
		ft_putchar((unsigned int)wc);
	else if ((unsigned int)wc <= 2047)
	{
		ft_putchar(192 | (((unsigned int)wc >> 6) & 63));
		ft_putchar(49280 | ((unsigned int)wc & 63));
	}
	else if ((unsigned int)wc <= 65535)
	{
		ft_putchar(224 | ((unsigned int)wc >> 12));
		ft_putchar(128 | (((unsigned int)wc >> 6) & 63));
		ft_putchar(128 | ((unsigned int)wc & 63));
	}
	else
	{
		ft_putchar(248 | (((unsigned int)wc >> 18) & 63));
		ft_putchar(128 | (((unsigned int)wc >> 12) & 63));
		ft_putchar(128 | (((unsigned int)wc >> 6) & 63));
		ft_putchar(128 | ((unsigned int)wc & 63));
	}
}
