CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = linked_list/ft_lstnew_bonus.c linked_list/ft_lstsize_bonus.c  linked_list/ft_lstadd_back_bonus.c \
	linked_list/ft_lstlast_bonus.c actions.c handle_args.c ft_atoi.c ft_split.c main.c ft_sort.c free_all_leaks.c \
	bubble_sort.c linked_list/ft_lstclear_bonus.c sort_utils.c push_to_b.c handel_error_utils.c

BONUS_SRCS = linked_list/ft_lstnew_bonus.c linked_list/ft_lstsize_bonus.c  linked_list/ft_lstadd_back_bonus.c \
	linked_list/ft_lstlast_bonus.c ./bonus/actions_bonus.c ./bonus/actions2_bonus.c ./bonus/handel_args_bonus.c ./bonus/ft_atoi_bonus.c \
	./bonus/ft_split_bonus.c ./bonus/free_all_leaks_bonus.c ./bonus/handel_args_utils_bonus.c \
	./bonus/bubble_sort_bonus.c linked_list/ft_lstclear_bonus.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c ./bonus/main_bonus.c

NAME = push_swap
NAME_BONUS = checker

OBJECT = $(SRCS:.c=.o)
BONUS_OBJ = $(BONUS_SRCS:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

all : $(NAME)

$(NAME) : $(OBJECT) 
	@$(CC) $(CFLAGS) $(OBJECT) -o $(NAME)

fclean : clean
	rm -f $(NAME) $(NAME_BONUS)

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) -o $(NAME_BONUS)

clean :
	rm -f $(OBJECT) $(BONUS_OBJ)

re: fclean all

run : all
	./$(NAME)

.PHONY : all fclean clean re

.SECONDARY: $(OBJECT) $(BONUS_OBJ)