/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:47:35 by adiban-i          #+#    #+#             */
/*   Updated: 2024/07/30 12:15:32 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_error_img_or_texture(void *img, char *info, int texture)
{
	if (img == NULL)
	{
		if (!texture)
			ft_putstr("Error\nError loading image-> ");
		else
			ft_putstr("Error\nError loading texture-> ");
		perror(info);
		exit(EXIT_FAILURE);
	}
}

static void	init_sprites_player(t_game_data *gd)
{
	void	*texture;

	load_and_check_texture("./assets/cat_up.png", "cat_up", texture);
	gd->sprites->player_up = mlx_texture_to_image(gd->mlx, texture);
	check_error_img_or_texture(gd->sprites->player_up, "player_up", 0);
	mlx_delete_texture(texture);
	load_and_check_texture("./assets/cat_down.png", "cat_down", texture);
	gd->sprites->player_down = mlx_texture_to_image(gd->mlx, texture);
	check_error_img_or_texture(gd->sprites->player_down, "player_down", 0);
	mlx_delete_texture(texture);
	load_and_check_texture("./assets/cat_left.png", "cat_left", texture);
	gd->sprites->player_left = mlx_texture_to_image(gd->mlx, texture);
	check_error_img_or_texture(gd->sprites->player_left, "player_left", 0);
	mlx_delete_texture(texture);
	load_and_check_texture("./assets/cat_right.png", "cat_right", texture);
	gd->sprites->player_right = mlx_texture_to_image(gd->mlx, texture);
	check_error_img_or_texture(gd->sprites->player_right, "player_right", 0);
	mlx_delete_texture(texture);
}

static void	init_walls_and_header(t_game_data *gd)
{
	void	*texture;

	load_and_check_texture("./assets/wall.png", "obstacle", texture);
	gd->sprites->obstacle = mlx_texture_to_image(gd->mlx, texture);
	check_error_img_or_texture(gd->sprites->obstacle, "obstacle", 0);
	mlx_delete_texture(texture);
	load_and_check_texture("./assets/title.png", "header", texture);
	gd->sprites->header = mlx_texture_to_image(gd->mlx, texture);
	mlx_delete_texture(texture);
	check_error_img_or_texture(gd->sprites->header, "header", 0);
	load_and_check_texture("./assets/bg/black.png", "clean_img", texture);
	gd->sprites->clean_img = mlx_texture_to_image(gd->mlx, texture);
	check_error_img_or_texture(gd->sprites->clean_img, "clean_img", 0);
	mlx_delete_texture(texture);
	load_and_check_texture("./assets/bg/gamendlost.png", "lost", texture);
	gd->sprites->lost = mlx_texture_to_image(gd->mlx, texture);
	check_error_img_or_texture(gd->sprites->lost, "lost", 0);
	mlx_delete_texture(texture);
	load_and_check_texture("./assets/bg/gamendwin.png", "win", texture);
	gd->sprites->win = mlx_texture_to_image(gd->mlx, texture);
	check_error_img_or_texture(gd->sprites->win, "win", 0);
	mlx_delete_texture(texture);
}

static void	init_objects(t_game_data *gd)
{
	void	*texture;

	load_and_check_texture("./assets/bg/bg.png", "background", texture);
	gd->sprites->bg = mlx_texture_to_image(gd->mlx, texture);
	check_error_img_or_texture(gd->sprites->bg, "background", 0);
	mlx_delete_texture(texture);
	load_and_check_texture("./assets/item.png", "item", texture);
	gd->sprites->collectable = mlx_texture_to_image(gd->mlx, texture);
	check_error_img_or_texture(gd->sprites->collectable, "collectable", 0);
	mlx_delete_texture(texture);
	load_and_check_texture("./assets/exit.png", "exit", texture);
	gd->sprites->exit = mlx_texture_to_image(gd->mlx, texture);
	check_error_img_or_texture(gd->sprites->exit, "exit", 0);
	mlx_delete_texture(texture);
	load_and_check_texture("./assets/slimeman.png", "enemy", texture);
	gd->sprites->enemy = mlx_texture_to_image(gd->mlx, texture);
	check_error_img_or_texture(gd->sprites->enemy, "enemy", 0);
	mlx_delete_texture(texture);
}

void	init_sprites(t_game_data *gd)
{
	gd->sprites = malloc(sizeof(t_sprites));
	if (gd->sprites == NULL)
	{
		perror("Error\nMalloc failed for game_data.sprites\n");
		exit(EXIT_FAILURE);
	}
	init_objects(gd);
	init_walls_and_header(gd);
	init_sprites_player(gd);
	load_animations(gd);
}
