# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/17 14:09:34 by enijakow          #+#    #+#              #
#    Updated: 2022/04/01 11:38:29 by nlenoch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXECUTABLE = ./cub3d
MLX_DIR = ./../mlx

HEADERS = \
include/cub_ext.h \
include/cub_gfx.h \
include/cub_map.h \
include/cub_math.h \
include/cub.h \
utils/utils.h \
utils/reader/reader.h \
utils/stringbuilder/stringbuilder.h

# gfx/mlx/gfx_create.c
# gfx/mlx/gfx_destroy.c

# gfx/screen/screen_blit.c
# gfx/tex/tex_at.c
# gfx/tex/tex_create.c
# gfx/tex/tex_destroy.c

SOURCES = \
gfx/rgb_create.c \
gfx/rgb_is_black.c \
gfx/rgb_scale.c \
gfx/rgb_split.c \
gfx/screen/screen_create.c \
gfx/screen/screen_destroy.c \
gfx/screen/screen_get_height.c \
gfx/screen/screen_get_width.c \
gfx/screen/screen_put.c \
gfx/screen/screen_render.c \
map/block_is_solid.c \
map/map_at.c \
map/map_check_inbounds.c \
map/map_create.c \
map/map_destroy.c \
map/map_get_height.c \
map/map_get_width.c \
map/map_put.c \
map/map_raycast.c \
map/map_resize.c \
map/map_validate.c \
utils/memcpy.c \
utils/read_file.c \
utils/stringbuilder/stringbuilder.c \
main.c

OBJECTS = $(patsubst %.c,%.o,$(SOURCES))

CFLAGS = -Wall -Wextra -Werror -03
LDFLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(EXECUTABLE): $(OBJECTS) $(HEADERS)
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJECTS) $(LDFLAGS) -o $(EXECUTABLE)

all: $(EXECUTABLE)

.phony: clean
clean:
	- make -C $(MLX_DIR) clean
	- $(RM) $(OBJECTS)

.phony: fclean
fclean: clean
	- $(RM) $(EXECUTABLE)

.phony: re
re: fclean all
