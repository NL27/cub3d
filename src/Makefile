# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/17 14:09:34 by enijakow          #+#    #+#              #
#    Updated: 2022/03/23 13:52:57 by enijakow         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXECUTABLE = ./cub3d

HEADERS = \
include/cub_ext.h \
include/cub_gfx.h \
include/cub_map.h \
include/cub_math.h \
include/cub.h \
utils/utils.h \
utils/reader/reader.h \
utils/stringbuilder/stringbuilder.h

SOURCES = \
map/map_at.c \
map/map_check_inbounds.c \
map/map_create.c \
map/map_destroy.c \
map/map_get_height.c \
map/map_get_width.c \
map/map_put.c \
map/map_resize.c \
utils/memcpy.c \
utils/read_file.c \
utils/stringbuilder/stringbuilder.c \
main.c

OBJECTS = $(patsubst %.c,%.o,$(SOURCES))

CFLAGS = -Wall -Wextra -Werror
LDFLAGS = 

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(EXECUTABLE): $(OBJECTS) $(HEADERS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $(EXECUTABLE)

all: $(EXECUTABLE)

.phony: clean
clean:
	- $(RM) $(OBJECTS)

.phony: fclean
fclean: clean
	- $(RM) $(EXECUTABLE)
