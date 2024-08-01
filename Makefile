# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iassil <iassil@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/04 21:44:18 by iassil            #+#    #+#              #
#    Updated: 2024/08/01 11:37:18 by iassil           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	cc
CC				+=	-Wall -Wextra -Werror
MLX				=	/Users/$(USER)/.MLX42/build/libmlx42.a -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"
MLX				+=	-framework Cocoa -framework OpenGL -framework IOKit
INCLUDE			=	-I./lib/MLX42
RM				=	rm -f
NAME			=	cub3D
NAME_BONUS		=	cub3D_bonus
SRC_HR_H		=	mandatory/include/cub3d.h
SRC_HR_BONUS_H	=	bonus/include/cub3d_bonus.h
LIB_HR_H		=	mandatory/include/libft.h
LIB_HR_BONUS_H	=	bonus/include/libft_bonus.h
GNL_HR_H		=	mandatory/include/get_next_line.h
GNL_HR_BONUS_H	=	bonus/include/get_next_line_bonus.h
FLD_NAME		=	._object_files

##### SOURCE FILES #######################################################################
SRC_FILES	=	cub3d.c				ft_check_input.c		src_utils.c

PRS_FILES	=	ft_parse.c			ft_to_2d.c			ft_map_utils3.c		ft_map_utils4.c 	\
				ft_free.c			ft_map_utils.c		ft_map_utils2.c		ft_map_utils4.c		\
				ft_map_utils5.c		ft_map_utils6.c		ft_map_utils7.c		ft_map_utils8.c		\
				ft_map_utils9.c		ft_check_range.c	ft_map_validity.c	utils.c				\
				utils2.c
				

EXEC_FILES	=	colors.c			free_func.c				mlx_destroy.c		render_pixel.c	\
				draw.c				get_distance.c			player_mv.c			textures.c		\
				execution.c			get_distance_utils.c	raycasting.c		utils.c			\
				execution_utils.c	mlx.c					raycasting_utils.c

UTILS_FILES	=	t_list.c			t_tools.c

GNL_FILES	=	get_next_line.c		get_next_line_utils.c

LIB_FILES	=	ft_atoi.c			ft_bzero.c				ft_calloc.c			\
				ft_isalnum.c		ft_isalpha.c			ft_isascii.c		\
				ft_isdigit.c		ft_isprint.c			ft_memchr.c			\
				ft_memcmp.c			ft_memcpy.c				ft_memmove.c		\
				ft_memset.c			ft_strchr.c				ft_strdup.c			\
				ft_strjoin.c		ft_strlcat.c			ft_strlcpy.c		\
				ft_strlen.c			ft_strncmp.c			ft_strnstr.c		\
				ft_strrchr.c		ft_strtrim.c			ft_substr.c			\
				ft_tolower.c		ft_toupper.c			ft_itoa.c			\
				ft_strmapi.c		ft_striteri.c			ft_putchar_fd.c		\
				ft_putstr_fd.c		ft_putendl_fd.c			ft_putnbr_fd.c		\
				ft_split.c
##########################################################################################

LIB_SRC		=	$(addprefix mandatory/lib/libft/,$(LIB_FILES))
GNL_SRC		=	$(addprefix mandatory/lib/gnl/,$(GNL_FILES))
SRC_SRC		=	$(addprefix mandatory/src/,$(SRC_FILES))
PRS_SRC		=	$(addprefix mandatory/parsing/,$(PRS_FILES))
EXEC_SRC	=	$(addprefix mandatory/raycasting/,$(EXEC_FILES))
UTILS_SRC	=	$(addprefix mandatory/t_utils/,$(UTILS_FILES))

LIB_OBJ		=	$(addprefix $(FLD_NAME)/,$(LIB_SRC:.c=.o))
GNL_OBJ		=	$(addprefix $(FLD_NAME)/,$(GNL_SRC:.c=.o))
SRC_OBJ		=	$(addprefix $(FLD_NAME)/,$(SRC_SRC:.c=.o))
PRS_OBJ		=	$(addprefix $(FLD_NAME)/,$(PRS_SRC:.c=.o))
EXEC_OBJ	=	$(addprefix $(FLD_NAME)/,$(EXEC_SRC:.c=.o))
UTILS_OBJ	=	$(addprefix $(FLD_NAME)/,$(UTILS_SRC:.c=.o))

OBJ 		=	$(SRC_OBJ) $(GNL_OBJ) $(LIB_OBJ)	\
				$(PRS_OBJ) $(UTILS_OBJ) $(EXEC_OBJ)

