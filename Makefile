#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/25 17:23:52 by ddinaut           #+#    #+#              #
#    Updated: 2017/12/07 20:50:28 by ddinaut          ###   ########.fr        #
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
CONCAT	= $(CONV)concat/

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
		$(FUNC)ft_itoa_base.c \
		$(FUNC)ft_atoi.c \
		$(FUNC)ft_strsub.c \
		$(FUNC)ft_strfsub.c \
		$(FUNC)ft_strdup.c \
		$(FUNC)ft_strjoin.c \
		$(FUNC)ft_strjoin_fr.c \
		$(FUNC)ft_strjoin_fl.c \
		$(FUNC)ft_strcmp.c \
		$(FUNC)ft_strncmp.c \
\
		$(UTILS)oneof.c

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
