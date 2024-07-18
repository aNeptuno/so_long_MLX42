/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 01:53:27 by adiban-i          #+#    #+#             */
/*   Updated: 2024/07/02 17:00:38 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_game_data *gd)
{
	if (!gd->game_ended)
	{
		ft_putstr("\033[1;31m");
		ft_putstr("\nNooo, you gave up :'c\n");
		ft_putstr("\033[0m\n");
	}
	else
	{
		ft_putstr("\033[1;33m");
		ft_putstr("\nThanks for playing ^^!\n");
		ft_putstr("\033[0m\n");
	}
	/* if (gd->window)
	{
		mlx_destroy_window(gd->mlx, gd->window);
		gd->window = NULL;
	}
	if (gd->mlx)
	{
		mlx_destroy_display(gd->mlx);
		gd->mlx = NULL;
	} */
	//free_game_data(gd);
	exit(EXIT_SUCCESS);
	return (0);
}

static void	reset_gd_moves(t_game_data *gd)
{
	gd->move_up = 0;
	gd->move_down = 0;
	gd->move_left = 0;
	gd->move_right = 0;
}

int	key_press(int keycode, t_game_data *gd)
{
	if (keycode == ESC)
		close_window(gd);
	if (keycode == UP)
	{
		reset_gd_moves(gd);
		gd->move_up = 1;
	}
	else if (keycode == DOWN)
	{
		reset_gd_moves(gd);
		gd->move_down = 1;
	}
	else if (keycode == LEFT)
	{
		reset_gd_moves(gd);
		gd->move_left = 1;
	}
	else if (keycode == RIGHT)
	{
		reset_gd_moves(gd);
		gd->move_right = 1;
	}
	printf("keycode: %d\n", keycode);
	return (0);
}

int	key_release(int keycode, t_game_data *gd)
{
	if (keycode == LEFT || keycode == RIGHT || keycode == UP || keycode == DOWN)
		reset_gd_moves(gd);
	return (0);
}
