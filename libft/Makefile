NAME = libft.a

HEADER = libft.h

SRC =  ft_atoi.c\
	ft_strncmp.c\
	ft_isdigit.c\
	ft_strdup.c\
	ft_strchr.c\
	ft_strlen.c\
	ft_putstr.c\
	ft_calloc.c\
	ft_bzero.c\
	ft_memmove.c\
	ft_memset.c\
	ft_substr.c\
	ft_split.c\
	ft_strjoin.c



OBJ = $(SRC:.c=.o)

SRCBN = ft_lstsize.c\
	ft_lstadd_back.c\
	ft_lstclear.c\
	ft_lstnew.c\
	ft_lstlast.c

OBJBN = $(SRCBN:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o: %.c $(HEADER)
	@gcc -Wall -Wextra -Werror -c $< -o $@

bonus: $(SRCBN)	$(OBJBN) $(HEADER)
	@ar rc $(NAME) $(OBJBN)
	@ranlib $(NAME)

so:
	@gcc -shared -o libft.so  $(OBJ) $(OBJBN)

clean:
	@rm -f $(OBJ) $(OBJBN)

fclean:
	@rm -f  $(OBJ) $(OBJBN) $(NAME)

re: fclean all

.PHONY: all clean fclean re
