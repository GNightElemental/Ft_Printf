NAME		= 	libft.a

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra

LIBFT		=	ft_swap \
				ft_memalloc \
				ft_strcat \
				ft_strchr \
				ft_strcpy \
				ft_strdup \
				ft_strjoin \
				ft_strlen \
				ft_strncat \
				ft_strncpy \
				ft_strnew \
				ft_strsub \
				ft_swap \
				ft_bzero \
				ft_putendl_fd \
				ft_putendl \
				ft_putstr_fd \
				ft_putchar \
				ft_putstr \
				ft_putnbr_fd \
				ft_putnbr \
				ft_itoa \
				ft_numcount \
				ft_atoi_base \
				ft_itoa_base \

SRCS		=	$(addsuffix .c, $(LIBFT))
OBJS		=	$(addsuffix .o, $(LIBFT))

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
