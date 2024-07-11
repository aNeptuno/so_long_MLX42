/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:35:35 by adiban-i          #+#    #+#             */
/*   Updated: 2023/12/03 17:35:35 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static size_t	get_size(long n)
{
	size_t	size;

	if (n <= 0)
		size = 1;
	else
		size = 0;
	while (n)
	{
		n /= 10;
		size++;
	}
	return (size);
}

static char	*handle_zero(char *res, size_t size)
{
	if (size == 1 && res[1] == '\0')
		res[0] = '0';
	else if (size == 1 && res[1])
		res[1] = '0';
	return (res);
}

static void	handle_negative(char *res, long *num)
{
	if (*num < 0)
	{
		res[0] = '-';
		*num *= -1;
	}
}

char	*ft_itoa(int n)
{
	size_t	size;
	int		i;
	char	*res;
	long	num;

	num = (long)n;
	size = get_size(num);
	res = (char *)malloc(size + 1);
	if (!res)
		return (NULL);
	res[size] = '\0';
	i = 0;
	handle_negative(res, &num);
	if (num == 0)
		res = handle_zero(res, size);
	while (num)
	{
		res[size - 1 - i] = (num % 10) + '0';
		num /= 10;
		i++;
	}
	return (res);
}
