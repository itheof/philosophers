# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/10 14:41:44 by tvallee           #+#    #+#              #
#    Updated: 2015/04/03 16:53:36 by tvallee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		= maingtk.c init.c ft_find_file.c draw.c timeout.c get_options.c \
		  tools.c temp.c term_display.c steps.c philo_routine.c ft_putstr_v.c\
		  ft_putendl_v.c \
		  sig_handlers/params.c sig_handlers/buttons.c \
		  sig_handlers/drawing_zone.c sig_handlers/params2.c
NAME	= philo
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -Wshadow -Wno-missing-noreturn\
		  -Wno-padded -Wno-unreachable-code -Wredundant-decls\
		  -Wmissing-declarations
SRC_DIR	= srcs
VPATH	= $(SRC_DIR)
INC		= -I./includes -I./libft/includes `pkg-config --cflags --libs gtk+-3.0`
LIB		= -L./libft -lft -pthread
OBJ_DIR	= objs
OBJ		= $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	@echo ""
	@echo "Building libft..."
	@make -C libft
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
