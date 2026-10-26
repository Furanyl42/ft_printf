# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nide-wil <nide-wil@student.42belgium.be>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/14 12:39:34 by nide-wil          #+#    #+#              #
#    Updated: 2026/10/26 12:42:18 by nide-wil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

LIBFT		= libft/libft.a

SRCS		= ft_printf.c \
			  print_percent.c \
			  print_char.c \
			  print_str.c \
			  print_nbr.c \
			  print_unsigned.c \
			  print_hex.c \
			  hex_utils.c \
			  print_ptr.c \
			  parse.c \
			  utils.c \
			  ptr_utils.c \
			  unsigned_utils.c \

OBJS		= $(SRCS:.c=.o)

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f
AR			= ar rcs

TEST_BIN	= TEST
TEST_SRC	= main_test.c

all: $(NAME)

$(LIBFT):
	@make -C libft

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJS)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

test: $(NAME) $(TEST_SRC)
	$(CC) $(TEST_SRC) $(NAME) -I. -o $(TEST_BIN)
	./$(TEST_BIN)
	$(MAKE) fclean

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(TEST_BIN)

re: fclean all

.PHONY: all clean fclean re
