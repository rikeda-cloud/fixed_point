NAME				=	minirt
CC					=	cc
RM					=	rm -rf
MKDIR				=	mkdir -p
CFLAGS				=	-Wall -Wextra -Werror
LMFLAG				=	-lm

SRCS				=	main.c

OBJS				= 	$(SRCS:%.c=%.o)

all: $(OBJDIR) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LMFLAG)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@ $(LMFLAG)

clean:	
	$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re
