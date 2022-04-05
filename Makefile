# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/03 19:50:54 by ijaaskel          #+#    #+#              #
#    Updated: 2021/11/03 19:59:16 by ijaaskel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fillit

FLAGS	=	-Wall -Wextra -Werror

SRC		=	./src/
SRCS	=	main.c	reader.c	solver.c	validater.c	writer.c
OBJS	=	$(SRCS:.c=.o)

LIB		=	./libft/libft.a

all:	$(NAME)

$(NAME):
	cd libft/ && make
	gcc $(FLAGS) -c $(addprefix $(SRC), $(SRCS))
	gcc -o $(NAME) $(OBJS) $(LIB)

clean:
	cd libft/ && make clean
	rm -v -f $(OBJS)
	rm -v -f *~

fclean:	clean
	cd libft/ && make fclean
	rm -v -f $(NAME)

re:		fclean all

.PHONY:	all clean fclean re