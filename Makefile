NAME			= cub3d
LIBFT			= libft.a
MLX				= libmlx_Linux.a

SRCS            =	ft_main.c \
					ft_parsing_akadil.c \
					ft_rendering.c \
					rendering/ft_render_projection.c

SRCS_DIR		= ./srcs
BUILD_DIR       = ./.build
INCLUDES_DIR	= ./includes
LIBFT_DIR		= ./libft
MLX_DIR			= ./mlx_linux

OBJS			= $(addprefix $(BUILD_DIR)/, $(SRCS))
OBJS			:= $(OBJS:%.c=%.o)
SRCS			:= $(addprefix $(SRCS_DIR)/, $(SRCS))

CC				= cc
CFLAGS          = -Wall -Werror -Wextra
HFLAGS			= -I $(INCLUDES_DIR) -I $(MLX_DIR)

all						: ${NAME}

${NAME}         		: ${OBJS}
			${CC} $(OBJS) -o $(NAME) -Lmlx_linux -lmlx_Linux -lXext -lX11 -lm -lz -Llibft -lft  

${BUILD_DIR}/%.o		: $(SRCS_DIR)/%.c $(LIBFT_DIR)/$(LIBFT) $(MLX_DIR)/$(MLX)
			${CC} -g3 $(HFLAGS) ${CFLAGS} -O3 -c $< -o $@ 

$(LIBFT_DIR)/$(LIBFT)	:
			make -C $(LIBFT_DIR)

$(MLX_DIR)/$(MLX)		:
			make -C $(MLX_DIR)

clean					:
			make -C $(LIBFT_DIR) clean
			make -C $(MLX_DIR) clean
			rm -rf ${OBJS}

fclean					: clean
			rm -rf ${NAME} $(LIBFT_DIR)/$(LIBFT) $(MLX_DIR)/$(MLX)

re						: fclean all

.PHONY					: all clean fclean re