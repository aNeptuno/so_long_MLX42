/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 18:27:16 by adiban-i          #+#    #+#             */
/*   Updated: 2024/12/08 18:53:10 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* void	draw_end_img(t_game_data *gd)
{
	int	x;
	int	y;

	x = gd->size_x / 2 - 288;
	y = gd->size_y / 2 + HEADER_HEIGHT / 2 - 162;
	if (gd->win)
		mlx_image_to_window(gd->mlx, gd->sprites->win, x, y);
	else
		mlx_image_to_window(gd->mlx, gd->sprites->lost, x, y);
} */

void	draw_end_img_util(t_game_data *gd, mlx_image_t *img, char *path)
{
	int	x;
	int	y;

	x = gd->size_x / 2 - 288;
	y = gd->size_y / 2 + HEADER_HEIGHT / 2 - 162;
	if (mlx_image_to_window(gd->mlx, img, x, y < 0))
	{
		ft_putstr("Error\nError instanciating img-> ");
		perror(path);
		exit(EXIT_FAILURE);
	}
}


void	draw_end_img(t_game_data *gd)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;
	char			*path;

	if (gd->win)
		path = "./assets/bg/gamendwin.png";
	else
		path = "./assets/bg/gamendlost.png";
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
	if (gd->win)
		draw_end_img_util(gd->mlx, img, path);
	else
		draw_end_img_util(gd->mlx, img, path);
}