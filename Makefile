# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/22 17:31:22 by jinsyang          #+#    #+#              #
#    Updated: 2022/11/28 18:58:07 by jinsyang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC_M = ft_atoi.c \
	  ft_bzero.c \
	  ft_calloc.c \
	  ft_isalnum.c \
	  ft_isalpha.c \
	  ft_isascii.c \
	  ft_isdigit.c \
	  ft_isprint.c \
	  ft_itoa.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_memcpy.c \
	  ft_memmove.c \
	  ft_memset.c \
	  ft_putchar_fd.c \
	  ft_putendl_fd.c \
	  ft_putnbr_fd.c \
	  ft_putstr_fd.c \
	  ft_split.c \
	  ft_strchr.c \
	  ft_strdup.c \
	  ft_striteri.c \
	  ft_strjoin.c \
	  ft_strlcat.c \
	  ft_strlcpy.c \
	  ft_strlen.c \
	  ft_strmapi.c \
	  ft_strncmp.c \
	  ft_strnstr.c \
	  ft_strrchr.c \
	  ft_strtrim.c \
	  ft_substr.c \
	  ft_tolower.c \
	  ft_toupper.c

SRC_B = ft_lstnew_bonus.c

OBJ_M = $(SRC_M:.c=.o)

OBJ_B = $(SRC_B:.c=.o)

INCLUDE = ./libft.h


ifdef WITH_BONUS
	OBJ = $(OBJ_M) $(OBJ_B)
else
	OBJ = $(OBJ_M)
endif

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(INCLUDE)

$(NAME) : $(OBJ)
	ar rsc $@ $^

all : $(NAME)
	sleep 1

bonus :
	make WITH_BONUS=1

clean:
	rm -rf $(OBJ_M) $(OBJ_B)

fclean: clean
	rm -rf $(NAME)

re : fclean all

.PHONY : clean fclean re all bonus
