CFLAGS = -Wall -Wextra -Werror

CC = cc

NAME = push_swap

FILES = helpers.c add_numbers.c move_push.c move_rotate.c move_swap.c \
 	 main_test.c sort_three.c sort_four.c

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

.PHONY : clean fclean