##### SOURCE BONUS FILES #################################################################
SRC_BONUS_FILES		=	cub3d_bonus.c			ft_check_input_bonus.c		src_utils_bonus.c

PRS_BONUS_FILES		=	ft_parse_bonus.c		ft_to_2d_bonus.c		ft_map_utils3_bonus.c		ft_map_utils4_bonus.c 	\
						ft_free_bonus.c			ft_map_utils_bonus.c	ft_map_utils2_bonus.c		ft_map_utils4_bonus.c	\
						ft_map_utils5_bonus.c	ft_map_utils6_bonus.c	ft_map_utils7_bonus.c		ft_map_utils8_bonus.c	\
						ft_map_utils9_bonus.c	ft_check_range_bonus.c	ft_map_validity_bonus.c		utils_bonus.c			\
						utils_bonus2.c
				

EXEC_BONUS_FILES	=	animation_bonus.c		get_distance_bonus.c		raycasting_bonus.c			\
						colors_bonus.c			get_distance_utils_bonus.c	raycasting_utils_bonus.c	\
						draw_bonus.c			minimap_bonus.c				render_pixel_bonus.c		\
						execution_bonus.c		mlx_bonus.c					textures_bonus.c			\
						execution_utils_bonus.c	mlx_destroy_bonus.c			utils_bonus.c				\
						free_func_bonus.c		player_mv_bonus.c			mlx_mouse_bonus.c

UTILS_BONUS_FILES	=	t_list_bonus.c			t_tools_bonus.c

GNL_BONUS_FILES		=	get_next_line_bonus.c	get_next_line_utils_bonus.c

LIB_BONUS_FILES		=	ft_atoi_bonus.c			ft_bzero_bonus.c			ft_calloc_bonus.c		\
						ft_isalnum_bonus.c		ft_isalpha_bonus.c			ft_isascii_bonus.c		\
						ft_isdigit_bonus.c		ft_isprint_bonus.c			ft_memchr_bonus.c		\
						ft_memcmp_bonus.c		ft_memcpy_bonus.c			ft_memmove_bonus.c		\
						ft_memset_bonus.c		ft_strchr_bonus.c			ft_strdup_bonus.c		\
						ft_strjoin_bonus.c		ft_strlcat_bonus.c			ft_strlcpy_bonus.c		\
						ft_strlen_bonus.c		ft_strncmp_bonus.c			ft_strnstr_bonus.c		\
						ft_strrchr_bonus.c		ft_strtrim_bonus.c			ft_substr_bonus.c		\
						ft_tolower_bonus.c		ft_toupper_bonus.c			ft_itoa_bonus.c			\
						ft_strmapi_bonus.c		ft_striteri_bonus.c			ft_putchar_fd_bonus.c	\
						ft_putstr_fd_bonus.c	ft_putendl_fd_bonus.c		ft_putnbr_fd_bonus.c	\
						ft_split_bonus.c
##########################################################################################

LIB_SRC_BONUS		=	$(addprefix bonus/lib/libft/,$(LIB_BONUS_FILES))
GNL_SRC_BONUS		=	$(addprefix bonus/lib/gnl/,$(GNL_BONUS_FILES))
SRC_SRC_BONUS		=	$(addprefix bonus/src/,$(SRC_BONUS_FILES))
PRS_SRC_BONUS		=	$(addprefix bonus/parsing/,$(PRS_BONUS_FILES))
EXEC_SRC_BONUS		=	$(addprefix bonus/raycasting/,$(EXEC_BONUS_FILES))
UTILS_SRC_BONUS		=	$(addprefix bonus/t_utils/,$(UTILS_BONUS_FILES))

LIB_OBJ_BONUS		=	$(addprefix $(FLD_NAME)/,$(LIB_SRC_BONUS:.c=.o))
GNL_OBJ_BONUS		=	$(addprefix $(FLD_NAME)/,$(GNL_SRC_BONUS:.c=.o))
SRC_OBJ_BONUS		=	$(addprefix $(FLD_NAME)/,$(SRC_SRC_BONUS:.c=.o))
PRS_OBJ_BONUS		=	$(addprefix $(FLD_NAME)/,$(PRS_SRC_BONUS:.c=.o))
EXEC_OBJ_BONUS		=	$(addprefix $(FLD_NAME)/,$(EXEC_SRC_BONUS:.c=.o))
UTILS_OBJ_BONUS		=	$(addprefix $(FLD_NAME)/,$(UTILS_SRC_BONUS:.c=.o))

