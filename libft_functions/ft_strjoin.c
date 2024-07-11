/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 21:28:44 by adiban-i          #+#    #+#             */
/*   Updated: 2023/12/03 21:28:44 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	size_t	i;
	char	*res;

	size = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(size + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (s1[i] && (int)i < ft_strlen(s1))
	{
		res[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] && (int)i < ft_strlen(s2))
	{
		res[ft_strlen(s1) + i] = s2[i];
		i++;
	}
	res[ft_strlen(s1) + i] = '\0';
	return (res);
}
