# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enijakow <enijakow@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/17 14:09:34 by enijakow          #+#    #+#              #
#    Updated: 2022/03/17 14:15:32 by enijakow         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXECUTABLE = ./cub3d

HEADERS = \
include/cub_ext.h \
include/cub.h

SOURCES = \
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
