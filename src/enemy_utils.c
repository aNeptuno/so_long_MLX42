/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 13:14:12 by adiban-i          #+#    #+#             */
/*   Updated: 2024/12/08 18:22:29 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		gd->enemies[i].vertical = 0;
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

// Draw enemy on map
void	update_enemy(t_game_data *gd, int i, int j)
{
	if (gd->enemy_index < gd->num_enemies)
	{
		gd->enemies[gd->enemy_index].position->x = j;
		gd->enemies[gd->enemy_index].position->y = i;
	}
	else
		gd->enemy_index = 0;
}

void	check_vertical(t_game_data *gd, t_enemy *enemy)
{
	int		y;
	int		x;

	y = enemy->position->y;
	x = enemy->position->x;
	if (!enemy_can_move(gd->map[y][x + 1])
		&& !enemy_can_move(gd->map[y][x - 1]))
	{
		enemy->vertical = 1;
	}
}
