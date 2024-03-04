CFLAGS = -Wall -Wextra -Werror

CC = cc

NAME = push_swap

FILES = helpers.c add_numbers.c move_push.c move_rotate.c move_swap.c \
 	 main.c sort_three.c sort_four.c sort_five.c index_list.c sort_list.c

FILES_O = $(FILES:.c=.o)

all : $(NAME) 

$(NAME) :  $(FILES_O)
	make -C libft
	cc $(CFLAGS)  $? libft/libft.a -o $@ 

 clean : 
	make clean -C libft/
	rm -f $(FILES_O)

fclean : clean
	make fclean -C libft/
	rm -f $(NAME)

re : fclean all

.PHONY : clean fclean
