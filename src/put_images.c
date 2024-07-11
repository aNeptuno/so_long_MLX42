/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:21:58 by adiban-i          #+#    #+#             */
/*   Updated: 2024/07/03 14:43:29 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_player(t_game_data *gd, int i, int j)
{
	t_sprites	*player_sprite;

	if (gd->new_move == 'D')
		player_sprite = gd->sprites->player_down;
	if (gd->new_move == 'U')
		player_sprite = gd->sprites->player_up;
	if (gd->new_move == 'L')
		player_sprite = gd->sprites->player_left;
	if (gd->new_move == 'R')
		player_sprite = gd->sprites->player_right;
	mlx_put_image_to_window(gd->mlx, gd->window,
		player_sprite, j * PIXELS, (i * PIXELS) + HEADER_HEIGHT);
	gd->player->x = j;
	gd->player->y = i;
}

static void	put_object_sprite(t_game_data *gd, char c, int i, int j)
{
	if (c == 'P')
		put_player(gd, i, j);
	else if (c == '1')
	{
		mlx_put_image_to_window(gd->mlx, gd->window,
			gd->sprites->obstacle, j * PIXELS, (i * PIXELS) + HEADER_HEIGHT);
	}
	else if (c == 'E' && gd->first_init)
	{
		mlx_put_image_to_window(gd->mlx, gd->window,
			gd->sprites->exit, j * PIXELS, (i * PIXELS) + HEADER_HEIGHT);
		gd->exit_anim_data->position_x = j * PIXELS;
		gd->exit_anim_data->position_y = (i * PIXELS) + HEADER_HEIGHT;
	}
	else if (c == 'C')
	{
		mlx_put_image_to_window(gd->mlx, gd->window,
			gd->sprites->collectable, j * PIXELS, (i * PIXELS) + HEADER_HEIGHT);
		if (gd->first_init)
			gd->map_items++;
	}
	else if (c == 'M')
		put_enemy(gd, i, j);
}

static void	ft_mlx_string(t_game_data *gd, int x, int y, char *title)
{
	mlx_string_put(gd->mlx, gd->window, x, y, 0x800080, title);
}

static void	draw_header(t_game_data *gd)
{
	int		title_x;
	int		collected_x;
	char	*moves;
	char	*items;

	title_x = (gd->size_x / 2) - 25;
	collected_x = gd->size_x / 12;
	moves = ft_itoa(gd->player_moves);
	items = ft_itoa(gd->player_items);
	mlx_put_image_to_window(gd->mlx, gd->window, gd->sprites->header,
		title_x, 0);
	mlx_string_put(gd->mlx, gd->window, title_x - 100, 45, 0xFFFFFF,
		"Cybercat Chronicles: The Ancient Floppy Hunt");
	ft_mlx_string(gd, gd->size_x - 150, 30, "Player Moves: ");
	ft_mlx_string(gd, gd->size_x - 50, 30, moves);
	ft_mlx_string(gd, collected_x, 30, "Collected Floppy: ");
	ft_mlx_string(gd, collected_x + 120, 30, items);
	free(moves);
	free(items);
}

void	put_map(t_game_data *gd)
{
	int	i;
	int	j;

	draw_header(gd);
	mlx_put_image_to_window(gd->mlx, gd->window, gd->sprites->bg_resized,
		0, HEADER_HEIGHT);
	if (!gd->first_init)
		put_animations(gd);
	i = 0;
	while (i < gd->rows)
	{
		j = 0;
		while (j < gd->cols)
		{
			put_object_sprite(gd, gd->map[i][j], i, j);
			j++;
		}
		i++;
	}
	gd->first_init = 0;
}
