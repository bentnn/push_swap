NAME1 = push_swap

NAME2 = checker

HEADER1 =	push_swap_files/push_swap.h \
			push_swap_files/swap_commands_ps.h

HEADER2 =	checker_files/checker.h \
			checker_files/swap_commands.h \
			gnl/get_next_line.h \
			gnl/gnl_systemic.h

SRCS1 = 	    push_swap_files/main.c \
				push_swap_files/doing_moves.c \
				push_swap_files/push_commands_ps.c \
				push_swap_files/push_swap.c \
				push_swap_files/reverse_rotate_commands_ps.c \
				push_swap_files/rotate_commands_ps.c \
				push_swap_files/swap_commands_ps.c \
				push_swap_files/data_func.c \
				push_swap_files/min_way_and_sort_three.c \
				push_swap_files/count_ways.c

SRCS2 = 	    checker_files/main.c \
				checker_files/data_func.c \
				checker_files/find_command.c \
				checker_files/output_stacks.c \
				checker_files/push_commands_checker.c \
				checker_files/reverse_rotate_commands_checker.c \
				checker_files/rotate_commands_checker.c \
				checker_files/swap_commands.c \
				checker_files/work_with_commands.c \
				gnl/get_next_line.c \
				gnl/get_next_line_utils.c \
				gnl/gnl_update.c

OBJS1 = 		$(SRCS1:.c=.o)

OBJS2 = 		$(SRCS2:.c=.o)

OBJS = 			$(OBJS1) $(OBJS2)

LIBFT =		libft

CC :=		gcc
CFLAGS =	-Wall -Werror -Wextra
LIB_FLAGS =	-L libft -lft
RM =		rm -f

#deps :=	$(patsubst %.o,%.d,$(OBJS))
#-include $(deps)
#DEPFLAGS = -MMD -MF $(@:.o=.d)

all:		$(NAME2) $(NAME1)

$(NAME1):	$(OBJS1) $(HEADER1) $(LIBFT)
			@make -s -C $(LIBFT)
			@ $(CC) $(CFLAGS) $(LIB_FLAGS) $(OBJS1) -o $(NAME1)

$(NAME2):	$(OBJS2) $(HEADER2) $(LIBFT)
			@make -s -C $(LIBFT)
			@ $(CC) $(CFLAGS) $(LIB_FLAGS) $(OBJS2) -o $(NAME2)

#%.o:	%.c
#	$(CC) $(CFLAGS) -c $< $(DEPFLAGS)

clean:
			@ $(RM) $(OBJS2) $(OBJS1) $(deps)
			@make clean -C $(LIBFT)

fclean:		clean
			@ $(RM) $(NAME2) $(NAME1)
			@make fclean -C $(LIBFT)

re:		fclean all

.PHONY:	all clean fclean re