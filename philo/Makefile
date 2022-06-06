# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: steh <steh@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/31 12:49:52 by steh              #+#    #+#              #
#    Updated: 2022/06/06 19:05:14 by steh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# implicit variables or nonchanging variables
CC				:= gcc
CFLAGS			:= -Wall -Werror -Wextra
SRC_DIR			:= src
OBJ_DIR			:= obj
SRC				:= $(wildcard $(SRC_DIR)/*.c)
OBJ				:= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
INC				:= -Iinc
.PHONY			: all clean fclean re

# git shell color and styling
# example 
# red                           : \033[0;31m
# bold red                      : \033[1;31m
# underline red                 : \033[4;31m
# background red                : \033[41m
# high intensity red            : \033[0;91m
# bold intensity red            : \033[1;91m
# high intensity red background : \033[1;101m
_RESET		= \033[0m
_BOLD		= \033[1m
_RED		= \033[0;31m
_GREEN		= \033[0;32m
_YEL		= \033[0;33m
_CYN		= \033[0;36m


# non-implicit variables or changing variables
# mostly include library or change program name
NAME			:= philo
all				: $(NAME)

$(NAME)			: $(OBJ)
					@$(CC) $(CFLAGS) $(OBJ) $(INC) -o $@
					@echo "$(_GREEN) Project Compiled $(_RESET)"

$(OBJ_DIR)/%.o	: $(SRC_DIR)/%.c
					@mkdir -p $(OBJ_DIR)
					@$(CC) $(INC) -c $< -o $@
					@echo "$(_GREEN) Compiling $(_YEL) $< $(_RESET)"

norm			:
					@echo "$(_YEL) norminatte start $(_RESET)"
					norminette $(SRC_DIR)/*.c

clean			:
					@$(RM) $(OBJS)
					@$(RM) -r $(OBJ_DIR)
					@echo "$(_RED) removed obj files and obj directory $(_RESET)"

fclean			: clean
					@$(RM) $(NAME)
					@echo "$(_RED) removed $(NAME) $(_RESET)"

re				: fclean all
