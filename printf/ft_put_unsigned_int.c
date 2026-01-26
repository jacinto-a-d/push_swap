/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabad-di <jabad-di@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 17:52:21 by jabad-di          #+#    #+#             */
/*   Updated: 2025/12/09 15:24:52 by jabad-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_put_unsigned_int(unsigned int x)
{
	char			*c;
	unsigned int	i;

	i = 0;
	c = ft_itoa_unsigned(x);
	while (c[i] != '\0')
	{
		write (1, &c[i], 1);
		i++;
	}
	free (c);
	return (i);
}
