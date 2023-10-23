# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/12 02:37:51 by aaslan            #+#    #+#              #
#    Updated: 2023/10/24 01:07:53 by aaslan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= cub3D
B_NAME		:= cub3D_bonus
CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror -g

COMMON		:= src/common/free_double_pointer.c \
			src/common/ft_atoi.c \
			src/common/ft_is_digit.c \
			src/common/ft_split.c \
			src/common/ft_strchr.c \
			src/common/ft_strcmp.c \
			src/common/ft_strdup.c \
			src/common/ft_strlcpy.c \
			src/common/ft_strlen.c \
			src/common/ft_strncmp.c \
			src/common/ft_strncpy.c \
			src/common/ft_strtrim_start.c \
			src/common/ft_strtrim.c \
			src/common/ft_substr.c
CONFIG		:= src/mandatory/config/check_map_empty_line.c \
			src/mandatory/config/create_map_same_row_len.c \
			src/mandatory/config/get_next_line.c \
			src/mandatory/config/init_free_colors.c \
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

# GAME		:= src/mandatory/game/
OTHERS		:= src/mandatory/init_free_cub3d.c \
			src/mandatory/print_error.c \
			src/mandatory/main.c

OBJS		:= $(COMMON:%.c=%.o) $(CONFIG:%.c=%.o) $(OTHERS:%.c=%.o)

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
