# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/12 02:37:51 by aaslan            #+#    #+#              #
#    Updated: 2023/10/17 16:50:47 by aaslan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= cub3D
CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror -g
SRC			:= $(wildcard src/*.c)
OTHERS_SRC	:= $(wildcard src/*/*.c)
OBJS		:= $(SRC:%.c=%.o)
OTHERS_OBJS	:= $(OTHERS_SRC:%.c=%.o)

ifeq ($(shell uname), Linux)
MLX			:= mlx_linux/libmlx.a
MLX_FLAGS	:= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
endif
ifeq ($(shell uname), Darwin)
MLX			:= mlx_macos/libmlx.a
MLX_FLAGS	:= -Lmlx_macos -lmlx_macos -framework OpenGL -framework AppKit
endif

all: $(NAME)

$(NAME): $(MLX) $(OBJS) $(OTHERS_OBJS)
	@$(CC) $(OBJS) $(OTHERS_OBJS) $(CFLAGS) $(MLX_FLAGS) $(MLX) -o $(NAME)

$(MLX):
ifeq ($(shell uname), Linux)
	@make -C mlx_linux
endif
ifeq ($(shell uname), Darwin)
	@make -C mlx_macos
endif
	@clear

clean:
	@rm -rf $(OBJS)
	@rm -rf $(OTHERS_OBJS)
	@clear

fclean: clean
	@rm -rf $(NAME)
ifeq ($(shell uname), Linux)
	@make clean -C mlx_linux
endif
ifeq ($(shell uname), Darwin)
	@make clean -C mlx_macos
endif
	@clear

re: fclean all

norm:
	@norminette *.h *.c

.PHONY: all clean fclean re
