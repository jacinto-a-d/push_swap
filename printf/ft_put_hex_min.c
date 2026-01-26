/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex_min.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabad-di <jabad-di@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 23:42:57 by dipekko           #+#    #+#             */
/*   Updated: 2025/12/09 15:26:18 by jabad-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_hex_min(unsigned int y)
{
	char			*ar;
	unsigned int	tmp;

	ar = "0123456789abcdef";
	tmp = 0;
	if (y == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	if (y >= 16)
	{
		tmp = ft_put_hex_min(y / 16);
		write (1, &ar[y % 16], 1);
	}
	else
		write (1, &ar[y], 1);
	return (tmp + 1);
}
