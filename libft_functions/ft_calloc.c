/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:45:37 by adiban-i          #+#    #+#             */
/*   Updated: 2023/11/30 14:45:37 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*ft_memset(void *dst, int c, size_t len)
{
	size_t			i;
	unsigned char	*cdst;

	cdst = (unsigned char *)dst;
	i = 0;
	while (i < len)
	{
		cdst[i] = (unsigned char)c;
		i++;
	}
	return (dst);
}

static void	ft_bzero(void *b, size_t len)
{
	ft_memset(b, 0, len);
}

void	*ft_calloc(size_t number, size_t size)
{
	void	*res;

	res = malloc(number * size);
	if (!res)
		return (NULL);
	ft_bzero(res, number * size);
	return (res);
}
