/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 18:27:16 by adiban-i          #+#    #+#             */
/*   Updated: 2024/12/27 18:46:35 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


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

	if (gd->win)
		draw_img(gd, 0, 0, "./assets/bg/gamendwin.png");
	else
		draw_img(gd, 0, 0, "./assets/bg/gamendlost.png");
}