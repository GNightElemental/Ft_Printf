# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sjuery <sjuery@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/31 11:03:41 by sjuery            #+#    #+#              #
#    Updated: 2017/10/31 11:21:12 by sjuery           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 	ft_printf
LIBNAME		=	libft.a

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra

LIBLIST		=	libft/ft_swap \
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
				libft/ft_uni2utf8 \

MAINLIST	=	ft_printf \

LIBSRCS		=	$(addsuffix .c, $(LIBLIST))
LIBOBJS		=	$(addsuffix .o, $(LIBLIST))

MAINSRCS	=	$(addsuffix .c, $(MAINLIST))
MAINOBJS	=	$(addsuffix .o, $(MAINLIST))

all: $(NAME)

$(LIBOBJS): $(LIBSRCS)

$(MAINOBJS): $(MAINSRCS)

$(LIBNAME): $(LIBOBJS)
	ar rcs $(LIBNAME) $(LIBOBJS)

$(NAME): $(LIBNAME) $(MAINOBJS)
	$(CC) $(CFLAGS) $(MAINOBJS) $(LIBNAME) -o $(NAME)

clean:
	@rm -rf $(MAINOBJS) $(LIBOBJS) $(TESTOBJS)

fclean: clean
	@rm -rf $(NAME) $(LIBNAME) t

re: fclean all

.SILENT: $(LIBOBJS) $(MAINOBJS)
