# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/19 17:35:19 by abadouab          #+#    #+#              #
#    Updated: 2024/06/12 01:36:06 by abadouab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libar.a
LIBH		=	CLib.h
ARRC		=	ar -rc

SRCS		=	$(shell find . -name "*.c")

OBJS_DIR	=	.Objects/
OBJS		=	$(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

FLGS		=	cc -Wall -Wextra -Werror
RM  		=	rm -fr

GREEN		=	"\033[1;32m"
YELOW 		=	"\033[1;33m"
REDCL 		=	"\033[1;31m"
RESET 		=	"\033[0m"

all: $(NAME)

$(NAME): $(OBJS)
	@$(ARRC) $(NAME) $(OBJS)

$(OBJS_DIR)%.o: %.c $(LIBH)
	@mkdir -p $(dir $@)
	@$(FLGS) -c $< -o $@
	@printf $(GREEN)"."$(RESET)

clean:
	@$(RM) $(OBJS_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
