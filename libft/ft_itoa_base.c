/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuery <sjuery@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 12:41:35 by sjuery            #+#    #+#             */
/*   Updated: 2017/11/02 15:38:14 by sjuery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(long int value, int base, int lowercase)
{
	long unsigned int		flag;
	long unsigned int		len;
	char					*str;
	long unsigned int		v;

	if (base < 2 && base > 36)
		return (0);
	flag = (value < 0 && base == 10) ? 1 : 0;
	len = 1 + flag;
	v = value;
	while (v /= base)
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	str[0] = '-';
	str[len] = 0;
	while (len-- > flag)
	{
		v = (value < 0) ? -(value % base) : value % base;
		if(lowercase == 1)
			str[len] = (v > 9) ? v + 'a' - 10 : v + '0';
		else
			str[len] = (v > 9) ? v + 'A' - 10 : v + '0';
		value /= base;
	}
	return (str);
}
