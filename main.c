/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuery <sjuery@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 23:50:01 by sjuery            #+#    #+#             */
/*   Updated: 2017/12/06 02:28:04 by sjuery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <stdio.h>
#include <stddef.h>
#include <stdint.h>

int	main()
{
	ft_printf("%*.*d\n", 0, 3, 0);
	printf("%*.*d", 0, 3, 0);
}
