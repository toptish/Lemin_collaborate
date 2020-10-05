# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdorcas <gdorcas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/09 11:08:28 by ophuong           #+#    #+#              #
#    Updated: 2020/10/03 09:46:27 by gdorcas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET	:= lem-in
CFLAGS 	:= -Wall -Werror -Wextra
CC 		:= gcc

LIBFT	:= ./libft/libft.a
INC		:= ./includes/
LFT_DIR := ./libft/
OBJ_DIR	:= ./obj/
SRC_DIR	:= ./srcs/

SRCS 	:= main.c read.c str_isroom.c \
           str_isant.c str_islink.c str_iscommand.c \
           init.c read_ants.c read_rooms.c \
           read_links.c ways_get.c way_search.c \
           ways_man.c move.c errors.c \
           str_isempty.c free.c opts_usage.c

HEADER	:= includes/*.h

vpath %.c srcs/
vpath %.h includes/

OBJ	:= $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

RED 	:= \033[31;1m
GREEN 	:= \033[32;1m
WHITE	:= \033[39;1m
EOC		:= \033[00m

all: obj $(TARGET)

obj:
	@mkdir -p $(OBJ_DIR)

$(TARGET): $(LIBFT) $(OBJ)
	@$(CC) $^ -o $@ $(LIBFT)
	@printf "\n$(GREEN)compiled: $(WHITE)$(TARGET)$(EOC)\n"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER) Makefile
	@printf "$(GREEN).....$(EOC)"
	@$(CC) $(CFLAGS) -I $(INC) -I $(LFT_DIR)/includes -c $< -o $@

$(LIBFT): FORCE
	@make -C $(LFT_DIR)

clean:
	@rm -rf *.o obj includes/lemin.h.gch
	@cd libft/ && make clean
	@echo "$(RED)deleted: $(WHITE)obj files$(EOC)"

fclean: clean
	@rm -f $(TARGET)
	@cd libft/ && make fclean
	@echo "$(RED)deleted: $(WHITE)$(TARGET)$(EOC)"

re: fclean all

FORCE:

.PHONY: clean fclean re all
