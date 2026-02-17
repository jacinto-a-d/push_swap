/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabad-di <jabad-di@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 13:39:34 by jabad-di          #+#    #+#             */
/*   Updated: 2026/02/17 13:50:49 by jabad-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static	char	*copy_substr(const char *s, char c, size_t j, char *second)
{
	size_t		i;
	size_t		a;
	size_t		x;

	a = 0;
	i = 0;
	x = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (j == x)
		{
			while (s[i] && s[i] != c)
				second[a++] = s[i++];
			break ;
		}
		else
			while (s[i] && s[i] != c)
				i++;
		x++;
	}
	second[a] = '\0';
	return (second);
}

static	int	count_max_substr(const char *str2, char c)
{
	size_t	i;
	size_t	num_substr;

	i = 0;
	num_substr = 0;
	while (str2[i])
	{
		while (str2[i] && str2[i] == c)
			i++;
		if (str2[i] && str2[i] != c)
		{
			num_substr++;
			while (str2[i] && str2[i] != c)
				i++;
		}
	}
	return (num_substr);
}

static char	*memorydup(const char *s, char c, size_t j)
{
	char		*second;
	size_t		i;

	i = 0;
	while (s[i])
		i++;
	second = malloc(i + 1);
	if (second == NULL)
		return (NULL);
	copy_substr(s, c, j, second);
	return (second);
}

char	**ft_split_bonus(char const *s, char c)
{
	char		**result;
	size_t		j;
	size_t		max_substr;

	j = 0;
	max_substr = count_max_substr(s, c);
	if (!s)
		return (NULL);
	result = malloc(sizeof(char *) * (max_substr + 1));
	if (result == NULL)
		return (NULL);
	while (max_substr > j)
	{
		result[j] = memorydup(s, c, j);
		if (result[j] == NULL)
		{
			while (j > 0)
				free (result[--j]);
			free (result);
		}
		j++;
	}
	result[j] = NULL;
	return (result);
}
