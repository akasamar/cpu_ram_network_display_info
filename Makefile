# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mstorcha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/26 15:48:11 by mstorcha          #+#    #+#              #
#    Updated: 2018/10/14 19:36:01 by aminadzh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_gkrellm

CC = clang++

CFLAGS = -Wall -Wextra -Werror
#CFLAGS += -g

INCLUDES = -I./inc/

INCLUDES	+=	-I./frameworks/SDL2.framework/Headers
INCLUDES	+=  -I./frameworks/SDL2_ttf.framework/Headers/SDL_ttf.h
INCLUDES	+=  -F./frameworks 

FRAMEWORKS	=	-lncurses -framework SDL2 -framework SDL2_ttf -rpath ./frameworks 

SRC_DIR = ./src
OBJ_DIR = obj

SOURCES = main.cpp \
		  BaseInfoModule.cpp \
		  CPUModule.cpp \
		  Ncurse.cpp \
		  NetworkModule.cpp \
		  Parser.cpp \
		  RAMModule.cpp \
		  WindowMode.cpp

OBJ = $(addprefix $(OBJ_DIR)/, $(SOURCES:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIB_FLAGS) -o $(NAME) $(INCLUDES) $(FRAMEWORKS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDES)

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

clean:
	@/bin/rm -rf $(OBJ)
	@/bin/rm -rf $(OBJ_DIR)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
