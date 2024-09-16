# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/19 17:23:22 by abadouab          #+#    #+#              #
#    Updated: 2024/09/16 12:13:34 by abadouab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	Cub3D

SRCS		=	$(wildcard *.c)

OBJS		=	$(SRCS:.c=.o)
HEADER		=	includes/Cub3D.h

MLX42		=	MLX42

CLIB		=	CLib
ARLIB		=	CLib/libar.a

CC			=	cc
FLAGS		=	-Wall -Wextra -Werror
SHORT		=	-L$(CLIB) -lar
RM			=	rm -fr

GREEN		=	"\033[1;32m"
YELOW		=	"\033[1;33m"
REDCL		=	"\033[1;31m"
RESET		=	"\033[0m"

all: $(MLX42) 

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
	@if [ -d $(MLX42)/MLX ]; then \
		rm -rf $(MLX42)/MLX; \
	fi



$(CLIB):
	@make -C $(CLIB) --no-print-directory

$(MLX42):
	@git submodule init
	@cmake -B MLX42/MLX -S MLX42
	@make -C MLX42/MLX --no-print-directory

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $^ $(SHORT) -o $(NAME)

$(OBJS): %.o: %.c $(HEADER) $(ARLIB)
	@$(CC) $(FLAGS) -c -I $(CLIB) -I -I $(HDMLX) -I includes $< -o $@
	@printf $(GREEN)"."$(RESET)

clean:
	@$(RM) $(OBJS)
	@$(RM) $(OBJS_BONUS)
	@make clean -C $(CLIB) --no-print-directory
	@echo $(YELOW)Cleaning up 🧹💫$(RESET)

fclean: removing clean
	@$(RM) $(NAME)
	@$(RM) $(NAME_BONUS)
	@make fclean -C $(CLIB) --no-print-directory
	@echo $(REDCL)Purging all files 🗑️$(RESET)

re: fclean all

run: all clean
		clear && ./minishell

.PHONY: $(CLIB) $(MLX42)
