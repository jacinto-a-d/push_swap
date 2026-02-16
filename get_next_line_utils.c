/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dipekko <dipekko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:21:51 by jabad-di          #+#    #+#             */
/*   Updated: 2026/02/16 11:02:24 by dipekko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strcat(char *dest, const char *src)
{
	char	*ptr;

	ptr = dest;
	while (*ptr != '\0')
		ptr++;
	while (*src != '\0')
	{
		*ptr = *src;
		ptr++;
		src++;
	}
	*ptr = '\0';
	return (dest);
}

char	*ft_str_malloc_concat(char *s1, char *s2)
{
	size_t	l1;
	size_t	l2;
	char	*str;

	l1 = 0;
	l2 = 0;
	if (s1 != NULL)
		l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	str = (char *)malloc (l1 + l2 + 1);
	if (!str)
	{
		free (s1);
		return (NULL);
	}
	str[0] = '\0';
	if (s1 != NULL)
		ft_strcat(str, s1);
	ft_strcat(str, s2);
	free (s1);
	return (str);
}

char	*ft_init_stash(char *stash)
{
	if (!stash)
	{
		stash = malloc (1);
		if (!stash)
			return (NULL);
		stash[0] = '\0';
	}
	return (stash);
}

char	*ft_clean_exit(char *stash, char *tmp)
{
	if (tmp)
		free (tmp);
	if (!stash || stash[0] == '\0')
	{
		if (stash)
			free (stash);
		return (NULL);
	}
	return (stash);
}

char	*ft_read_and_strchr(int fd, char *stash)
{
	char	*buf_tmp;
	int		read_byt;

	stash = ft_init_stash(stash);
	buf_tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf_tmp)
		return (NULL);
	read_byt = 1;
	while (stash && !ft_strchr(stash, '\n') && read_byt > 0)
	{
		read_byt = read(fd, buf_tmp, BUFFER_SIZE);
		if (read_byt < 0)
		{
			free (stash);
			return (ft_clean_exit(NULL, buf_tmp));
		}
		if (read_byt > 0)
		{
			buf_tmp[read_byt] = '\0';
			stash = ft_str_malloc_concat(stash, buf_tmp);
			if (!stash)
				return (ft_clean_exit(NULL, buf_tmp));
		}
	}
	return (ft_clean_exit(stash, buf_tmp));
}
