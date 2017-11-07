/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuery <sjuery@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 12:41:38 by sjuery            #+#    #+#             */
/*   Updated: 2017/11/05 04:18:49 by sjuery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	basechecker(char c, int base)
{
	if (base <= 10)
		return (c >= '0' && c <= ('9' + base - 10));
	return ((c >= '0' && c <= '9') ||
		(c >= 'A' && c <= ('A' + base - 10)) ||
		(c >= 'a' && c <= ('a' + base - 10)));
}

int			ft_atoi_base(const char *str, int base)
{
	int i;
	int	sign;
	int result;

	i = 0;
	sign = 1;
	result = 0;
	if (base >= 2 && base <= 16)
	{
		while ((*str == ' ') || (*str == '\t') || (*str == '\n')
			|| (*str == '\v') || (*str == '\f') || (*str == '\r'))
			i++;
		if (str[i] == '-')
			sign = -1;
		if (str[i] == '+' || str[i] == '-')
			i++;
		while (basechecker(str[i], base))
		{
			if (str[i] - 'a' >= 0)
				result = result * base + (str[i] - 'a' + 10);
			else if (str[i] - 'A' >= 0)
				result = result * base + (str[i] - 'A' + 10);
			else
				result = result * base + (str[i] - '0');
			i++;
		}
		return (sign * result);
	}
	return (0);
}
