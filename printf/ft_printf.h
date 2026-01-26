/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabad-di <jabad-di@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:12:17 by jabad-di          #+#    #+#             */
/*   Updated: 2025/12/09 15:25:28 by jabad-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int				ft_atoi(const char *nptr);
int				ft_put_char_ascii(int x);
int				ft_put_char_ptr(char *x);
int				ft_put_int(int x);
int				ft_put_hex_min(unsigned int y);
int				ft_put_hex_may(unsigned int x);
int				ft_put_void(void *s);
int				ft_printf(const char *format, ...);

unsigned int	ft_put_unsigned_int(unsigned int x);

char			*ft_itoa_unsigned(unsigned int n);
char			*ft_itoa(int n);

#endif
