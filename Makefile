DEBUG		= no

NAME		= tekwm

CC		= cc

SRCS_FILE	= main.c	\
		  tekwm.c	\
		  init_xcb.c	\
		  loop.c

SRCS		= $(addprefix src/, $(SRCS_FILE))

OBJS		= $(SRCS:.c=.o)

INCDIR		= -I./include

ifeq ($(DEBUG), no)
    CFLAGS	= $(INCDIR) -W -Wall -Werror -Wextra -ansi -pedantic
else
    CFLAGS	= $(INCDIR) -g -pg
endif

LDFLAGS		= -lxcb

$(NAME): $(OBJS)
	@ $(CC) $(OBJS) -o $(NAME)
	@ echo "these flags were use: $(CFLAGS)"

%.o: %.c
	@ $(CC) -c $< -o $@ $(CFLAGS)
	@ echo "compile $<"

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean clean re
