/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 02:54:40 by adiban-i          #+#    #+#             */
/*   Updated: 2024/12/08 18:53:37 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_and_free(t_game_data *game_data, char *msg)
{
	perror("Error\n");
	ft_putstr(msg);
	if (game_data->file_content != NULL)
	{
		free(game_data->file_content);
		game_data->file_content = NULL;
	}
	return ;
}

/* static void	free_sprites(t_game_data *gd)
{
	int	i;

	if (gd->sprites)
	{
		mlx_delete_image(gd->mlx, gd->sprites->lost);
		mlx_delete_image(gd->mlx, gd->sprites->win);
		mlx_delete_image(gd->mlx, gd->sprites->player_up);
		mlx_delete_image(gd->mlx, gd->sprites->player_left);
		mlx_delete_image(gd->mlx, gd->sprites->player_right);
		mlx_delete_image(gd->mlx, gd->sprites->player_down);
		mlx_delete_image(gd->mlx, gd->sprites->obstacle);
		mlx_delete_image(gd->mlx, gd->sprites->collectable);
		mlx_delete_image(gd->mlx, gd->sprites->exit);
		mlx_delete_image(gd->mlx, gd->sprites->header);
		mlx_delete_image(gd->mlx, gd->sprites->clean_img);
		mlx_delete_image(gd->mlx, gd->sprites->enemy);

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
} */

void	free_game_data(t_game_data *game_data)
{
	int	i;

	if (game_data != NULL)
	{
		if (game_data->file_content)
			free(game_data->file_content);
		if (game_data->map)
		{
			i = 0;
			while (i < game_data->rows)
			{
				if (game_data->map[i])
					free(game_data->map[i]);
				i++;
			}
			free(game_data->map);
		}
		/* if (game_data->sprites)
			free(game_data->sprites);
		free_sprites(game_data);
		if (game_data->player)
			free(game_data->player);
		if (game_data->exit_anim_data)
			free(game_data->exit_anim_data);
		if (game_data->enemies)
			free (game_data->enemies); */
	}
}

