/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 17:11:15 by adiban-i          #+#    #+#             */
/*   Updated: 2024/07/19 13:25:10 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_anim_data(t_game_data *gd)
{
	gd->exit_anim_data = malloc(sizeof(t_anim_data));
	if (gd->exit_anim_data == NULL)
	{
		perror("Error\nMalloc failed for exit_anim_data\n");
		exit(EXIT_FAILURE);
	}
	gd->exit_anim_data->current_frame = 0;
	gd->exit_anim_data->frame_count = 6;
	gd->exit_anim_data->frame_delay = 5;
	gd->exit_anim_data->frame_counter = 0;
}

static void	show_error(int is_null, char *msg)
{
	if (is_null)
	{
		ft_putstr("Error\n");
		ft_putstr(msg);
		perror("");
		exit(EXIT_FAILURE);
	}
}

void	load_animations(t_game_data *gd)
{
	char	i[1];
	char	*path;
	char	*tmp;
	void	*texture;

	init_anim_data(gd);
	i[0] = '0';
	while (i[0] <= '5')
	{
		tmp = ft_strjoin("./assets/exit_anim/", i);
		path = ft_strjoin(tmp, ".png");
		texture = mlx_load_png(path);
		show_error(!texture, "Error loading exit anim texture: ");
		gd->sprites->exit_anim_frames[i[0] - 48] = mlx_texture_to_image(
				gd->mlx, texture);
		show_error(!gd->sprites->exit_anim_frames[i[0] - 48],
			"Error loading exit anim frames: ");
		i[0]++;
		free(path);
		free(tmp);
	}
	mlx_delete_texture(texture);
}

void	put_animations(t_game_data *gd)
{
	int	frame_index;
	int	x;
	int	y;

	frame_index = gd->exit_anim_data->current_frame;
	x = gd->exit_anim_data->position_x;
	y = gd->exit_anim_data->position_y;
	mlx_image_to_window(gd->mlx,
		gd->sprites->exit_anim_frames[frame_index], x, y);
}

void	handle_exit_sprite(t_game_data *gd, int j, int i)
{
	if (gd->first_init)
	{
		draw_img(gd, i, j, "./assets/exit.png");
		gd->exit_anim_data->position_x = j * PIXELS;
		gd->exit_anim_data->position_y = (i * PIXELS) + HEADER_HEIGHT;
	}
	else
	{
		put_animations(gd);
	}
}
