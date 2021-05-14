# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msessa <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/23 11:32:44 by msessa            #+#    #+#              #
#    Updated: 2021/05/14 17:06:00 by msessa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

LIBFT	=	libft

HEADERS	=	headers

DIR_S	=	srcs

DIR_O	=	obj

# Using wildcards: $(shell find $(DIR_S) -name *.c)
O_SRCS	:=	$(shell find $(DIR_S) -name *.c)

SRCS	:=	$(O_SRCS)

B_SRCS	:=	$(O_SRCS)

OBJS	:= $(SRCS:%.c=$(DIR_O)/%.o)

BOBJS	:= $(B_SRCS:%.c=$(DIR_O)/%.o)

SUB_DIR_O := $(shell find $(DIR_S) -type d)
SUB_DIR_O := $(SUB_DIR_O:%=$(DIR_O)/%)

# Using wildcards: $(shell find $(HEADERS) -name *.h)
DEPS	=	$(shell find $(HEADERS) -name *.h)

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror -fsanitize=address

LIBS	=	-L./libft -lft

RM		=	rm -f

$(DIR_O)/%.o: %.c
			@mkdir -p $(DIR_O)
			@mkdir -p $(SUB_DIR_O)
			$(CC) $(CFLAGS) -o $@ -c $<

$(NAME):	$(DEPS) $(OBJS)
			@make bonus -C $(LIBFT)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)

all:		$(NAME)

miniclean:
			$(RM) $(OBJS)
			$(RM) $(BOBJS)

clean:		miniclean
			@make clean -C $(LIBFT)

fclean:		clean
			$(RM) $(NAME)
			@make fclean -C $(LIBFT)

re:			fclean all

bonus:		$(DEPS) $(BOBJS)
			@make bonus -C $(LIBFT)
			$(CC) $(CFLAGS) -o $(NAME) $(BOBJS) $(LIBS)

.PHONY:		all clean fclean miniclean re bonus
