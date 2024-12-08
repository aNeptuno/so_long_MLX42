/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:21:58 by adiban-i          #+#    #+#             */
/*   Updated: 2024/12/08 18:23:54 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* void	reset_imgs(t_game_data *gd)
{
	mlx_delete_image(gd->mlx, gd->sprites->player_up);
	mlx_delete_image(gd->mlx, gd->sprites->player_left);
	mlx_delete_image(gd->mlx, gd->sprites->player_right);
	mlx_delete_image(gd->mlx, gd->sprites->player_down);
	mlx_delete_image(gd->mlx, gd->sprites->collectable);
	mlx_delete_image(gd->mlx, gd->sprites->enemy);
} */

void	draw_img(t_game_data *gd, int i, int j, char *path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png(path);
	if (!texture)
	{
		ft_putstr("Error\nError loading texture-> ");
		perror(path);
		exit(EXIT_FAILURE);
	}
	img = mlx_texture_to_image(gd->mlx, texture);
	mlx_delete_texture(texture);
	if (!img)
	{
		ft_putstr("Error\nError loading image-> ");
		perror(path);
		exit(EXIT_FAILURE);
	}
	if (mlx_image_to_window(gd->mlx, img,
			j * PIXELS, (i * PIXELS) + HEADER_HEIGHT) < 0)
	{
		ft_putstr("Error\nError instanciating img-> ");
		perror(path);
		exit(EXIT_FAILURE);
	}
}

static void	put_player(t_game_data *gd, int i, int j)
{
	void	*player_sprite;

	if (gd->new_move == 'D')
		draw_img(gd, i, j, "./assets/cat_down.png");
	if (gd->new_move == 'U')
		draw_img(gd, i, j, "./assets/cat_up.png");
	if (gd->new_move == 'L')
		draw_img(gd, i, j, "./assets/cat_left.png");
	if (gd->new_move == 'R')
		draw_img(gd, i, j, "./assets/cat_right.png");
	gd->player->x = j;
	gd->player->y = i;
}

static void	put_object_sprite(t_game_data *gd, char c, int i, int j)
{
	if (c == 'P')
		put_player(gd, i, j);
	else if (c == '1' && gd->first_init)
		draw_img(gd, i, j, "./assets/wall.png");
	else if (c == 'E' && gd->first_init)
	{
		handle_exit_sprite(gd, j, i);
	}
	else if (c == 'C')
	{
		draw_img(gd, i, j, "./assets/item.png");
		if (gd->first_init)
			gd->map_items++;
	}
	else if (c == 'M')
	{
		draw_img(gd, i, j, "./assets/slimeman.png");
		update_enemy(gd, i, j);
		gd->enemy_index++;
	}
}

static void	ft_mlx_string(t_game_data *gd, int x, int y, char *title)
{
	mlx_put_string(gd->mlx, title, x, y);
}

static void	draw_header(t_game_data *gd)
{
	int		title_x;
	int		collected_x;
	char	*moves;
	char	*items;

	title_x = (gd->size_x / 2) - 25;
	collected_x = gd->size_x / 20;
	moves = ft_itoa(gd->player_moves);
	items = ft_itoa(gd->player_items);
	mlx_image_to_window(gd->mlx, gd->sprites->header, title_x, 0);
	ft_mlx_string(gd, gd->size_x / 3 - 20, 45,
		"Cybercat Chronicles: The Ancient Floppy Hunt");
	ft_mlx_string(gd, gd->size_x - 200, 30, "Player Moves: ");
	ft_mlx_string(gd, gd->size_x - 50, 30, moves);
	ft_mlx_string(gd, collected_x, 30, "Collected Floppy: ");
	ft_mlx_string(gd, collected_x + 200, 30, items);
	free(moves);
	free(items);
}

void	put_map(t_game_data *gd)
{
	int	i;
	int	j;

	if (gd->first_init)
	{
		mlx_image_to_window(gd->mlx, gd->sprites->clean_img, 0, 0);
		draw_header(gd);
		mlx_image_to_window(gd->mlx, gd->sprites->bg, 0, HEADER_HEIGHT);
	}
	i = 0;
	while (i < gd->rows)
	{
		j = 0;
		while (j < gd->cols)
		{
			put_object_sprite(gd, gd->map[i][j], i, j);
			j++;
		}
		i++;
	}
	gd->first_init = 0;
}
