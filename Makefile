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

LDFLAGS		= -lxcb

ifeq ($(DEBUG), no)
    CFLAGS	= $(INCDIR) $(LDFLAGS) -W -Wall -Werror -Wextra -ansi -pedantic
else
    CFLAGS	= $(INCDIR) $(LDFLAGS) -g -pg
endif

$(NAME): $(OBJS)
	@ $(CC) $(OBJS) -o $(NAME) $(CFLAGS)
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
