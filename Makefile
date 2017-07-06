# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/07 16:55:33 by mbarbari          #+#    #+#              #
#    Updated: 2017/07/06 09:52:41 by barbare          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC ?= clang
CX ?= clang++

NAME = cryptStore_data

CFLAGS += -g -Wall -Wextra -Werror

SOURCES_FILES = ./src
HEADERS_FILES = ./inc
OBJECTS_FILES = ./obj

INC = -I./inc

SRCS = 	$(SOURCES_FILES)/main.c

OBJS = $(patsubst $(SOURCES_FILES)/%.c,$(OBJECTS_FILES)/%.o,$(SRCS))

SRC_INCLUDE = $(HEADERS_FILES)/cryptStore_data.h

RM ?= rm -f
MKDIR ?= mkdir
CD ?= cd

all: $(NAME)

print-% : ; $(info $* is $(flavor $*) variable set to [$($*)]) @true

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(INC) $(LIBS)

$(OBJECTS_FILES)/%.o: $(SOURCES_FILES)/%.c $(SRC_INCLUDE)
	$(MKDIR) -p $(dir $@)
	$(CC) -c $(CFLAGS) $(INC) $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) cli
	$(RM) $(OBJS)

re: fclean all

.PHONY: clean fclean re all
