# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/12 02:37:51 by aaslan            #+#    #+#              #
#    Updated: 2023/10/26 19:22:08 by aaslan           ###   ########.fr        #
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
			src/mandatory/game/init_free_mlx_image.c \
			src/mandatory/game/init_free_player.c

OTHERS		:= src/mandatory/init_free_cub3d.c \
			src/mandatory/print_error.c \
			src/mandatory/main.c

OBJS		:= $(UTILITIES:%.c=%.o) $(CONFIG:%.c=%.o) $(GAME:%.c=%.o) $(OTHERS:%.c=%.o)

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
	@clear

fclean: clean
	@rm -rf $(NAME)
ifeq ($(shell uname), Linux)
	@make clean -C mlx_linux
endif
ifeq ($(shell uname), Darwin)
	@make clean -C mlx
endif
	@clear

re: fclean all

norm:
	@norminette *.h *.c

.PHONY: all clean fclean re
