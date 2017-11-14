/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chartostr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuery <sjuery@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 19:23:18 by sjuery            #+#    #+#             */
/*   Updated: 2017/11/11 19:36:59 by sjuery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_chartostr(char ch)
{
    char *newstr;
    newstr = malloc(sizeof(char));
    *newstr = ch;
    return (newstr);
}
