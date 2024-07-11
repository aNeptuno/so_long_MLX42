/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:05:03 by adiban-i          #+#    #+#             */
/*   Updated: 2024/06/26 00:23:11 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Works as realloc but it recibes the oldsize as a parameter
void	*my_realloc(void *ptr, size_t newsize, size_t oldsize)
{
	void	*newptr;

	if (ptr == NULL)
	{
		ptr = malloc(newsize);
		return (ptr);
	}
	else if (ptr != NULL && newsize == 0)
	{
		free(ptr);
		return (NULL);
	}
	else
	{
		newptr = malloc(newsize);
		if (newptr == NULL)
			return (NULL);
		if (newsize < oldsize)
			oldsize = newsize;
		ft_memcpy(newptr, ptr, oldsize);
		free(newptr);
		return (ptr);
	}
}
