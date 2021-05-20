# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msessa <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/23 11:32:44 by msessa            #+#    #+#              #
#    Updated: 2021/05/20 13:22:22 by msessa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	speed_tester

LIBFT	=	../push_swap/libft

HEADERS	=	headers

DIR_S	=	srcs

DIR_O	=	obj

# Using wildcards: $(shell find $(DIR_S) -name *.c)
SRCS	:=	$(shell find $(DIR_S) -name *.c)

OBJS	:= $(SRCS:%.c=$(DIR_O)/%.o)

SUB_DIR_O := $(shell find $(DIR_S) -type d)
SUB_DIR_O := $(SUB_DIR_O:%=$(DIR_O)/%)

# Using wildcards: $(shell find $(HEADERS) -name *.h)
DEPS	=	$(shell find $(HEADERS) -name *.h)

CC		=	gcc

CFLAGS	=	-Wall -Wextra

INCLUDES	= -I $(HEADERS) -I ../push_swap/headers -I ../push_swap/libft

LIBS	=	-L../push_swap/libft -lft

RM		=	rm -f

$(DIR_O)/%.o: %.c
			@mkdir -p $(DIR_O)
			@mkdir -p $(SUB_DIR_O)
			$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(NAME):	$(DEPS) $(OBJS)
			@make -C ../push_swap
			$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(LIBS)

all:		$(NAME)

clean:
			$(RM) $(OBJS)
			@make miniclean -C ../push_swap

fclean:		clean
			$(RM) $(NAME)
			@make fclean -C ../push_swap

re:			fclean all

.PHONY:		all clean fclean re
