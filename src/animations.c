/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 17:11:15 by adiban-i          #+#    #+#             */
/*   Updated: 2024/12/27 18:04:39 by adiban-i         ###   ########.fr       */
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

static char	*get_animation_asset(int frame_index)
{
	char	*asset;

	asset = ft_strjoin("./assets/exit_anim/", frame_index);
	return (asset);
}

void	put_animations(t_game_data *gd)
{
	int		frame_index;
	int		x;
	int		y;
	char	*asset;

	frame_index = gd->exit_anim_data->current_frame;
	x = gd->exit_anim_data->position_x;
	y = gd->exit_anim_data->position_y;
	asset = get_animation_asset(frame_index);
	draw_img(gd, x, y, asset);
	free(asset);
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
