CFLAGS = -Wall -Wextra -Werror

CC = cc

NAME = push_swap

NAME_BONUS = checker

LIBFT = src/libft/

LIBFT_NAME = src/libft/libft.a

FILES = src/helpers.c src/helpers2.c add_numbers.c move/move_push.c move/move_rotate.c move/move_swap.c \
 	 main.c sort/sort_three.c sort/sort_four.c sort/sort_five.c index_list.c sort/sort_list.c

FILES_BONUS = src/helpers.c src/helpers2.c add_numbers.c move/move_push.c move/move_rotate.c move/move_swap.c \
 	src/get_next_line/get_next_line.c src/get_next_line/get_next_line_utils.c src/helpers_bonus.c main_bonus.c 

FILES_O = $(FILES:.c=.o)

BONUS_O = $(FILES_BONUS:.c=.o)

$(NAME) :  $(FILES_O)
	make -C $(LIBFT)
	cc $(CFLAGS)  $? $(LIBFT_NAME) -o $@ 

$(NAME_BONUS) :  $(BONUS_O)
	make -C $(LIBFT)
	cc $(CFLAGS)  $? $(LIBFT_NAME) -o $@ 

bonus : $(NAME_BONUS)

all : $(NAME) $(NAME_BONUS)

 clean : 
	make clean -C $(LIBFT)
	rm -f $(FILES_O) $(BONUS_O)

fclean : clean
	make fclean -C $(LIBFT)
	rm -f $(NAME) $(NAME_BONUS)

re : fclean all

.PHONY : clean fclean
