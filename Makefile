
MLX42_URL	= https://github.com/codam-coding-college/MLX42.git
MLX42_DIR	= MLX42
BUILD_DIR	= $(MLX42_DIR)/build

SRC_DIR		= src

SRCS		= $(SRC_DIR)/so_long.c
OBJS		= ${SRCS:.c=.o}

NAME		= so_long
CC			= gcc
CFLAGS		= -Wextra -Wall -Werror
LDFLAGS		= -ldl -lglfw -lm -lpthread -L$(BUILD_DIR) -lmlx42 -I$(MLX42_DIR)


all: $(NAME)


$(MLX42_DIR):
	@printf "Cloning MLX42... "
	@git clone $(MLX42_URL) $(MLX42_DIR) > /dev/null 2>&1
	@printf "\033[0;32mDone.\033[0m\n"
	
$(BUILD_DIR): $(MLX42_DIR)
	@printf "Configuring MLX42 & cmake -B build... "
	@cd $(MLX42_DIR) && cmake -B build > /dev/null
	@printf "\033[0;32mDone.\033[0m\n"
	@printf "Building MLX42 library & cmake --build build -j4... "
	@cd $(MLX42_DIR) && cmake --build build -j4 > /dev/null
	@printf "\033[0;32mDone.\033[0m\n"

$(OBJS): $(SRCS)
	@printf "Compiling $<... "
	@$(CC) $(CFLAGS) -I$(MLX42_DIR) -c $< -o $@ > /dev/null
	@printf "\033[0;32mDone.\033[0m\n"

$(NAME): $(BUILD_DIR) $(OBJS)
	@printf "Linking $(NAME)... "
	@$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $(NAME) > /dev/null
	@printf "\033[0;32mDone.\033[0m\n"
	@printf "\033[0;32mso_long successfully built!\033[0m\n"


clean:
	rm -rf $(BUILD_DIR) $(NAME)
	rm -f $(OBJS)

fclean: clean
	rm -rf $(MLX42_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all src clean fclean re
