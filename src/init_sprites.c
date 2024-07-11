/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:47:35 by adiban-i          #+#    #+#             */
/*   Updated: 2024/07/03 18:36:49 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_error_img(void *img, char *info)
{
	if (img == NULL)
	{
		ft_putstr("Error\nError loading image-> ");
		perror(info);
		exit(EXIT_FAILURE);
	}
}

static void	init_sprites_player(t_game_data *game_data)
{
	char	*rel_path;
	int		w;
	int		h;

	rel_path = "./assets/cat_up.xpm";
	game_data->sprites->player_up = mlx_xpm_file_to_image(game_data->mlx,
			rel_path, &w, &h);
	check_error_img(game_data->sprites->player_up, "player");
	rel_path = "./assets/cat_down.xpm";
	game_data->sprites->player_down = mlx_xpm_file_to_image(game_data->mlx,
			rel_path, &w, &h);
	check_error_img(game_data->sprites->player_down, "player");
	rel_path = "./assets/cat_left.xpm";
	game_data->sprites->player_left = mlx_xpm_file_to_image(game_data->mlx,
			rel_path, &w, &h);
	check_error_img(game_data->sprites->player_left, "player");
	rel_path = "./assets/cat_right.xpm";
	game_data->sprites->player_right = mlx_xpm_file_to_image(game_data->mlx,
			rel_path, &w, &h);
	check_error_img(game_data->sprites->player_right, "player");
}

static void	init_walls_and_header(t_game_data *gd)
{
	char	*rel_path;
	int		w;
	int		h;

	rel_path = "./assets/wall.xpm";
	gd->sprites->obstacle = mlx_xpm_file_to_image(gd->mlx,
			rel_path, &w, &h);
	check_error_img(gd->sprites->obstacle, "obstacle");
	rel_path = "./assets/title.xpm";
	gd->sprites->header = mlx_xpm_file_to_image(gd->mlx,
			rel_path, &w, &h);
	check_error_img(gd->sprites->header, "header");
	rel_path = "./assets/bg/lost.xpm";
	gd->sprites->lost = mlx_xpm_file_to_image(gd->mlx,
			rel_path, &w, &h);
	check_error_img(gd->sprites->lost, "lost");
	resize_end_img(gd, w, h, 0);
	rel_path = "./assets/bg/win.xpm";
	gd->sprites->win = mlx_xpm_file_to_image(gd->mlx,
			rel_path, &w, &h);
	check_error_img(gd->sprites->win, "win");
	resize_end_img(gd, w, h, 1);
}

static void	init_objects(t_game_data *game_data)
{
	char	*rel_path;
	int		w;
	int		h;

	rel_path = "./assets/item.xpm";
	game_data->sprites->collectable = mlx_xpm_file_to_image(game_data->mlx,
			rel_path, &w, &h);
	check_error_img(game_data->sprites->collectable, "collectable");
	rel_path = "./assets/exit.xpm";
	game_data->sprites->exit = mlx_xpm_file_to_image(game_data->mlx,
			rel_path, &w, &h);
	check_error_img(game_data->sprites->exit, "exit");
	rel_path = "./assets/monsters/slimeman.xpm";
	game_data->sprites->enemy = mlx_xpm_file_to_image(game_data->mlx,
			rel_path, &w, &h);
	check_error_img(game_data->sprites->enemy, "enemy");
}

void	init_sprites(t_game_data *gd)
{
	char	*rel_path;
	int		w;
	int		h;

	gd->sprites = malloc(sizeof(t_sprites));
	if (gd->sprites == NULL)
	{
		perror("Error\nMalloc failed for game_data.sprites\n");
		exit(EXIT_FAILURE);
	}
	rel_path = "./assets/bg.xpm";
	gd->sprites->bg = mlx_xpm_file_to_image(gd->mlx,
			rel_path, &w, &h);
	check_error_img(gd->sprites->bg, "background");
	resize_bg_image(gd, w, h);
	init_walls_and_header(gd);
	init_objects(gd);
	init_sprites_player(gd);
	load_animations(gd);
}
