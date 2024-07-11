/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 19:32:07 by adiban-i          #+#    #+#             */
/*   Updated: 2024/07/03 17:58:27 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_mlx(t_game_data *gd)
{
	gd->mlx = mlx_init();
	if (gd->mlx == NULL)
	{
		perror("Error\nmlx init failed\n");
		exit(EXIT_FAILURE);
	}
	gd->window = mlx_new_window(gd->mlx, gd->size_x, gd->size_y, "so_long");
	if (gd->window == NULL)
	{
		mlx_destroy_display(gd->mlx);
		free(gd->mlx);
		exit(EXIT_FAILURE);
	}
}

static void	init_game(t_game_data *gd)
{
	gd->new_move = 'D';
	gd->player_moves = 0;
	gd->player_items = 0;
	gd->map_items = 0;
	gd->move_up = 0;
	gd->move_down = 0;
	gd->move_left = 0;
	gd->move_right = 0;
	gd->update_counter = 0;
	gd->game_ended = 0;
	gd->player = malloc(sizeof(t_point));
	gd->first_init = 1;
	gd->win = 0;
	init_enemies(gd);
	init_sprites(gd);
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
			mlx_hook(game_data.window, 17, 0, &close_window, &game_data);
			mlx_hook(game_data.window, 2, 1L << 0, key_press, &game_data);
			mlx_hook(game_data.window, 3, 1L << 1, key_release, &game_data);
			mlx_loop_hook(game_data.mlx, render_next_frame_loop, &game_data);
			mlx_loop(game_data.mlx);
			perror("Error\nMlx loop failed\n");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		ft_putstr("Error\nInvalid arguments\nUsage: <map_name>.ber");
		exit(EXIT_FAILURE);
	}
	return (0);
}
