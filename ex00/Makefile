# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsengeze <bsengeze@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/25 03:42:26 by bsengeze          #+#    #+#              #
#    Updated: 2023/12/26 22:51:28 by bsengeze         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone
CC = g++
RM = rm -rf
FLAGS = -std=c++98 -Wall -Wextra -Werror
OBJ_DIR = obj/
SRC_DIR = src/
GREEN   = \033[32;1m
RESET	= \033[0m

SRC 	= megaphone.cpp
SRCS	= $(addprefix $(SRC_DIR), $(SRC))

OBJ		= $(SRC:.cpp=.o)
OBJS 	= $(addprefix $(OBJ_DIR), $(OBJ))

all: $(OBJ_DIR) $(SRCS) $(OBJS) $(NAME) 

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	$(CC) $(FLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(NAME): $(OBJS)
		$(CC) $(FLAGS) $(OBJS) -o $(NAME)
		@echo "$(GREEN) Compiled with $(CFLAGS)$(RESET)"

clean:
		$(RM) $(OBJ_DIR)
		@echo "$(GREEN) Cleaned $(RESET)"

fclean: clean
		$(RM) $(NAME)
		@echo "$(GREEN) Full cleaned $(RESET)"

re: fclean all

.PHONY: all clean fclean re