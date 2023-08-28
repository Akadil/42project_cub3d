NAME			= cub3d
LIBFT			= libft.a
MLX				= libmlx_Linux.a

SRCS            =	ft_main.c \
					event_handler.c \
					parsing.c \
					rendering.c \
					parsing/parsing_args.c \
					parsing/parsing_map.c \
					parsing/parsing_textures.c \
					parsing/ft_get_rows_fd.c \
					parsing/ft_fill_matrix.c \
					parsing/parsing_rgb.c \
					parsing/utils/parsing_args_utils.c \
					parsing/utils/parsing_utils.c \
					parsing/utils/textures_utils.c \
					init/init_game.c \
					rendering/rendering_background.c \
					rendering/rendering_projection.c \
					rendering/rendering_minimap.c \
					rendering/rendering_3d_object.c \
					rendering/utils/rendering_utils.c \
					rendering/react_to_event/react_to_event.c \
					rendering/react_to_event/react_to_move.c \
					rendering/react_to_event/react_to_rotate.c \
					rendering/draw_column/draw_column.c 
					# ft_parsing_akadil.c

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
HFLAGS			= -I $(INCLUDES_DIR) -I $(MLX_DIR) -I ./srcs/rendering/includes

all						: ${NAME}

${NAME}         		: ${OBJS}
			${CC} $(OBJS) -o $(NAME) -Lmlx_linux -lmlx_Linux -lXext -lX11 -lm -lz -Llibft -lft  

${BUILD_DIR}/%.o		: $(SRCS_DIR)/%.c $(LIBFT_DIR)/$(LIBFT) $(MLX_DIR)/$(MLX)
			${CC} -g3 $(HFLAGS) ${CFLAGS} -c $< -o $@ 

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