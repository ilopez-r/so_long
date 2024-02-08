# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilopez-r <ilopez-r@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/18 11:18:33 by ilopez-r          #+#    #+#              #
#    Updated: 2024/01/26 13:22:07 by ilopez-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus

FLAGS = -Wall -Werror -Wextra

FILES = src/check_format.c\
		src/check_map.c\
		src/read_map.c\
		src/so_long.c\
		src/texture_to_image.c\
		src/image_to_window.c\
		src/player_move.c\

BONUS = srcb/check_format_bonus.c\
		srcb/check_map_bonus.c\
		srcb/read_map_bonus.c\
		srcb/so_long_bonus.c\
		srcb/texture_to_image_bonus.c\
		srcb/image_to_window_bonus.c\
		srcb/player_move_bonus.c\
		srcb/enemy_move_bonus.c\

OBJS = $(FILES:.c=.o)

OBJS_BONUS = $(BONUS:.c=.o)

LIBFT_PATH = ./libftc

MLX_PATH = ./MLX42

LIBFT = $(LIBFT_PATH)/libft.a

MLX = $(MLX_PATH)/libmlx42.a

LIB_SYS = -Iinclude -lglfw -L "/Users/ilopez-r/.brew/opt/glfw/lib/"

all : $(NAME) $(LIBFT) $(MLX)

$(LIBFT) :
	@make -s -C $(LIBFT_PATH)

$(MLX) :
	@make -s -C $(MLX_PATH)

$(NAME) : $(OBJS) $(LIBFT) $(MLX)
	@gcc $(FLAGS) $(FILES) $(LIBFT) $(MLX) $(LIB_SYS)  -o $(NAME)

$(NAME_BONUS) : $(OBJS_BONUS) $(LIBFT) $(MLX)
	@gcc $(FLAGS) $(BONUS) $(LIBFT) $(MLX) $(LIB_SYS)  -o $(NAME_BONUS)

$(OBJS) : $(FILES)
	@gcc $(FLAGS) -c $< -o $@

$(OBJS_BONUS) : $(BONUS)
	@gcc $(FLAGS) -c $< -o $@

clean:
	@rm -fr $(OBJS) $(OBJS_BONUS)
	@make clean -s -C $(LIBFT_PATH)
	@make clean -s -C $(MLX_PATH)

fclean: clean
	@rm -fr $(NAME) $(NAME_BONUS)
	@make fclean -s -C $(LIBFT_PATH)
	@make fclean -s -C $(MLX_PATH)

re: fclean all

bonus: $(NAME_BONUS)

.PHONY : all clean fclean re bonus $(LIBFT)