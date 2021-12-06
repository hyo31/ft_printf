# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mgroen <mgroen@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/26 14:46:32 by mgroen        #+#    #+#                  #
#    Updated: 2021/12/06 12:45:48 by mgroen        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC = ft_printf.c format_p.c format_s_c.c format_i_d.c format_x.c format_u.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@cp libft/libft.a $(NAME)
	@ar rcs $(NAME) $(OBJ)

%.o: %.c
	@gcc -c -Wall -Wextra -Werror $<

clean:
	@rm -f *.o
	@make -C libft/ clean

fclean: clean
	@rm  -f $(NAME)
	@make -C libft/ fclean

re: fclean all

.PHONY: all clean fclean re
