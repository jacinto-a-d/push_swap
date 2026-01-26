/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabad-di <jabad-di@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 18:47:36 by jabad-di          #+#    #+#             */
/*   Updated: 2025/12/09 15:25:43 by jabad-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_cero(void)
{
	char	*s;

	s = malloc(2);
	if (!s)
		return ("0");
	s[0] = '0';
	s[1] = '\0';
	return (s);
}

static	int	ft_count_num(unsigned int n)
{
	unsigned int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa_unsigned(unsigned int n)
{
	char			*str;
	unsigned int	len;

	len = ft_count_num(n);
	if (n == 0)
		return (ft_cero());
	str = malloc(len + 1);
	if (!str)
		return ("0");
	str[len] = '\0';
	while (n > 0)
	{
		str[--len] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}
