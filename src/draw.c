/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 18:27:16 by adiban-i          #+#    #+#             */
/*   Updated: 2024/12/27 20:20:08 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	draw_init(t_game_data *gd, int i, int j, char *path)
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
	if (mlx_image_to_window(gd->mlx, img, j, i) < 0)
	{
		ft_putstr("Error\nError instanciating img-> ");
		perror(path);
		exit(EXIT_FAILURE);
	}
}

void	draw_end_img_util(t_game_data *gd, char *path)
{
	int	x;
	int	y;

	x = gd->size_x / 2 - 288;
	y = gd->size_y / 2 + HEADER_HEIGHT / 2 - 162;
	draw_img(gd, 0, 0, path);
}


void	draw_end_img(t_game_data *gd)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;
	char			*path;

	draw_img(gd, 0, 0, "./assets/bg/black.png");
	if (gd->win)
		draw_img(gd, 0, 0, "./assets/bg/gamendwin.png");
	else
		draw_img(gd, 0, 0, "./assets/bg/gamendlost.png");
}
