# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/10 14:41:44 by tvallee           #+#    #+#              #
#    Updated: 2015/03/09 19:19:07 by tvallee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		= main.c
NAME	= philo
CC		= gcc
CFLAGS	= -Wall -Wextra -g -Wshadow -Wno-missing-noreturn\
		  -Wno-padded -Wno-unreachable-code -Wredundant-decls\
		  -Wmissing-declarations
SRC_DIR	= srcs
VPATH	= $(SRC_DIR)
INC		= -I./includes -I./libft/includes `pkg-config --cflags --libs gtk+-3.0`
LIB		= -L./libft -lft
OBJ_DIR	= objs
OBJ		= $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	@echo ""
	@echo "Building libft..."
	@echo "Done !"
	@echo ""
	@echo "Linkin'"
	@$(CC) $(CFLAGS) -o $(NAME) $(INC) $(OBJ) $(LIB)
	@echo "Successful !"

$(OBJ_DIR)/%.o: %.c
	@echo "Compiling $<."
	@$(CC) -c $< $(INC) -o $@ $(CFLAGS)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/parsing $(OBJ_DIR)/interpreter $(OBJ_DIR)/libftmod
	@mkdir -p $(OBJ_DIR)/builtins

clean:
	@echo "Deleting obj files."
	@make -C libft/ clean
	@rm -f $(OBJ)

fclean: clean
	@echo "Deleting executable"
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re $(OBJ_DIR)
