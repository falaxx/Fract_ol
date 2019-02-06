NAME = fractol

SRC_PATH = src

SRC_NAME = trace.c init.c main.c pixels.c event.c  mode.c mode2.c keyhook.c colormode.c

CPPFLAGS = -I libft/includes/ -I /usr/local/include/ -MMD

LDFLAGS = -L libft/ -lft  -L /usr/local/include/ -lmlx

LDLIBS = -framework OpenGL -framework AppKit

CC = gcc

CFLAGS = -Werror -Wall -Wextra

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ_PATH = obj

HEADER_PATH = includes/

HEADER_NAME = fdf.h

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

HEADER = $(addprefix $(HEADER_PATH)/,$(HEADER_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	$(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) $^ -o $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	$(CC) $(CFLAGS) $(CPPFLAGS) -I $(HEADER_PATH) -o $@ -c $<

$(OBJ_PATH):
	@mkdir $(OBJ_PATH) 2> /dev/null || true

clean:
	make clean -C libft/
	rm -f $(OBJ) $(OBJ:.o=.d)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	make fclean -C libft/
	rm -f $(NAME)

re: fclean
	$(MAKE) all

.PHONY: make clean fclean re

-include $(OBJ:.o=.d)
