# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/17 14:09:34 by enijakow          #+#    #+#              #
#    Updated: 2022/04/16 17:23:00 by nlenoch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXECUTABLE = ./cub3d
MLX_DIR = ./../mlx

HEADERS = \
include/cub_ext.h \
include/cub_gfx.h \
include/cub_map.h \
include/cub_math.h \
include/cub_parser.h \
include/cub.h \
map/map_internal.h \
parser/parser_internal.h \
utils/utils.h \
utils/reader/reader.h \
utils/stringbuilder/stringbuilder.h

SOURCES = \
cub/cub_create.c \
cub/cub_destroy.c \
cub/cub_keydown.c \
cub/cub_keyup.c \
cub/cub_shoot_portal.c \
cub/cub_tick.c \
gfx/mlx/gfx_create.c \
gfx/mlx/gfx_destroy.c \
gfx/mlx/gfx_keys.c \
gfx/mlx/gfx_run.c \
gfx/mlx/gfx_set_tick_function.c \
gfx/rgb_create.c \
gfx/rgb_is_black.c \
gfx/rgb_scale.c \
gfx/rgb_split.c \
gfx/screen/screen_at.c \
gfx/screen/screen_blit.c \
gfx/screen/screen_create.c \
gfx/screen/screen_destroy.c \
gfx/screen/screen_draw_rect.c \
gfx/screen/screen_get_height.c \
gfx/screen/screen_get_width.c \
gfx/screen/screen_put.c \
gfx/screen/screen_render_minimap.c \
gfx/screen/screen_render.c \
gfx/tex/tex_at.c \
gfx/tex/tex_create.c \
gfx/tex/tex_destroy.c \
main.c \
map/block_is_solid.c \
map/clip_is_clipped.c \
map/direction_as_angle.c \
map/map_at.c \
map/map_check_inbounds.c \
map/map_create.c \
map/map_destroy.c \
map/map_get_color.c \
map/map_get_height.c \
map/map_get_width.c \
map/map_put.c \
map/map_raycast.c \
map/map_render_portals.c \
map/map_resize.c \
map/map_set_color.c \
map/map_set_spawn.c \
map/map_tex_at.c \
map/map_validate.c \
parser/parser.c \
parser/parser_parse_config_body.c \
parser/parser_parse_config_header.c \
parser/parser_parse_rgb.c \
utils/memcpy.c \
utils/read_file.c \
utils/string_ends_with.c \
utils/reader/reader.c \
utils/reader/reader_check_empty_line.c \
utils/reader/reader_check_newline.c \
utils/reader/reader_peek.c \
utils/reader/reader_read_int.c \
utils/reader/reader_read_until_newline.c \
utils/reader/reader_skip_whitespace.c \
utils/stringbuilder/stringbuilder.c

OBJECTS = $(patsubst %.c,%.o,$(SOURCES))

CFLAGS = -Wall -Wextra -Werror -Ofast
LDFLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit -lz

%.o: %.c $(HEADERS)
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
