# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/16 12:39:22 by abadouab          #+#    #+#              #
#    Updated: 2024/09/21 10:39:08 by abadouab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	Cub3D

SRCS		=	Cub3D.c \
				Parser/Parser.c \
				Parser/ParseMap.c \
				Parser/ParseColor.c \
				Parser/ParseTexture.c \
				Error/ErrorHandler.c

OBJS_DIR	=	.Objects/
OBJS		=	$(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

MLX			=	MLX42/MLX
MLX42		=	MLX42
HEADER		=	Includes/Cub3D.h

CLIB		=	CLib
ARLIB		=	CLib/libar.a

CC			=	cc
FLAGS		=	-Wall -Wextra -Werror -g -fsanitize=address
RM			=	rm -fr

SHORT		=	-L$(CLIB) -lar -L $(MLX) -l mlx42 -lglfw
INCLUDES	=	-I $(CLIB) -I Includes -I $(MLX42)/include/MLX42/

GREEN		=	"\033[1;32m"
YELOW		=	"\033[1;33m"
REDCL		=	"\033[1;31m"
RESET		=	"\033[0m"

all: $(MLX42) start $(CLIB) $(NAME) finish

start:
	@printf "\n"
	@echo $(GREEN)"Starting build..."
	@sleep 1
	@printf "Loading [ "

finish:
	@echo $(GREEN) ] 100%$(RESET)
	@echo $(GREEN)Project built.$(RESET)
	@printf "\n"

removing:
	@if [ -d $(MLX) ]; then rm -rf $(MLX); fi

$(CLIB):
	@make -C $(CLIB) --no-print-directory

$(MLX42):
	@git submodule update --init
	@cmake -B $(MLX) -S $(MLX42)
	@make -C $(MLX) --no-print-directory

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $^ $(SHORT) -o $(NAME)

$(OBJS): $(OBJS_DIR)%.o: %.c $(HEADER) $(ARLIB)
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@
	@printf $(GREEN)"."$(RESET)

clean:
	@$(RM) $(OBJS_DIR)
	@make clean -C $(CLIB) --no-print-directory
	@echo $(YELOW)Cleaning up 🧹💫$(RESET)

fclean: removing clean
	@$(RM) $(NAME)
	@make fclean -C $(CLIB) --no-print-directory
	@echo $(REDCL)Purging all files 🗑️$(RESET)

re: fclean all

.PHONY: $(CLIB) $(MLX42)
