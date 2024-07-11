/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:51:12 by adiban-i          #+#    #+#             */
/*   Updated: 2024/07/03 13:47:31 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_error(t_game_data *gd, char *msg)
{
	ft_putstr("\033[1;31m");
	ft_putstr("Error\n");
	ft_putstr(msg);
	ft_putstr("\033[0m\n");
	gd->is_map_valid = 0;
}

static int	is_char_of_map(char c)
{
	int	is_char;

	is_char = (c == 'C' || c == 'P' || c == 'E' || c == '\n');
	return (c == '1' || c == '0' || is_char || c == 'M');
}

static int	char_count(char charToCount, char *file)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (file[i])
	{
		if (file[i] == charToCount)
			count++;
		i++;
	}
	return (count);
}

static int	validate_map_chars(t_game_data *game_data)
{
	int		i;
	int		file_len;
	char	*file;

	file_len = ft_strlen(game_data->file_content);
	i = 0;
	file = game_data->file_content;
	while (file[i] && is_char_of_map(file[i]))
		i++;
	if (i != file_len)
	{
		map_error(game_data, "Map contains forbbiden characters\n");
		return (0);
	}
	if (char_count('E', file) != 1 || char_count('P', file) != 1)
	{
		map_error(game_data, "Map doesnt have ONE character 'E' or 'P'\n");
		return (0);
	}
	if (char_count('C', file) == 0)
	{
		map_error(game_data, "Map doesnt at least ONE collectable 'C'\n");
		return (0);
	}
	return (1);
}

void	validate_map(t_game_data *game_data)
{
	if (!validate_map_chars(game_data))
		exit(EXIT_FAILURE);
	get_cols(game_data);
	get_rows(game_data);
	if (!game_data->is_map_valid)
	{
		map_error(game_data, "Invalid map proportions (rows and cols)\n");
		exit(EXIT_FAILURE);
	}
	get_map_matrix(game_data);
	if (game_data->map != NULL)
		check_limits(game_data);
}
