/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dipekko <dipekko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:43:26 by jabad-di          #+#    #+#             */
/*   Updated: 2026/02/16 10:57:29 by dipekko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	char	i_c;

	if (!str)
		return (NULL);
	i_c = (char)c;
	while (*str)
	{
		if (*str == i_c)
			return ((char *)str);
		str++;
	}
	if (i_c == '\0')
		return ((char *)str);
	return (NULL);
}

char	*ft_extract_line(char *stash)
{
	char	*line;
	int		x;

	x = 0;
	if (!stash || stash[0] == '\0')
		return (NULL);
	while (stash[x] && stash[x] != '\n')
		x++;
	line = malloc(sizeof(char) * (x + 2));
	if (!line)
		return (NULL);
	x = 0;
	while (stash[x] && stash[x] != '\n')
	{
		line[x] = stash[x];
		x++;
	}
	if (stash[x] == '\n')
	{
		line[x] = stash[x];
		x++;
	}
	line[x] = '\0';
	return (line);
}

char	*ft_stash_clean(char *stash)
{
	char	*rest;
	int		x;
	int		i;

	x = 0;
	i = 0;
	while (stash && stash[x] && stash[x] != '\n')
		x++;
	if (!stash || !stash[x])
	{
		free (stash);
		return (NULL);
	}
	rest = malloc(sizeof(char) * (ft_strlen(stash) - x + 1));
	if (!rest)
	{
		free (stash);
		return (NULL);
	}
	x++;
	while (stash[x])
		rest[i++] = stash[x++];
	rest[i] = '\0';
	free (stash);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char		*stash;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (stash)
			free (stash);
		stash = NULL;
		return (NULL);
	}
	stash = ft_read_and_strchr(fd, stash);
	if (!stash)
	{
		stash = NULL;
		return (NULL);
	}
	line = ft_extract_line(stash);
	if (!line || line[0] == '\0')
	{
		free (line);
		stash = NULL;
		return (NULL);
	}
	stash = ft_stash_clean(stash);
	return (line);
}
