# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sjuery <sjuery@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/31 11:28:46 by sjuery            #+#    #+#              #
#    Updated: 2017/12/05 03:48:47 by sjuery           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 	libftprintf.a

LIBFT		=	srcs/libft/ft_atoi \
				srcs/libft/ft_bzero \
				srcs/libft/ft_intlen \
				srcs/libft/ft_isalnum \
				srcs/libft/ft_isalpha \
				srcs/libft/ft_isascii \
				srcs/libft/ft_isdigit \
				srcs/libft/ft_islower \
				srcs/libft/ft_isprint \
				srcs/libft/ft_isupper \
				srcs/libft/ft_itoa \
				srcs/libft/ft_lstadd \
				srcs/libft/ft_lstdel \
				srcs/libft/ft_lstdelone \
				srcs/libft/ft_lstiter \
				srcs/libft/ft_lstmap \
				srcs/libft/ft_lstnew \
				srcs/libft/ft_memalloc \
				srcs/libft/ft_memccpy \
				srcs/libft/ft_memchr \
				srcs/libft/ft_memcmp \
				srcs/libft/ft_memcpy \
				srcs/libft/ft_memdel \
				srcs/libft/ft_memmove \
				srcs/libft/ft_memset \
				srcs/libft/ft_numcount \
				srcs/libft/ft_putchar_fd \
				srcs/libft/ft_putchar \
				srcs/libft/ft_putendl_fd \
				srcs/libft/ft_putendl \
				srcs/libft/ft_putnbr_fd \
				srcs/libft/ft_putnbr \
				srcs/libft/ft_putunbr \
				srcs/libft/ft_putnstr \
				srcs/libft/ft_putstr_fd \
				srcs/libft/ft_putstr \
				srcs/libft/ft_strcat \
				srcs/libft/ft_strchr \
				srcs/libft/ft_strclr \
				srcs/libft/ft_strcmp \
				srcs/libft/ft_strcpy \
				srcs/libft/ft_strdel \
				srcs/libft/ft_strdup \
				srcs/libft/ft_strequ \
				srcs/libft/ft_striter \
				srcs/libft/ft_striteri \
				srcs/libft/ft_strjoin \
				srcs/libft/ft_strlcat \
				srcs/libft/ft_strlen \
				srcs/libft/ft_widelen \
				srcs/libft/ft_strmap \
				srcs/libft/ft_strmapi \
				srcs/libft/ft_strncat \
				srcs/libft/ft_strncmp \
				srcs/libft/ft_strncpy \
				srcs/libft/ft_strnequ \
				srcs/libft/ft_strnew \
				srcs/libft/ft_strnstr \
				srcs/libft/ft_strrchr \
				srcs/libft/ft_strsplit \
				srcs/libft/ft_strstr \
				srcs/libft/ft_strsub \
				srcs/libft/ft_strtrim \
				srcs/libft/ft_swap \
				srcs/libft/ft_tolower \
				srcs/libft/ft_toupper \
				srcs/libft/ft_wordcount \

PRINTF		=	ft_printf \
				srcs/parsers/parse_input \
				srcs/parsers/parse_flags \
				srcs/parsers/parse_chars \
				srcs/parsers/parse_ints \
				srcs/printers/print_chars \
				srcs/printers/print_ints \
				srcs/printers/print_sints \
				srcs/printers/print_per \
				srcs/converters/conv_hexa \
				srcs/converters/conv_octa \
				srcs/converters/conv_uni \
				srcs/converters/itoa_base \
				srcs/converters/conv_simu \

SRCS		=	$(addsuffix .c, $(LIBFT)) $(addsuffix .c, $(PRINTF))
OBJS		=	$(addsuffix .o, $(LIBFT)) $(addsuffix .o, $(PRINTF))

all: $(NAME)

$(OBJS): $(SRCS)

$(NAME): $(OBJS)
	printf '\033[31m[...] %s\n\033[0m' "Compiling Libft Printf"
	@ar rcs $(NAME) $(OBJS)
	printf '\033[32m[ ✔ ] %s\n\033[0m' "Compiled Libft Printf"

clean:
	printf '\033[31m[...] %s\n\033[0m' "Cleaning Libft Printf"
	@rm -rf $(OBJS)
	printf '\033[32m[ ✔ ] %s\n\033[0m' "Cleaned Libft Printf"

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.SILENT: $(OBJS) $(NAME) clean fclean re
