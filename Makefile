TARGET		=	fixed_point
NAME		=	fixed_point.a
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
AR			=	ar rcs
RM			=	rm -rf
LMFLAG		=	-lm

SRCS_DIR	=	./srcs/
SRCS		=	$(SRCS_DIR)cast.c
SRCS		+=	$(SRCS_DIR)four_arithmetic_operations.c
SRCS		+=	$(SRCS_DIR)main.c
OBJS		= 	$(SRCS:%.c=%.o)

ifdef DOUBLE
	CFLAGS	+=	-D DOUBLE=1
endif

$(TARGET): $(NAME) $(MAIN)
	$(CC) $(CFLAGS) $^ -o $@ $(LMFLAG)

$(NAME): $(OBJS)
	$(AR) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

all: $(TARGET)

clean:
	$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME) $(TARGET)

re:		fclean all

double:
	make DOUBLE=1

.PHONY:	all clean fclean re
