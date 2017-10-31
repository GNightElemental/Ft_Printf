/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uni2utf8.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuery <sjuery@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 20:47:03 by sjuery            #+#    #+#             */
/*   Updated: 2017/10/30 20:54:22 by sjuery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char* ft_uni2utf8(wchar_t c)
{
    static char b_static[5];
    char* b = b_static;

    if (c<(1<<7))// 7 bit Unicode encoded as plain ascii
    {
        *b++ = (unsigned char)(c);
    }
    else if (c<(1<<11))// 11 bit Unicode encoded in 2 UTF-8 bytes
    {
        *b++ = (unsigned char)((c>>6)|0xC0);
        *b++ = (unsigned char)((c&0x3F)|0x80);
    }
    else if (c<(1<<16))// 16 bit Unicode encoded in 3 UTF-8 bytes
        {
        *b++ = (unsigned char)(((c>>12))|0xE0);
        *b++ =  (unsigned char)(((c>>6)&0x3F)|0x80);
        *b++ =  (unsigned char)((c&0x3F)|0x80);
    }

    else if (c<(1<<21))// 21 bit Unicode encoded in 4 UTF-8 bytes
    {
        *b++ = (unsigned char)(((c>>18))|0xF0);
        *b++ = (unsigned char)(((c>>12)&0x3F)|0x80);
        *b++ = (unsigned char)(((c>>6)&0x3F)|0x80);
        *b++ = (unsigned char)((c&0x3F)|0x80);
    }
    *b = '\0';
    return b_static;
}
