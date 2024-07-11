/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 11:56:35 by adiban-i          #+#    #+#             */
/*   Updated: 2024/07/03 18:31:38 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Obtain pixel color in image
static int	get_pixel_color(void *img, int x, int y)
{
	char	*data;
	int		bpp;
	int		size_line;
	int		endian;

	data = mlx_get_data_addr(img, &bpp, &size_line, &endian);
	return (*(int *)(data + (y * size_line + x * (bpp / 8))));
}

// Stablish pixel color in image
static void	set_pixel_color(void *img, int x, int y, int color)
{
	char	*data;
	int		bpp;
	int		size_line;
	int		endian;

	data = mlx_get_data_addr(img, &bpp, &size_line, &endian);
	*(int *)(data + (y * size_line + x * (bpp / 8))) = color;
}

static void	check_error_create_img(t_game_data *gd, int bg, int win)
{
	if (bg && !gd->sprites->bg_resized)
	{
		perror("Error\nFailed to create new bg image");
		exit(EXIT_FAILURE);
	}
	else if (!bg && win && !gd->sprites->win_resized)
	{
		perror("Error\nFailed to create new win image");
		exit(EXIT_FAILURE);
	}
	else if (!bg && !win && !gd->sprites->lost_resized)
	{
		perror("Error\nFailed to create new lost image");
		exit(EXIT_FAILURE);
	}
}

// Function for resizing an image
void	resize_bg_image(t_game_data *gd, int original_width, int original_height)
{
	int	x;
	int	y;
	int	old_x;
	int	old_y;

	gd->sprites->bg_resized = mlx_new_image(gd->mlx, gd->size_x, gd->size_y);
	check_error_create_img(gd, 1, 0);
	y = 0;
	while (y < gd->size_y)
	{
		x = 0;
		while (x < gd->size_x)
		{
			old_x = (int)(x * ((float)original_width / (float)gd->size_x));
			old_y = (int)(y * ((float)original_height / (float)gd->size_y));
			set_pixel_color(gd->sprites->bg_resized, x, y,
				get_pixel_color(gd->sprites->bg, old_x, old_y));
			x++;
		}
		y++;
	}
	return ;
}

// Function for resizing end game images
void	resize_end_img(t_game_data *gd, int original_width, int original_height, int win)
{
	int	x;
	int	y;
	int	old_x;
	int	old_y;

	if (win)
		gd->sprites->win_resized = mlx_new_image(gd->mlx, gd->size_x, gd->size_y);
	else
		gd->sprites->lost_resized = mlx_new_image(gd->mlx, gd->size_x, gd->size_y);
	check_error_create_img(gd, 0, win);
	y = 0;
	while (y < gd->size_y)
	{
		x = 0;
		while (x < gd->size_x)
		{
			old_x = (int)(x * ((float)original_width / (float)gd->size_x));
			old_y = (int)(y * ((float)original_height / (float)gd->size_y));
			if (win)
			{
				set_pixel_color(gd->sprites->win_resized, x, y,
					get_pixel_color(gd->sprites->win, old_x, old_y));
			}
			else
			{
				set_pixel_color(gd->sprites->lost_resized, x, y,
					get_pixel_color(gd->sprites->lost, old_x, old_y));
			}
			x++;
		}
		y++;
	}
	
	return ;
}
