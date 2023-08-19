# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/05 05:18:43 by aandom            #+#    #+#              #
#    Updated: 2023/08/19 18:32:37 by aandom           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

$(VERBOSE).SILENT:

CC = cc
CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g3
SRC_DIR = src

INCLUDE_DIR = includes
LIBFT_PATH = includes/libft
MLX_PATH = includes/mlx

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = ${SRC_FILES:.c=.o}

LIBFT = $(LIBFT_PATH)/libft.a
MLX = $(MLX_PATH)/libmlx.a
LINKER = -lmlx -framework OpenGL -framework AppKit

NAME = fractol

all: $(NAME)

$(NAME): $(OBJ_FILES) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_PATH) -lft -L$(MLX_PATH) $(LINKER)


$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

$(MLX):
	@$(MAKE) -C $(MLX_PATH)

clean:
	@$(MAKE) -C $(LIBFT_PATH) clean
# @$(MAKE) -C $(MLX_PATH) clean
	@rm -rf $(OBJ_FILES)


fclean: clean
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re