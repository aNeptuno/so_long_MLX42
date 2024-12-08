/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 14:21:29 by adiban-i          #+#    #+#             */
/*   Updated: 2024/12/08 18:25:47 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	change_player_sprite(int coord_x, int coord_y, t_game_data *gd)
{
	if (coord_x == 1)
	{
		gd->new_move = 'R';
	}
	if (coord_x == -1)
	{
		gd->new_move = 'L';
	}
	if (coord_y == 1)
	{
		gd->new_move = 'U';
	}
	if (coord_y == -1)
	{
		gd->new_move = 'D';
	}
}

static void	display_stats(t_game_data *gd, int is_moves)
{
	char	*moves;
	char	*items;

	moves = ft_itoa(gd->player_moves);
	items = ft_itoa(gd->player_items);
	if (is_moves)
	{
		ft_putstr("\033[2J");
		ft_putstr("\033[H");
		ft_putstr("\033[1;33m");
		ft_putstr("Total moves: ");
		ft_putstr(moves);
		ft_putstr("\033[0m\n");
	}
	else
	{
		ft_putstr("Collected Floppy: ");
		ft_putstr(items);
		ft_putstr(" | Total moves: ");
		ft_putstr(moves);
	}
	free(moves);
	free(items);
}

static void	move_exit(t_game_data *gd)
{
	gd->game_ended = 1;
	if (gd->player_items == gd->map_items)
	{
		ft_putstr("\033[1;32m");
		ft_putstr("\nYou won! :D\n");
		display_stats(gd, 0);
		ft_putstr("\033[0m\n");
		gd->win = 1;
		draw_end_img(gd);
	}
	else
	{
		ft_putstr("\033[2J");
		ft_putstr("\033[H");
		ft_putstr("\033[1;31m");
		ft_putstr("\nYou failed your mission to collect them all :(\n");
		display_stats(gd, 0);
		ft_putstr("\033[0m\n");
		draw_end_img(gd);
	}
}

void	move_player(int coord_x, int coord_y, t_game_data *gd)
{
	char	c;

	c = gd->map[gd->player->y - coord_y][gd->player->x + coord_x];
	if (c != '1')
	{
		/* update_animations(gd->exit_anim_data);
		put_animations(gd); */
		/////
		move_enemies(gd);
		gd->map[gd->player->y][gd->player->x] = '0';
		gd->player->y -= coord_y;
		gd->player->x += coord_x;
		gd->map[gd->player->y][gd->player->x] = 'P';
		change_player_sprite(coord_x, coord_y, gd);
		gd->player_moves++;
		display_stats(gd, 1);
		if (c == 'C')
			gd->player_items++;
		if (c == 'E')
			move_exit(gd);
		if (c == 'M')
			touch_enemy(gd);
		put_map(gd);
	}
}
