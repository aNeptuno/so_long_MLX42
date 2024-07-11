/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 17:11:15 by adiban-i          #+#    #+#             */
/*   Updated: 2024/07/03 14:03:42 by adiban-i         ###   ########.fr       */
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

void	load_animations(t_game_data *gd)
{
	char	i[1];
	char	*path;
	char	*tmp;
	int		img_width;
	int		img_height;

	init_anim_data(gd);
	i[0] = '0';
	while (i[0] <= '5')
	{
		tmp = ft_strjoin("./assets/exit_anim/", i);
		path = ft_strjoin(tmp, ".xpm");
		gd->sprites->exit_anim_frames[i[0] - 48] = mlx_xpm_file_to_image(
				gd->mlx, path, &img_width, &img_height);
		if (gd->sprites->exit_anim_frames[i[0] - 48] == NULL)
		{
			perror("Error\nError loading exit anim frames.\n");
			exit(EXIT_FAILURE);
		}
		i[0]++;
		free(path);
		free(tmp);
	}
}

void	put_animations(t_game_data *gd)
{
	int	frame_index;
	int	x;
	int	y;

	frame_index = gd->exit_anim_data->current_frame;
	x = gd->exit_anim_data->position_x;
	y = gd->exit_anim_data->position_y;
	mlx_put_image_to_window(gd->mlx, gd->window,
		gd->sprites->exit_anim_frames[frame_index], x, y);			
}
