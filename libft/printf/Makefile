
NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_strlen.c ft_putstr.c ft_case_p_u.c ft_case_xx.c ft_putchar.c ft_putnbr.c ft_putstr_rev.c

OFILE = $(SRCS:.c=.o)

HEADER = ft_printf.h

all: $(NAME)

$(NAME): $(OFILE)
	ar rcs $(NAME) $(OFILE)


%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -f $(OFILE)

fclean: clean
	rm -f $(NAME)


re: fclean $(NAME)

.PHONY: all re fclean clean
