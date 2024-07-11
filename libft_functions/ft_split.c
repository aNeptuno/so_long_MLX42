/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:03:39 by adiban-i          #+#    #+#             */
/*   Updated: 2024/06/17 18:04:08 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	if (!s)
		return (NULL);
	if ((int)start > ft_strlen(s))
		len = 0;
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	i = 0;
	while ((int)start < ft_strlen(s) && i < len && s[start])
	{
		res[i++] = s[start++];
	}
	res[i] = '\0';
	return (res);
}

static size_t	count_words(char const *s, char c)
{
	size_t	size;
	int		i;

	size = 0;
	i = 0;
	while (s[i])
	{
		if ((s[i + 1] == c || !s[i + 1]) && s[i] != c)
			size++;
		i++;
	}
	return (size);
}

static void	free_mem(char **res)
{
	int	i;

	i = -1;
	while (res[i++])
		free(res[i]);
	free(res);
}

static char	**init_result(char const *s, char c, char **res)
{
	size_t	begin;
	size_t	i;
	size_t	word;

	begin = 0;
	i = 0;
	word = 0;
	while (s[i])
	{
		if ((s[i + 1] == c || !s[i + 1]) && s[i] != c)
		{
			res[word] = ft_substr(s, begin, i - begin + 1);
			if (!res[word])
			{
				free_mem(res);
				return (NULL);
			}
			word++;
		}
		if (s[i] == c && (s[i + 1] != c || s[i + 1]))
			begin = i + 1;
		i++;
	}
	res[word] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	size_t	size;
	char	**res;

	if (!s)
		return (NULL);
	size = count_words(s, c);
	res = (char **)malloc((size + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	res = init_result(s, c, res);
	return (res);
}
