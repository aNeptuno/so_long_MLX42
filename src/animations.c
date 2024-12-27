/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 17:11:15 by adiban-i          #+#    #+#             */
/*   Updated: 2024/12/27 20:05:46 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_anim_data(t_game_data *gd)
{
	gd->exit_anim_data = malloc(sizeof(t_anim_data));
	if (gd->exit_anim_data == NULL)
	{
		perror("Error\nMalloc failed for exit_anim_data\n");
		exit(EXIT_FAILURE);
	}
	gd->exit_anim_data->current_frame = 1;
	gd->exit_anim_data->frame_count = 6;
}

static void	update_animations(t_anim_data *anim_data)
{
	anim_data->current_frame = (anim_data->current_frame + 1)
		% anim_data->frame_count;
}

static void	put_animations(t_game_data *gd, int i, int j)
{
	int		frame_index;
	int		x;
	int		y;
	char	*tmp;
	char	*asset;

	frame_index = gd->exit_anim_data->current_frame;
	tmp = ft_strjoin("./assets/exit_anim/", ft_itoa(frame_index));
	asset = ft_strjoin(tmp, ".png");
	draw_img(gd, i, j, asset);
	free(asset);
	free(tmp);
}

void	handle_exit_sprite(t_game_data *gd, int j, int i)
{
	if (gd->first_init)
	{
		draw_img(gd, i, j, "./assets/exit.png");
	}
	else
	{
		update_animations(gd->exit_anim_data);
		put_animations(gd, i, j);
	}
}
