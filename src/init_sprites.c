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

static void	load_texture_img(char *path, void **sprite, t_game_data *gd)
{
	void	*texture;

	texture = mlx_load_png(path);
	if (!texture)
	{
		ft_putstr("Error\nError loading texture-> ");
		perror(path);
		exit(EXIT_FAILURE);
	}
	*sprite = mlx_texture_to_image(gd->mlx, texture);
	if (sprite == NULL)
	{
		ft_putstr("Error\nError loading image-> ");
		perror(path);
		exit(EXIT_FAILURE);
	}
	//mlx_delete_image(gd->mlx, texture);
	mlx_delete_texture(texture);
}

/// @brief Loads texture and save it to be able to make an img from it later
static void	load_texture_into_data(void **text, char *path, void **img, t_game_data *gd)
{
	*text = mlx_load_png(path);
	if (*text == NULL)
	{
		ft_putstr("Error\nError loading texture-> ");
		perror(path);
		exit(EXIT_FAILURE);
	}
	*img = mlx_texture_to_image(gd->mlx, *text);
	if (*img == NULL)
	{
		ft_putstr("Error\nError loading image-> ");
		perror(path);
		exit(EXIT_FAILURE);
	}
}
static void	init_sprites_player(t_game_data *gd)
{
	load_texture_into_data(&gd->sprites->player_up_text, "./assets/cat_up.png",
		&gd->sprites->player_up, gd);
	load_texture_into_data(&gd->sprites->player_down_text, "./assets/cat_down.png",
		&gd->sprites->player_down, gd);
	load_texture_into_data(&gd->sprites->player_left_text, "./assets/cat_left.png",
		&gd->sprites->player_left, gd);
	load_texture_into_data(&gd->sprites->player_right_text, "./assets/cat_right.png",
		&gd->sprites->player_right, gd);
}

static void	init_objects(t_game_data *gd)
{
	load_texture_img("./assets/bg/bg.png", &gd->sprites->bg, gd);
	load_texture_img("./assets/wall.png", &gd->sprites->obstacle, gd);
	load_texture_img("./assets/title.png", &gd->sprites->header, gd);
	load_texture_img("./assets/bg/black.png", &gd->sprites->clean_img, gd);
	load_texture_img("./assets/bg/gamendlost.png", &gd->sprites->lost, gd);
	load_texture_img("./assets/bg/gamendwin.png", &gd->sprites->win, gd);
	load_texture_img("./assets/exit.png", &gd->sprites->exit, gd);
	load_texture_into_data(&gd->sprites->collectable_text, "./assets/item.png",
		&gd->sprites->collectable, gd);
	load_texture_into_data(&gd->sprites->enemy_text, "./assets/slimeman.png",
		&gd->sprites->enemy, gd);
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
	init_sprites_player(gd);
	load_animations(gd);
}
