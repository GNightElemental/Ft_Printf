# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sjuery <sjuery@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/31 11:28:46 by sjuery            #+#    #+#              #
#    Updated: 2017/11/10 18:08:11 by sjuery           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 	libftprintf.a

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra

LIBFT		=	libft/ft_swap \
				libft/ft_memalloc \
				libft/ft_strcat \
				libft/ft_strchr \
				libft/ft_strcpy \
				libft/ft_strdup \
				libft/ft_strjoin \
				libft/ft_strlen \
				libft/ft_strncat \
				libft/ft_strncpy \
				libft/ft_strnew \
				libft/ft_strsub \
				libft/ft_swap \
				libft/ft_bzero \
				libft/ft_putendl_fd \
				libft/ft_putendl \
				libft/ft_putstr_fd \
				libft/ft_putchar \
				libft/ft_putstr \
				libft/ft_putnbr_fd \
				libft/ft_putchar_fd \
				libft/ft_putnbr \
				libft/ft_itoa \
				libft/ft_numcount \
				libft/ft_atoi_base \
				libft/ft_itoa_base \
				libft/wint_to_str \
				libft/wstr_to_str \
				libft/ft_putwchar \

PRINTF		=	ft_printf \

SRCS		=	$(addsuffix .c, $(LIBFT)) $(addsuffix .c, $(PRINTF))
OBJS		=	$(addsuffix .o, $(LIBFT)) $(addsuffix .o, $(PRINTF))

all: $(NAME)

$(OBJS): $(SRCS)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.SILENT: $(OBJS)
