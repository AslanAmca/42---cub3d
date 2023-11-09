# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/12 02:37:51 by aaslan            #+#    #+#              #
#    Updated: 2023/11/10 00:51:51 by aaslan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= cub3D
B_NAME		:= cub3D_bonus
CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror -g

UTILITIES	:= src/utilities/free_double_pointer.c \
			src/utilities/ft_atoi.c \
			src/utilities/ft_is_digit.c \
			src/utilities/ft_split.c \
			src/utilities/ft_strchr.c \
			src/utilities/ft_strcmp.c \
			src/utilities/ft_strdup.c \
			src/utilities/ft_strlcpy.c \
			src/utilities/ft_strlen.c \
			src/utilities/ft_strncmp.c \
			src/utilities/ft_strncpy.c \
			src/utilities/ft_strtrim_start.c \
			src/utilities/ft_strtrim.c \
			src/utilities/ft_substr.c

CONFIG		:= src/mandatory/config/check_map_empty_line.c \
			src/mandatory/config/create_map_same_row_len.c \
			src/mandatory/config/get_next_line.c \
			src/mandatory/config/init_free_colors.c \
			src/mandatory/config/init_free_config.c \
			src/mandatory/config/init_free_map.c \
			src/mandatory/config/init_free_xpm_files.c \
			src/mandatory/config/is_empty_line.c \
			src/mandatory/config/set_config_line_count.c \
			src/mandatory/config/set_config_text.c \
			src/mandatory/config/set_elements_count.c \
			src/mandatory/config/set_map_text.c \
			src/mandatory/config/validate_argument.c \
			src/mandatory/config/validate_ceiling_color.c \
			src/mandatory/config/validate_config_is_non_empty.c \
			src/mandatory/config/validate_elements.c \
			src/mandatory/config/validate_floor_color.c \
			src/mandatory/config/validate_map_characters.c \
			src/mandatory/config/validate_map_spaces.c \
			src/mandatory/config/validate_map_walls.c \
			src/mandatory/config/validate_map.c \
			src/mandatory/config/validate_xpm_files.c

GAME		:= src/mandatory/game/init_free_game.c \
			src/mandatory/game/init_free_mlx.c \
			src/mandatory/game/init_free_player.c \
			src/mandatory/game/init_free_screen.c \
			src/mandatory/game/init_free_xpm_images.c \
			src/mandatory/game/init_rgb_colors.c \
			src/mandatory/game/mlx_event_handlers.c \
			src/mandatory/game/mlx_loop_handler.c \
			src/mandatory/game/player_move.c \
			src/mandatory/game/player_turn.c \
			src/mandatory/game/mlx_helpers.c \
			src/mandatory/game/ray_draw_until_hit_wall.c \
			src/mandatory/game/ray_fill_screen.c \
			src/mandatory/game/ray_properties.c \
			src/mandatory/game/ray_texture_properties.c \
			src/mandatory/game/ray_wall_properties.c \
			src/mandatory/game/raycasting.c

OTHERS		:= src/mandatory/init_free_cub3d.c \
			src/mandatory/print_error.c \
			src/mandatory/main.c

B_CONFIG	:= src/bonus/config/b_check_map_empty_line.c \
			src/bonus/config/b_create_map_same_row_len.c \
			src/bonus/config/b_get_next_line.c \
			src/bonus/config/b_helpers.c \
			src/bonus/config/b_init_free_colors.c \
			src/bonus/config/b_init_free_config.c \
			src/bonus/config/b_init_free_map.c \
			src/bonus/config/b_init_free_xpm_files.c \
			src/bonus/config/b_is_empty_line.c \
			src/bonus/config/b_set_config_line_count.c \
			src/bonus/config/b_set_config_text.c \
			src/bonus/config/b_set_elements_count.c \
			src/bonus/config/b_set_map_text.c \
			src/bonus/config/b_validate_argument.c \
			src/bonus/config/b_validate_ceiling_color.c \
			src/bonus/config/b_validate_config_is_non_empty.c \
			src/bonus/config/b_validate_elements.c \
			src/bonus/config/b_validate_floor_color.c \
			src/bonus/config/b_validate_map_characters.c \
			src/bonus/config/b_validate_map_spaces.c \
			src/bonus/config/b_validate_map_walls.c \
			src/bonus/config/b_validate_map.c \
			src/bonus/config/b_validate_xpm_files.c

B_GAME		:= src/bonus/game/b_init_free_door_images.c \
			src/bonus/game/b_init_free_game.c \
			src/bonus/game/b_init_free_mlx.c \
			src/bonus/game/b_init_free_player.c \
			src/bonus/game/b_init_free_screen.c \
			src/bonus/game/b_init_free_xpm_images.c \
			src/bonus/game/b_init_rgb_colors.c \
			src/bonus/game/b_mlx_event_handlers.c \
			src/bonus/game/b_mlx_helpers.c \
			src/bonus/game/b_mlx_loop_handler.c \
			src/bonus/game/b_open_close_door.c \
			src/bonus/game/b_player_move.c \
			src/bonus/game/b_player_turn.c \
			src/bonus/game/b_ray_draw_until_hit_wall.c \
			src/bonus/game/b_ray_fill_screen.c \
			src/bonus/game/b_ray_properties.c \
			src/bonus/game/b_ray_texture_properties.c \
			src/bonus/game/b_ray_wall_properties.c \
			src/bonus/game/b_raycasting.c

B_OTHERS	:= src/bonus/b_init_free_cub3d.c \
			src/bonus/b_print_error.c \
			src/bonus/b_main.c

OBJS		:= $(UTILITIES:%.c=%.o) $(CONFIG:%.c=%.o) $(GAME:%.c=%.o) $(OTHERS:%.c=%.o)
B_OBJS		:= $(UTILITIES:%.c=%.o) $(B_CONFIG:%.c=%.o) $(B_GAME:%.c=%.o) $(B_OTHERS:%.c=%.o)

ifeq ($(shell uname), Linux)
MLX			:= mlx_linux/libmlx.a
MLX_FLAGS	:= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
endif
ifeq ($(shell uname), Darwin)
MLX			:= mlx/libmlx.a
MLX_FLAGS	:= -Lmlx -lmlx -framework OpenGL -framework AppKit
endif


all: $(NAME)

$(NAME): $(MLX) $(OBJS)
	@$(CC) $(OBJS) $(CFLAGS) $(MLX_FLAGS) $(MLX) -o $(NAME)

bonus: $(MLX) $(B_OBJS)
	@$(CC) $(B_OBJS) $(CFLAGS) $(MLX_FLAGS) $(MLX) -o $(B_NAME)

$(MLX):
ifeq ($(shell uname), Linux)
	@make -C mlx_linux
endif
ifeq ($(shell uname), Darwin)
	@make -C mlx
endif
	@clear

clean:
	@rm -rf $(OBJS)
	@rm -rf $(B_OBJS)
	@clear

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(B_NAME)
ifeq ($(shell uname), Linux)
	@make clean -C mlx_linux
endif
ifeq ($(shell uname), Darwin)
	@make clean -C mlx
endif
	@clear

re: fclean all

norm:
	@norminette src/

norm_mandatory:
	@norminette src/mandatory

norm_bonus:
	@norminette src/bonus

.PHONY: all clean fclean re
