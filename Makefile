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

# --- choice main or benchmark ---
# SRCS		+=	$(SRCS_DIR)main.c
SRCS		+=	$(SRCS_DIR)benchmark.c
# --- choice main or benchmark ---
#
OBJS		= 	$(SRCS:%.c=%.o)

ifdef DOUBLE
	CFLAGS	+=	-D DOUBLE=1
endif

ifdef FLOAT
	CFLAGS	+=	-D FLOAT=1
endif

ifdef LONG
	CFLAGS	+=	-D LONG=1
endif

ifdef LLONG
	CFLAGS	+=	-D LLONG=1
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
float:
	make FLOAT=1
long:
	make LONG=1
llong:
	make LLONG=1

.PHONY:	all clean fclean re
