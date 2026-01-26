/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabad-di <jabad-di@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 20:24:56 by jabad-di          #+#    #+#             */
/*   Updated: 2026/01/08 14:42:56 by jabad-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_identy_letter(va_list args, const char *format)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (format[i] == 'c')
		count += ft_put_char_ascii(va_arg (args, int));
	else if (format[i] == 's')
		count += ft_put_char_ptr(va_arg (args, char *));
	else if (format[i] == 'd' || format[i] == 'i')
		count += ft_put_int(va_arg (args, int));
	else if (format[i] == 'u')
		count += ft_put_unsigned_int(va_arg (args, unsigned int));
	else if (format[i] == 'x')
		count += ft_put_hex_min(va_arg (args, unsigned int));
	else if (format[i] == 'X')
		count += ft_put_hex_may(va_arg (args, unsigned int));
	else if (format[i] == 'p')
		count += ft_put_void(va_arg (args, void *));
	else if (format[i] == '%')
		count += write(1, "%", 1);
	va_end(args);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	int		i;
	va_list	args;

	count = 0;
	i = -1;
	va_start (args, format);
	while (format[++i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_identy_letter(args, &format[i]);
		}
		else
			count += write (1, &format[i], 1);
	}
	va_end(args);
	return (count);
}
