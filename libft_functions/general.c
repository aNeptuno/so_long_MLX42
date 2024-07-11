/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:32:46 by adiban-i          #+#    #+#             */
/*   Updated: 2024/06/17 19:19:41 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;
	int	j;
	int	k;
	int	needle_size;

	if (haystack != NULL && needle != NULL)
	{
		needle_size = ft_strlen(needle);
		i = 0;
		while (haystack[i])
		{
			j = 0;
			k = i;
			while (haystack[k] && needle[j] && haystack[k] == needle[j])
			{
				j++;
				k++;
			}
			if (j == needle_size)
				return ((char *)(haystack + i));
			i++;
		}
	}
	return (NULL);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

// Copy into dst from src "len" bytes
void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	char			*cdst;
	const char		*csrc;
	size_t			i;

	cdst = (char *)dst;
	csrc = (const char *)src;
	if (!dst && !src)
		return (NULL);
	i = 0;
	while (i < len)
	{
		cdst[i] = (char)csrc[i];
		i++;
	}
	return (dst);
}
