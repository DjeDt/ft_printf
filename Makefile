#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 19:43:04 by ddinaut           #+#    #+#              #
#    Updated: 2017/11/10 18:48:48 by ddinaut          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# Output file #
NAME = libprintf.a

# Details #
CC		= gcc
FLAGS	= -Wall -Wextra -Werror
E_FLAGS =

# Path #
OBJ_PATH = obj
SRC_PATH = srcs
INC_PATH = includes/

# Sub_dirs #
CONV =	conv/
FUNC =	lib/

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
INC = -I $(INC_PATH)

# Sources #
SRCS = \
		core_printf.c \
		do_conv.c \
\
		$(CONV)do_d.c \
		$(CONV)do_c.c \
		$(CONV)do_s.c \
		$(CONV)do_o.c \
		$(CONV)do_u.c \
		$(CONV)do_x.c \
\
		$(CONV)do_char.c \
		$(CONV)do_int.c \
		$(CONV)do_unsign.c \
		$(CONV)do_ptr.c \
		$(CONV)do_long.c \
\
		$(FUNC)ft_putchar.c \
		$(FUNC)ft_putnbr.c \
		$(FUNC)ft_putstr.c \
		$(FUNC)ft_strlen.c \
		$(FUNC)ft_itoa_base.c \
		$(FUNC)ft_atoi.c \
		$(FUNC)ft_strsub.c


OBJ = $(SRC:$(SRC_PATH)/%.c=$(OBJ_PATH)/%.o)
SRC = $(addprefix $(SRC_PATH)/,$(SRCS))

# Rules #
.PHONY: all clean fclean re logo

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
