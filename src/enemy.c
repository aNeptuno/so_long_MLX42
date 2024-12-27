/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:15:01 by adiban-i          #+#    #+#             */
/*   Updated: 2024/12/27 20:12:55 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	enemy_can_move(char c)
{
	return (c != '1' && c != 'C' && c != 'E');
}

static void	move_enemy_vertical(t_enemy *enemy, t_game_data *gd)
{
	int		y;
	int		x;
	int		new_y;

	y = enemy->position->y;
	x = enemy->position->x;
	new_y = y + enemy->move_direction;
	if (new_y < 0 || new_y >= gd->rows)
	{
		enemy->move_direction *= -1;
		new_y = y + enemy->move_direction;
	}
	else if (!enemy_can_move(gd->map[new_y][x]))
	{
		enemy->move_direction *= -1;
		new_y = y + enemy->move_direction;
	}
	else if (new_y >= 0 && x < gd->cols && enemy_can_move(gd->map[new_y][x]))
	{
		gd->map[y][x] = '0';
		enemy->position->y = new_y;
		if (gd->map[y][x] == 'P')
			touch_enemy(gd);
		gd->map[new_y][x] = 'M';
	}
}

static void	move_to_pos(t_enemy *enemy, t_game_data *gd, int new_x, int x)
{
	int	y;

	y = enemy->position->y;
	gd->map[y][x] = '0';
	enemy->position->x = new_x;
	if (gd->map[y][x] == 'P')
		touch_enemy(gd);
	gd->map[y][new_x] = 'M';
}

static void	move_enemy(t_enemy *enemy, t_game_data *gd)
{
	int		y;
	int		x;
	int		new_x;

	y = enemy->position->y;
	x = enemy->position->x;
	new_x = x + enemy->move_direction;
	if (new_x < 0 || new_x >= gd->cols)
	{
		enemy->move_direction *= -1;
		new_x = x + enemy->move_direction;
	}
	else if (!enemy_can_move(gd->map[y][new_x]))
	{
		enemy->move_direction *= -1;
		new_x = x + enemy->move_direction;
	}
	else if (new_x >= 0 && new_x < gd->cols
		&& enemy_can_move(gd->map[y][new_x]))
	{
		move_to_pos(enemy, gd, new_x, x);
	}
}

void	move_enemies(t_game_data *gd)
{
	int	i;

	i = 0;
	while (i < gd->num_enemies)
	{
		check_vertical(gd, &gd->enemies[i]);
		if (!gd->enemies[i].vertical)
			move_enemy(&gd->enemies[i], gd);
		else
			move_enemy_vertical(&gd->enemies[i], gd);
		i++;
	}
}
