# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybellakr <ybellakr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/04 21:44:18 by iassil            #+#    #+#              #
#    Updated: 2024/07/17 11:16:23 by ybellakr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	cc
# CC			+=	-Wall -Wextra -Werror
CC			+=	-fsanitize=address -g
MLX			=	/Users/$(USER)/MLX42/build/libmlx42.a -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"
MLX			+=	-framework Cocoa -framework OpenGL -framework IOKit
INCLUDE		=	-I./lib/MLX42
RM			=	rm -f
NAME		=	cub3d
SRC_HR_H	=	include/cub3d.h
LIB_HR_H	=	include/libft.h
GNL_HR_H	=	include/get_next_line.h
FLD_NAME	=	._object_files

##### SOURCE FILES #######################################################################
SRC_FILES	=	cub3d.c				ft_check_input.c		src_utils.c

PRS_FILES	=	ft_parse.c			ft_to_2d.c				ft_free.c

EXEC_FILES	=	colors.c			execution_utils.c		minimap.c			\
				player_mv.c			render_pixel.c			draw.c				\
				get_distance.c		mlx.c					raycasting.c		\
				execution.c			get_distance_utils.c	mlx_destroy.c		\
				animation.c			textures.c				raycasting_utils.c	\
				utils.c

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

LIB_SRC		=	$(addprefix lib/libft/,$(LIB_FILES))
GNL_SRC		=	$(addprefix lib/gnl/,$(GNL_FILES))
SRC_SRC		=	$(addprefix src/,$(SRC_FILES))
PRS_SRC		=	$(addprefix parsing/,$(PRS_FILES))
EXEC_SRC	=	$(addprefix raycasting/,$(EXEC_FILES))
UTILS_SRC	=	$(addprefix t_utils/,$(UTILS_FILES))

LIB_OBJ		=	$(addprefix $(FLD_NAME)/,$(LIB_SRC:.c=.o))
GNL_OBJ		=	$(addprefix $(FLD_NAME)/,$(GNL_SRC:.c=.o))
SRC_OBJ		=	$(addprefix $(FLD_NAME)/,$(SRC_SRC:.c=.o))
PRS_OBJ		=	$(addprefix $(FLD_NAME)/,$(PRS_SRC:.c=.o))
EXEC_OBJ	=	$(addprefix $(FLD_NAME)/,$(EXEC_SRC:.c=.o))
UTILS_OBJ	=	$(addprefix $(FLD_NAME)/,$(UTILS_SRC:.c=.o))

OBJ 		=	$(SRC_OBJ) $(GNL_OBJ) $(LIB_OBJ)	\
				$(PRS_OBJ) $(UTILS_OBJ) $(EXEC_OBJ)

########### Goal Target
all: $(NAME)

# Define a pattern rule for compiling object files
$(FLD_NAME)/src/%.o: src/%.c $(SRC_HR_H)
	@mkdir -p $(dir $@)
	@$(CC) -c $< -o $@

$(FLD_NAME)/parsing/%.o: parsing/%.c $(SRC_HR_H)
	@mkdir -p $(dir $@)
	@$(CC) -c $< -o $@

$(FLD_NAME)/t_utils/%.o: t_utils/%.c $(SRC_HR_H)
	@mkdir -p $(dir $@)
	@$(CC) -c $< -o $@

$(FLD_NAME)/lib/gnl/%.o: lib/gnl/%.c $(GNL_HR_H)
	@mkdir -p $(dir $@)
	@$(CC) -c $< -o $@

$(FLD_NAME)/lib/libft/%.o: lib/libft/%.c $(LIB_HR_H)
	@mkdir -p $(dir $@)
	@$(CC) -c $< -o $@

$(FLD_NAME)/raycasting/%.o: raycasting/%.c $(SRC_HR_H)
	@mkdir -p $(dir $@)
	@$(CC) -c $< -o $@ $(INCLUDE)
######################################################

$(NAME): $(OBJ)
	@echo "$(YELLOW)[ ~ ] Compilation of the Objects files...$(RESET)"
	@$(CC) $(MLX) $^ -o $@ 
	@echo "$(GREEN)[ ✓ ] Executable file Compiled Successfully!$(RESET)"

clean:
	@echo "$(YELLOW)[ ~ ] Removing Object files $(RESET)"
	@$(RM) $(OBJ)
	@$(RM) -rf $(FLD_NAME)
	@echo "$(GREEN)[ ✓ ] Object files removed successfully!$(RESET)"
	
fclean: clean
	@echo "$(YELLOW)[ ~ ] Removing Executable...$(RESET)"
	@$(RM) $(NAME)
	@echo "$(GREEN)[ ✓ ] Executable files removed successfully!$(RESET)"

re: fclean all

.PHONY: all fclean clean re

########## DFine ANSI escape codes for colors
GREEN=	\033[1;32m
YELLOW=	\033[33m
RESET=	\033[0m		# No Color