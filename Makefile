#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/25 17:23:52 by ddinaut           #+#    #+#              #
#    Updated: 2017/11/25 17:26:14 by ddinaut          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# Output file #
NAME = libftprintf.a

# Details #
CC		= gcc
FLAGS	= -Wall -Wextra -Werror
E_FLAGS = #-fsanitize=address

# Path #
OBJ_PATH = obj
SRC_PATH = srcs
INC_PATH = includes/

# Sub_dirs #
CONV	= conv/
FUNC	= lib/
UTILS	= utils/

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
		core_printf.c \
		do_conv.c \
\
		$(CONV)do_char.c \
		$(CONV)do_int.c \
		$(CONV)do_unsign.c \
		$(CONV)do_ptr.c \
		$(CONV)print_ptr.c \
		$(CONV)do_long.c \
		$(CONV)get_width.c \
\
		$(FUNC)ft_putchar.c \
		$(FUNC)ft_ascii_to_utf8.c \
		$(FUNC)ft_putnbr.c \
		$(FUNC)ft_putstr.c \
		$(FUNC)ft_putwstr.c \
		$(FUNC)ft_strlen.c \
		$(FUNC)nbr_len.c \
		$(FUNC)ft_itoa_base.c \
		$(FUNC)ft_atoi.c \
		$(FUNC)ft_strsub.c \
		$(FUNC)ft_strdup.c \
		$(FUNC)ft_strjoin.c \
		$(FUNC)ft_strjoin_fr.c \
\
		$(UTILS)print_exeption.c

OBJ = $(SRC:$(SRC_PATH)/%.c=$(OBJ_PATH)/%.o)
SRC = $(addprefix $(SRC_PATH)/,$(SRCS))

# Rules #
.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(OBJ)
	@$(RAN)

$(OBJ): $(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
	@mkdir -p $(dir $@)
	@$(CC) -o $@ $(FLAGS) $(E_FLAGS) $(INC) -c $<
	@printf "\e[1;38;5;148m%s -> %s                                   \r$(END_COL)" $@ $<

clean:
	@/bin/rm -rf $(OBJ_PATH)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
