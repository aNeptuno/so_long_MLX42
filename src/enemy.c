/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:15:01 by adiban-i          #+#    #+#             */
/*   Updated: 2024/07/03 18:37:22 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Draw enemy on map
void	put_enemy(t_game_data *gd, int i, int j)
{
	mlx_put_image_to_window(gd->mlx, gd->window,
			gd->sprites->enemy, j * PIXELS, (i * PIXELS) + HEADER_HEIGHT);

	if (gd->enemy_index < gd->num_enemies)
	{
		gd->enemies[gd->enemy_index].position->x = j;
		gd->enemies[gd->enemy_index].position->y = i;
	}
}

// Data init
static void	count_enemies(t_game_data *gd)
{
	int	i;
	int	j;

	i = 0;
	gd->num_enemies = 0;
	gd->enemy_index = 0;
	while (i < gd->rows)
	{
		j = 0;
		while (j < gd->cols)
		{
			if (gd->map[i][j] == 'M')
				gd->num_enemies++;
			j++;
		}
		i++;
	}
}

void	init_enemies(t_game_data *gd)
{
	int	i;

	count_enemies(gd);
	if (gd->num_enemies == 0)
		return ;
	
	gd->enemies = malloc(sizeof(t_enemy) * gd->num_enemies);
	if (!gd->enemies)
	{
		perror("Error\nMalloc failed for game_data.enemies\n");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < gd->num_enemies)
    {
        gd->enemies[i].position = malloc(sizeof(t_point));
        if (!gd->enemies[i].position)
        {
            perror("Error\nMalloc failed for game_data.enemies.position\n");
            exit(EXIT_FAILURE);
        }
		gd->enemies[i].move_direction = 1;
		i++;
    }
}

// Player and enemy interaction
void	touch_enemy(t_game_data *gd)
{
	gd->game_ended = 1;
	ft_putstr("\033[1;31m");
	ft_putstr("\nAntimatter lifeform reached you! You lost!\n");
	ft_putstr("\033[0m\n");
}

static int	enemy_can_move(char c)
{
	return (c != '1' && c != 'C' && c != 'E');
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
	else if (new_x >= 0 && new_x < gd->cols && enemy_can_move(gd->map[y][new_x]))
	{
        gd->map[y][x] = '0';
        enemy->position->x = new_x;
		if (gd->map[y][x] == 'P')
			touch_enemy(gd);
        gd->map[y][new_x] = 'M';
    }
}

void	move_enemies(t_game_data *gd)
{
	int	i;

	i = 0;
	while (i < gd->num_enemies)
	{
		move_enemy(&gd->enemies[i], gd);
		i++;
	}
}