OBJ_BONUS 			=	$(SRC_OBJ_BONUS) $(GNL_OBJ_BONUS) $(LIB_OBJ_BONUS)	\
						$(PRS_OBJ_BONUS) $(UTILS_OBJ_BONUS) $(EXEC_OBJ_BONUS)

########### Goal Target
all: $(NAME)

bonus: $(NAME_BONUS)

# MANDATORY PART
$(FLD_NAME)/mandatory/src/%.o: mandatory/src/%.c $(SRC_HR_H)
	@mkdir -p $(dir $@)
	@$(CC) -c $< -o $@

$(FLD_NAME)/mandatory/parsing/%.o: mandatory/parsing/%.c $(SRC_HR_H)
	@mkdir -p $(dir $@)
	@$(CC) -c $< -o $@

$(FLD_NAME)/mandatory/t_utils/%.o: mandatory/t_utils/%.c $(SRC_HR_H)
	@mkdir -p $(dir $@)
	@$(CC) -c $< -o $@

$(FLD_NAME)/mandatory/lib/gnl/%.o: mandatory/lib/gnl/%.c $(GNL_HR_H)
	@mkdir -p $(dir $@)
	@$(CC) -c $< -o $@

$(FLD_NAME)/mandatory/lib/libft/%.o: mandatory/lib/libft/%.c $(LIB_HR_H)
	@mkdir -p $(dir $@)
	@$(CC) -c $< -o $@

$(FLD_NAME)/mandatory/raycasting/%.o: mandatory/raycasting/%.c $(SRC_HR_H)
	@mkdir -p $(dir $@)
	@$(CC) -c $< -o $@ $(INCLUDE)
######################################################

# BONUS PART
$(FLD_NAME)/bonus/src/%.o: bonus/src/%.c $(SRC_HR_BONUS_H)
	@mkdir -p $(dir $@)
	@$(CC) -c $< -o $@

$(FLD_NAME)/bonus/parsing/%.o: bonus/parsing/%.c $(SRC_HR_BONUS_H)
	@mkdir -p $(dir $@)
	@$(CC) -c $< -o $@

$(FLD_NAME)/bonus/t_utils/%.o: bonus/t_utils/%.c $(SRC_HR_BONUS_H)
	@mkdir -p $(dir $@)
	@$(CC) -c $< -o $@

$(FLD_NAME)/bonus/lib/gnl/%.o: bonus/lib/gnl/%.c $(GNL_HR_BONUS_H)
	@mkdir -p $(dir $@)
	@$(CC) -c $< -o $@

$(FLD_NAME)/bonus/lib/libft/%.o: bonus/lib/libft/%.c $(LIB_HR_BONUS_H)
	@mkdir -p $(dir $@)
	@$(CC) -c $< -o $@

$(FLD_NAME)/bonus/raycasting/%.o: bonus/raycasting/%.c $(SRC_HR_BONUS_H)
	@mkdir -p $(dir $@)
	@$(CC) -c $< -o $@ $(INCLUDE)
######################################################

$(NAME): $(OBJ)
	@echo "$(YELLOW)[ ~ ] Compilation of the Objects files...$(RESET)"
	@$(CC) $(MLX) $^ -o $@ 
	@echo "$(GREEN)[ ✓ ] Executable file Compiled Successfully!$(RESET)"

$(NAME_BONUS): $(OBJ_BONUS)
	@echo "$(YELLOW)[ ~ ] Compilation of the Objects files...$(RESET)"
	@$(CC) $(MLX) $^ -o $@ 
	@echo "$(GREEN)[ ✓ ] Executable file Compiled Successfully!$(RESET)"

clean:
	@echo "$(YELLOW)[ ~ ] Removing Object files $(RESET)"
	@$(RM) $(OBJ) $(OBJ_BONUS)
	@$(RM) -rf $(FLD_NAME)
	@echo "$(GREEN)[ ✓ ] Object files removed successfully!$(RESET)"
	
fclean: clean
	@echo "$(YELLOW)[ ~ ] Removing Executable...$(RESET)"
	@$(RM) $(NAME) $(NAME_BONUS)
	@echo "$(GREEN)[ ✓ ] Executable files removed successfully!$(RESET)"

re: fclean all

.PHONY: all fclean clean re

########## DFine ANSI escape codes for colors
GREEN=	\033[1;32m
YELLOW=	\033[33m
RESET=	\033[0m		# No Color