/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 01:53:27 by adiban-i          #+#    #+#             */
/*   Updated: 2024/12/27 20:00:42 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	close_window(void *param)
{
	t_game_data	*gd;

	gd = (t_game_data *) param;
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
	mlx_close_window(gd->mlx);
	exit(EXIT_SUCCESS);
}

void	move_hook(mlx_key_data_t keydata, void *data)
{
	t_game_data	*gd;

	gd = (t_game_data *) data;
	if (mlx_is_key_down(gd->mlx, MLX_KEY_ESCAPE))
		close_window(gd);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		move_player(0, 1, gd);
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		move_player(0, -1, gd);
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		move_player(-1, 0, gd);
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		move_player(1, 0, gd);
}
