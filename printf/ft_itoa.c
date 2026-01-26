/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabad-di <jabad-di@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:57:53 by jabad-di          #+#    #+#             */
/*   Updated: 2025/12/09 15:25:38 by jabad-di         ###   ########.fr       */
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

static	int	ft_count_num(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		count++;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long	num;
	char	*str;
	int		len;

	num = n;
	len = ft_count_num(num);
	if (num == 0)
		return (ft_cero());
	str = malloc(len + 1);
	if (!str)
		return ("0");
	str[len] = '\0';
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	while (num > 0)
	{
		str[--len] = (num % 10) + '0';
		num = num / 10;
	}
	return (str);
}
