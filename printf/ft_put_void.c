/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_void.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabad-di <jabad-di@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 00:04:27 by dipekko           #+#    #+#             */
/*   Updated: 2025/12/09 15:26:53 by jabad-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_hex_void(unsigned long x)
{
	int		tmp;
	char	*ar;

	ar = "0123456789abcdef";
	tmp = 0;
	if (x >= 16)
		tmp += ft_put_hex_void(x / 16);
	write (1, &ar[x % 16], 1);
	return (tmp + 1);
}

int	ft_put_void(void *s)
{
	unsigned long	len;
	unsigned long	tmp;

	if (!s)
	{
		write (1, "(nil)", 5);
		return (5);
	}
	write (1, "0x", 2);
	len = 2;
	tmp = (unsigned long)s;
	len += ft_put_hex_void(tmp);
	return (len);
}
