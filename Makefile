#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/25 17:23:52 by ddinaut           #+#    #+#              #
#    Updated: 2018/01/20 18:30:30 by ddinaut          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# Output file #
NAME = libftprintf.a

# Details #
CC		= gcc
FLAGS	= -Wall -Wextra -Werror
DEBUG	= n

# Path #
OBJ_PATH = obj
SRC_PATH = srcs
INC_PATH = includes/

# Sub_dirs #
CONV	= conv/
FUNC	= lib/
UTILS	= utils/
CONCAT	= concat/

# More sub_dir #

# Colors #
COL_BLACK	= \033[1;30m
COL_RED		= \033[1;31m
COL_GREEN	= \033[1;32m
COL_YELLOW	= \033[1;33m
COL_BLUE	= \033[1;34m
COL_PURPLE	= \033[1;35m
COL_WHITE	= \033[1;37m
END_COL		= \033[0;m

AR	= ar rc $(NAME)
RAN = ranlib $(NAME)
INC = -I$(INC_PATH)

# Sources #
SRCS = \
		ft_printf.c \
		do_conv.c \
		do_parse.c \
\
		$(CONV)do_char.c \
		$(CONV)do_int.c \
		$(CONV)do_unsign.c \
		$(CONV)do_ptr.c \
		$(CONV)do_long.c \
		$(CONV)add_to_final.c \
\
		$(CONCAT)concat_char.c \
		$(CONCAT)concat_int.c \
		$(CONCAT)concat_unsign.c \
		$(CONCAT)concat_ptr.c \
\
		$(FUNC)ft_strlen.c \
		$(FUNC)ft_strdel.c \
		$(FUNC)nbr_len.c \
		$(FUNC)ft_strdup.c \
		$(FUNC)ft_strjoin.c \
		$(FUNC)ft_strjoin_fr.c \
		$(FUNC)ft_strjoin_fl.c \
		$(FUNC)ft_memcpy.c \
\
		$(UTILS)oneof.c \
		$(UTILS)move_sign.c \
		$(UTILS)create_padding.c

OBJ = $(SRC:$(SRC_PATH)/%.c=$(OBJ_PATH)/%.o)
SRC = $(addprefix $(SRC_PATH)/,$(SRCS))

# Percent progress #
COUNT		= 1
NB_FILES	= $(words $(SRCS))
PERCENT		= $(shell echo $$(( ($(COUNT) * 100) / $(NB_FILES))))

# Debug option #
ifeq ($(DEBUG), yes)
	FLAGS = -Wall -Wextra -Werror -fsanitize=address -g
else
	FLAGS = -Wall -Wextra -Werror
endif

# Rules #
.PHONY: all clean fclean re

all: $(NAME)
	@printf "\r\033[K$(COL_RED)[100%%]\tPrintf compiled [√].$(END_COL)\n"

$(NAME): $(OBJ)
	@$(AR) $(OBJ)
	@$(RAN)

$(OBJ): $(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
	@mkdir -p $(dir $@)
	@$(CC) -o $@ $(FLAGS) $(E_FLAGS) $(INC) -c $<
	@printf "\r\033[K$(COL_RED)[%-5.2f%%]  \e[1;38;5;148m[$@] -> [$<]$(END_COL)" $(PERCENT)
	$(eval COUNT=$(shell echo $$(($(COUNT)+1))))

clean:
	@/bin/rm -rf $(OBJ_PATH)

fclean: clean
	@/bin/rm -f $(NAME)

exe: re
	gcc main.c $(NAME)
	./a.out

re: fclean all
