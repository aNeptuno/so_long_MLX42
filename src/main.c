/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 19:32:07 by adiban-i          #+#    #+#             */
/*   Updated: 2024/12/27 19:27:48 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_mlx(t_game_data *gd)
{
	gd->mlx = mlx_init(gd->size_x, gd->size_y + 32, "so_long", false);
	if (gd->mlx == NULL)
	{
		perror("Error\nmlx init failed\n");
		exit(EXIT_FAILURE);
	}
}

static void	init_game(t_game_data *gd)
{
	gd->new_move = 'D';
	gd->player_moves = 0;
	gd->player_items = 0;
	gd->map_items = 0;
	gd->game_ended = 0;
	gd->player = malloc(sizeof(t_point));
	gd->first_init = 1;
	gd->win = 0;
	gd->exit_anim_data = malloc(sizeof(t_anim_data));
	gd->update_counter = 0;
	init_enemies(gd);
	put_map(gd);
}

int	main(int ac, char **av)
{
	t_game_data	game_data;

	if (ac == 2)
	{
		get_map(&game_data, av[1]);
		if (game_data.is_map_valid)
		{
			init_mlx(&game_data);
			init_game(&game_data);
			mlx_key_hook(game_data.mlx, move_hook, &game_data);
			mlx_close_hook(game_data.mlx, close_window, &game_data);
			mlx_loop(game_data.mlx);
			mlx_terminate(game_data.mlx);
			free_game_data(&game_data);
			return (EXIT_SUCCESS);
		}
	}
	else
	{
		ft_putstr("Error\nInvalid arguments\nUsage: <map_name>.ber\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}
