NAME = push_swap
HEADER			= push_swap.h
FILES 			= ft_utils1.c\
 				  ft_utils2.c\
  				  ft_utils3.c\
 				  pa_pb_ra_rb.c\
 				  rra_rrb_sa_sb.c\
				  stack_prep.c\
				  get_elem.c\
				  push_swap.c

FILES_O			= $(FILES:.c=.o)
SRCS 			= $(addprefix src/, $(FILES))
OBJS 			= $(addprefix obj/, $(FILES_O))
OBJDIR			= obj
CC				= clang
RM				= rm -rf
CFLAGS			= -I. -Wall -Wextra -Werror
SRC_DIR			= src

obj/%.o :		src/%.c $(HEADER)
				$(CC) $(CFLAGS) -c $< -o $@

all:			$(OBJDIR) $(NAME)

$(OBJDIR):		
				@mkdir $(OBJDIR)

$(NAME):		$(OBJS) 
				$(CC) $(FLAGS)  -o $(NAME) $(OBJS) 
				@echo "all done"

clean:			
				@ $(RM) $(OBJDIR)

fclean:			clean
				@ $(RM) $(NAME)

re:				fclean all

.PHONY:			all bonus clean fclean re
