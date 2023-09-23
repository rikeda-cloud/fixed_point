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

ifdef FIXED
SRCS		+=	$(SRCS_DIR)main_fixed.c
endif

ifdef INT
SRCS		+=	$(SRCS_DIR)main_int.c
endif

ifdef DOUBLE
SRCS		+=	$(SRCS_DIR)main_double.c
endif

OBJS		= 	$(SRCS:%.c=%.o)

$(TARGET): $(NAME) $(MAIN)
	$(CC) $(CFLAGS) $^ -o $@ $(LMFLAG)

$(NAME): $(OBJS)
	$(AR) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

all: $(TARGET)

clean:
	$(RM) $(NAME) $(SRCS_DIR)*.o

fclean:	clean
		$(RM) $(TARGET)

re:		fclean all

int:
	make INT=1

fixed:
	make FIXED=1

double:
	make DOUBLE=1

.PHONY:	all clean fclean re
