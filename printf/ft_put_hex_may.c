/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex_may.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabad-di <jabad-di@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 19:15:19 by jabad-di          #+#    #+#             */
/*   Updated: 2026/01/08 14:43:20 by jabad-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_hex_may(unsigned int x)
{
	char			*ar;
	unsigned int	tmp;

	ar = "0123456789ABCDEF";
	tmp = 0;
	if (x == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	if (x >= 16)
	{
		tmp = ft_put_hex_may(x / 16);
		write (1, &ar[x % 16], 1);
	}
	else
		write (1, &ar[x], 1);
	return (tmp + 1);
}
