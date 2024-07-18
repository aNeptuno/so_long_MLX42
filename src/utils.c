/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 02:54:40 by adiban-i          #+#    #+#             */
/*   Updated: 2024/07/18 14:55:25 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_and_free(t_game_data *game_data, char *msg)
{
	perror("Error\n");
	ft_putstr(msg);
	free(game_data->file_content);
	game_data->file_content = NULL;
	return ;
}

static void	free_sprites(t_game_data *gd)
{
	int	i;

	if (gd->sprites)
	{
		if (gd->sprites->bg)
			mlx_delete_image(gd->mlx, gd->sprites->bg);
		i = 0;
		while (i < gd->exit_anim_data->frame_count)
		{
			if (gd->sprites->exit_anim_frames[i])
				mlx_delete_image(gd->mlx,
					gd->sprites->exit_anim_frames[i]);
			i++;
		}
		free(gd->sprites);
	}
}

void	free_game_data(t_game_data *game_data)
{
	int	i;

	if (game_data->file_content)
		free(game_data->file_content);
	if (game_data->map)
	{
		while (i < game_data->rows)
		{
			if (game_data->map[i])
				free(game_data->map[i]);
			i++;
		}
		free(game_data->map);
	}
	free_sprites(game_data);
	if (game_data->player)
		free(game_data->player);
	if (game_data->exit_anim_data)
		free(game_data->exit_anim_data);
}

void	*load_and_check_texture(char *path, char *check_desc)
{
	void	*texture;

	texture = mlx_load_png(path);
	if (!texture)
		check_error_img_or_texture(texture, check_desc, 1);
	return (texture);
}

void	draw_end_img(t_game_data *gd)
{
	int	x;
	int	y;

	x = gd->size_x / 2 - 288;
	y = gd->size_y / 2 + HEADER_HEIGHT - 162;
	if (gd->win)
		mlx_image_to_window(gd->mlx, gd->sprites->win, x, y);
	else
		mlx_image_to_window(gd->mlx, gd->sprites->lost, x, y);
}
