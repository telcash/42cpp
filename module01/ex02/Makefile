# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: carlossalazar <carlossalazar@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/06 19:35:41 by carlossalaz       #+#    #+#              #
#    Updated: 2025/11/06 20:49:47 by carlossalaz      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = refs
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f
SRC_DIR = ./
OBJ_DIR = ./

SRC_FILES = main.cpp

SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS = $(addprefix $(OBJ_DIR), $(SRC_FILES:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Building $(NAME)..."
	@$(CC) $(FLAGS) -o $(NAME) $(OBJS)
	@echo "$(NAME) built successfully!"

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(OBJ_DIR)
	@echo "Compiling $<..."
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re