/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:24:42 by adiban-i          #+#    #+#             */
/*   Updated: 2024/07/03 18:37:08 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "../MLX42/include/MLX42/MLX42.h"

# define MAX_ROWS 100
# define MAX_COLS 100
# define BUFFER_SIZE 1024
# define ESC 65307
# define UP 119
# define DOWN 115
# define RIGHT 100
# define LEFT 97
# define PIXELS 32
# define HEADER_HEIGHT 50
# define UPDATE_FREQ 3500
# define ENEMY_FREQ 10000

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

/// @brief Structure for persistent animation data
/**
 * @current_frame: Frame index.
 * @frame_count: Number of frames in idle animation.
 * @frame_delay: Adjust the delay to control the animation speed.
 * @frame_counter: Counter to manage frame change timing.
 * @position_x: coord x of the sprite.
 * @position_y: coord y of the sprite.
 */
typedef struct s_anim_data
{
	int	current_frame;
	int	frame_count;
	int	frame_delay;
	int	frame_counter;
	int	position_x;
	int	position_y;
}	t_anim_data;

/// @brief Structure for game sprites (mlx_xpm_file_to_image)
typedef struct s_sprites
{
	void	*bg;
	void	*bg_resized;
	void	*lost;
	void	*lost_resized;
	void	*win;
	void	*win_resized;
	void	*player_up;
	void	*player_left;
	void	*player_right;
	void	*player_down;
	void	*obstacle;
	void	*collectable;
	void	*exit;
	void	*header;
	void	*exit_anim_frames[6];
	void	*enemy;
}		t_sprites;

/// @brief Structure for enemy data
typedef struct s_enemy
{
	t_point	*position;
	int		move_direction;
}	t_enemy;

/// @brief Structure for saving game data
/**
 * @file_content: Content of the .ber file.
 * @fd: File descriptor for the .ber file.
 * @map: 2D array representing the game map.
 * @cols: Number of columns in the map.
 * @rows: Number of rows in the map.
 * @is_map_valid: Flag indicating if the map is valid.
 * @mlx: Pointer to mlx connection.
 * @window: Window created by mlx.
 * @size_x: Width of the window in pixels (cols * 32).
 * @size_y: Height of the window in pixels (rows * 32).
 * @map_items: Number of items to collect in the map.
 * @first_init: Flag indicating if this is the first initialization.
 * @sprites: Pointer to the sprites structure for the game.
 * @player_moves: Counter for the number of moves made by the player.
 * @player: Pointer to the player position structure.
 * @new_move: New move direction: U (up), D(down), L(left), R(right).
 * @player_items: Number of items collected by the player.
 * @move_up: Flag indicating if the up move key is pressed.
 * @move_down: Flag indicating if the down move key is pressed.
 * @move_left: Flag indicating if the left move key is pressed.
 * @move_right: Flag indicating if the right move key is pressed.
 * @update_counter: Counter for updating the game state.
 * @game_ended: Flag indicating if the game has ended.
 * @exit_anim_data: Contains necessary data to render exit animation.
 */
typedef struct s_game_data
{
	char		*file_content;
	int			fd;
	char		**map;
	int			cols;
	int			rows;
	int			is_map_valid;
	void		*mlx;
	void		*window;
	int			size_x;
	int			size_y;
	int			map_items;
	int			first_init;
	t_sprites	*sprites;
	int			player_moves;
	t_point		*player;
	char		new_move;
	int			player_items;
	int			move_up;
	int			move_down;
	int			move_left;
	int			move_right;
	int			update_counter;
	int			game_ended;
	t_anim_data	*exit_anim_data;
	t_enemy		*enemies;
	int			num_enemies;
	int			enemy_index;
	int			enemy_move_counter;
	int			win;
}	t_game_data;

// Libft functions
int		ft_strlen(const char *str);
void	ft_putstr(char *s);
char	*ft_strstr(const char *haystack, const char *needle);
void	*my_realloc(void *ptr, size_t newsize, size_t oldsize);
char	**ft_split(char const *s, char c);
void	*ft_memcpy(void *dst, const void *src, size_t len);
char	*ft_itoa(int n);
char	*ft_strjoin(char const *s1, char const *s2);

// Game initialization and data cleaning
void	get_map(t_game_data *game_data, char *file_content);
void	resize_bg_image(t_game_data *gd, int original_width, int original_height);
void	resize_end_img(t_game_data *gd, int original_width, int original_height, int win);
void	init_sprites(t_game_data *game_data);
void	init_enemies(t_game_data *gd);
void	error_and_free(t_game_data *game_data, char *msg);
void	free_game_data(t_game_data *game_data);
void	load_animations(t_game_data *gd);

// Map validation
void	get_cols(t_game_data *game_data);
void	get_rows(t_game_data *game_data);
void	get_map_matrix(t_game_data *game_data);
void	check_limits(t_game_data *game_data);
void	validate_map(t_game_data *game_data);
void	map_error(t_game_data *gd, char *msg);

// Mlx hooks
int		close_window(t_game_data *gd);
int		key_press(int keycode, t_game_data *gd);
int		key_release(int keycode, t_game_data *gd);

// Sprites rendering and character movement
void	put_map(t_game_data *gd);
void	put_enemy(t_game_data *gd, int i, int j);
void	put_animations(t_game_data *gd);
void	render_next_frame_loop(void	*gd);
void	draw_end_img(t_game_data *gd);

// Enemies
void	move_enemies(t_game_data *gd);
void	touch_enemy(t_game_data *gd);

#endif