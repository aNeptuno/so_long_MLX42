/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:21:58 by adiban-i          #+#    #+#             */
/*   Updated: 2024/12/27 20:10:06 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_player(t_game_data *gd, int i, int j)
{
	void	*player_sprite;

	if (gd->new_move == 'D')
		draw_img(gd, i, j, "./assets/cat_down.png");
	if (gd->new_move == 'U')
		draw_img(gd, i, j, "./assets/cat_up.png");
	if (gd->new_move == 'L')
		draw_img(gd, i, j, "./assets/cat_left.png");
	if (gd->new_move == 'R')
		draw_img(gd, i, j, "./assets/cat_right.png");
	gd->player->x = j;
	gd->player->y = i;
}

static void	put_object_sprite(t_game_data *gd, char c, int i, int j)
{
	if (c == 'P')
		put_player(gd, i, j);
	else if (c == '1')
		draw_img(gd, i, j, "./assets/wall.png");
	else if (c == 'E')
	{
		handle_exit_sprite(gd, j, i);
	}
	else if (c == 'C')
	{
		draw_img(gd, i, j, "./assets/item.png");
		if (gd->first_init)
			gd->map_items++;
	}
	else if (c == 'M')
	{
		draw_img(gd, i, j, "./assets/slimeman.png");
		update_enemy(gd, i, j);
		gd->enemy_index++;
	}
}

static void	ft_mlx_string(t_game_data *gd, int x, int y, char *title)
{
	mlx_put_string(gd->mlx, title, x, y);
}

static void	draw_header(t_game_data *gd)
{
	int		title_x;
	int		collected_x;
	char	*moves;
	char	*items;

	title_x = (gd->size_x / 2);
	collected_x = gd->size_x / 20;
	moves = ft_itoa(gd->player_moves);
	items = ft_itoa(gd->player_items);
	draw_init(gd, 0, title_x, "./assets/title.png");
	ft_mlx_string(gd, gd->size_x / 3 - 100, 45,
		"Cybercat Chronicles: The Ancient Floppy Hunt");
	ft_mlx_string(gd, gd->size_x - 200, 30, "Player Moves: ");
	ft_mlx_string(gd, gd->size_x - 50, 30, moves);
	ft_mlx_string(gd, collected_x, 30, "Collected Floppy: ");
	ft_mlx_string(gd, collected_x + 200, 30, items);
	free(moves);
	free(items);
}

void	put_map(t_game_data *gd)
{
	int	i;
	int	j;

	draw_init(gd, 0, 0, "./assets/bg/black.png");
	draw_header(gd);
	draw_img(gd, 0, 0, "./assets/bg/bg.png");
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
