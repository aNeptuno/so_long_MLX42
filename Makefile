# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/13 11:52:59 by adiban-i          #+#    #+#              #
#    Updated: 2024/12/27 18:06:33 by adiban-i         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# PROGRAM NAME
NAME = so_long

# COMPILER AND FLAGS
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Wunreachable-code -g

# COLORS
BLACK = "\033[0;30m"
RED = "\033[0;31m"
GREEN = "\033[0;32m"
YELLOW = "\033[0;33m"
BLUE = "\033[0;34m"
MAGENTA = "\033[0;35m"
CYAN = "\033[0;36m"
WHITE = "\033[0;37m"
NC = "\033[0;0m"  # NO COLOR
UP = "\033[A"
CUT = "\033[K"

# DIRECTORIES
SRC_DIR = src
LIBFT_DIR = libft_functions

# SOURCE FILES AND OBJECT FILES
SRC_FILES = $(LIBFT_DIR)/ft_split.c \
			$(LIBFT_DIR)/my_realloc.c \
			$(LIBFT_DIR)/general.c \
			$(LIBFT_DIR)/ft_itoa.c \
			$(LIBFT_DIR)/ft_strjoin.c \
			$(LIBFT_DIR)/ft_calloc.c \
			$(SRC_DIR)/main.c \
			$(SRC_DIR)/move_player.c \
			$(SRC_DIR)/mlx_hooks.c \
			$(SRC_DIR)/get_map.c \
			$(SRC_DIR)/map_validation.c \
			$(SRC_DIR)/map_validation_utils.c \
			$(SRC_DIR)/animations.c \
			$(SRC_DIR)/put_images.c \
			$(SRC_DIR)/utils.c \
			$(SRC_DIR)/enemy.c \
			$(SRC_DIR)/enemy_utils.c \
			$(SRC_DIR)/draw_images.c \
			
OBJ_FILES = $(SRC_FILES:.c=.o)

# MLX
MLX_DIR = ./MLX42
MLX := $(MLX_DIR)/libmlx42.a
MLX_FLAGS   := -ldl -pthread -lm -lglfw
HEADERS	:= -I ./includes -I$(MLX_DIR)/include

# RULES #
all: libmlx $(NAME)

libmlx:
	@echo $(CYAN)
	@make -C $(MLX_DIR)
	@echo $(NC)

%.o : %.c
	@echo $(MAGENTA)Compiling [$<]...$(NC)
	@$(CC) $(HEADERS) -c -o $@ $<
	@printf $(UP)$(CUT)

# CC $(CFLAGS)  HEADERS

$(NAME): $(OBJ_FILES)
	@echo $(MAGENTA)Compiling [$(SRC_FILES)]...$(NC)
	@echo $(GREEN)Finished [$(SRC_FILES)]$(NC)
	@echo
	@echo $(MAGENTA)Compiling [$(NAME)]...$(NC)
	@$(CC) $(OBJ_FILES) $(HEADERS) $(MLX) $(MLX_FLAGS) -o $(NAME)
	@echo $(GREEN)Compliation of [$(NAME)] is success 🎉$(NC)

clean:
	@make -C $(MLX_DIR) fclean
	@echo $(RED)Cleaned [$(OBJ_FILES)]$(NC)

fclean: clean
	@echo $(RED)Cleaned [$(NAME)]$(NC)

re: clean all

.PHONY: all, clean, fclean, re, libmlx
