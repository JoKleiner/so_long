
MLX42_URL	= https://github.com/codam-coding-college/MLX42.git
MLX42_DIR	= MLX42
BUILD_DIR	= $(MLX42_DIR)/build

LIBFT_DIR   = libft
PRINTF_DIR  = $(LIBFT_DIR)/printf
GET_NL_DIR	= $(LIBFT_DIR)/get_next_line
SRC_DIR		= src

SRCS		= $(SRC_DIR)/so_long.c $(SRC_DIR)/map_check.c $(SRC_DIR)/count_lines_init_map.c $(SRC_DIR)/hero.c $(SRC_DIR)/start_image.c $(SRC_DIR)/utils.c $(SRC_DIR)/check_doable.c
SRCS_GET_NL	= $(GET_NL_DIR)/get_next_line.c $(GET_NL_DIR)/get_next_line_utils.c
SRCS_LIBFT	= $(LIBFT_DIR)/ft_memcpy.c $(LIBFT_DIR)/ft_strjoin.c $(LIBFT_DIR)/ft_strlen.c

OBJS = ${SRCS:.c=.o} ${SRCS_LIBFT:.c=.o} ${SRCS_GET_NL:.c=.o} ${PRINTF_DIR}/libftprintf.a

NAME			= so_long
HEADER 			= $(SRC_DIR)/so_long.h
CC				= gcc
CFLAGS			= -Wextra -Wall -Werror
#-fsanitize=address -g
LDFLAGS			= -ldl -lglfw -lm -lpthread -L$(BUILD_DIR) -lmlx42 -I$(MLX42_DIR)

all: printf $(NAME)

printf:
	@make -C ${PRINTF_DIR}

$(MLX42_DIR):
	@printf "Cloning MLX42... "
	@git clone $(MLX42_URL) $(MLX42_DIR) > /dev/null 2>&1
	@printf "\033[0;32mDone.\033[0m\n"
	
$(BUILD_DIR): $(MLX42_DIR)
	@printf "Configuring MLX42 & cmake... "
	@cd $(MLX42_DIR) && cmake -B build > /dev/null
	@printf "\033[0;32mDone.\033[0m\n"
	@printf "Building MLX42 library & cmake... "
	@cd $(MLX42_DIR) && cmake --build build -j4 > /dev/null
	@printf "\033[0;32mDone.\033[0m\n"
	
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -I$(MLX42_DIR) -c $< -o $@ > /dev/null

$(LIBFT_DIR)/%.o: $(LIBFT_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@ > /dev/null

$(GET_NL_DIR)/%.o: $(GET_NL_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@ > /dev/null

$(NAME): $(BUILD_DIR) $(OBJS)
	@printf "Compiling SRC/Libft/Get_NL... "
	@printf "\033[0;32mDone.\033[0m\n"
	@printf "Linking $(NAME)... "
	@$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $(NAME) > /dev/null
	@printf "\033[0;32mDone.\033[0m\n"
	@printf "\033[0;32mso_long successfully built!\033[0m\n"

clean:
	@printf "Remove MLX build... "
	@rm -rf $(BUILD_DIR)
	@printf "\033[0;31mRemoved.\033[0m\n"
	@printf "Remove o-files... "
	@rm -f ${SRCS:.c=.o} ${SRCS_LIBFT:.c=.o} ${SRCS_GET_NL:.c=.o}
	@make -C ${PRINTF_DIR} -f Makefile clean
	@printf "\033[0;31mRemoved.\033[0m\n"

fclean: clean
	@printf "Remove so_long, MLX42... "
	@rm -f so_long
	@make -C ${PRINTF_DIR} -f Makefile fclean
	@rm -rf $(MLX42_DIR)
	@printf "\033[0;31mRemoved.\033[0m\n"

re: fclean all

.PHONY: all printf src clean fclean re
