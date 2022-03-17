# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/17 14:09:34 by enijakow          #+#    #+#              #
#    Updated: 2022/03/17 17:42:46 by enijakow         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXECUTABLE = ./cub3d

HEADERS = \
include/cub_ext.h \
include/cub_gfx.h \
include/cub_math.h \
include/cub.h \
utils/utils.h \
utils/reader/reader.h
utils/stringbuilder/stringbuilder.h

SOURCES = \
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
