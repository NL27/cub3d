# cub3d

0. Initial Check
-> args, files etc

1. Read 
-> parse the arguments

2. Map 
-> Create the map structure with block for walls, air for nothing and start for start

3. Rendering
3a Raycasting for finding the ray wall intersection of the map
3b Creating everything on the screen

Create a global block (struct block) with everything inside (textures for the 4 different directions)

Create a map (struct map) with all the infos about the map (walls, air, start)

OVERVIEW

ALLOWED FUNCTIONS
• open, close, read, write, printf, malloc, free, perror, strerror, exit
• All functions of the math library (-lm man man 3 math)
• All functions of the MinilibX

GENERAL

Different Wall textures for North, South, East, West
Floor and Ceiling must have different colors.

left and right arrows allow one to look left and right
WASD keys allow one to move forwards, left, backwards and right
ESC key and clicking exit will close the program

files with .cub must be taken in as an argument

ONLY 6 different characters are allowed for the MAPS:
0 for an empty space
1 for a wall
N for the Startposition facing North
S for the Startposition facing South
E for the Startposition facing East
W for the Startposition facing West

if the MAP is NOT surrounded by walls (1) it should return an error

???
◦ Except for the map content, each type of element can be separated by one or more empty line(s).
◦ Except for the map content which always has to be the last, each type of element can be set in any order in the file.
◦ Except for the map, each type of information from an element can be separated by one or more space(s).
◦ The map must be parsed as it looks in the file. Spaces are a valid part of the map and are up to you to handle. You must be able to parse any kind of map, as long as it respects the rules of the map.


EXAMPLE OF .cub file

NO ./path_to_north_texture
SO ./path_to_south_texture
WE ./path_to_west_texture
EA ./path_to_east_texture

F	37,100,0
C	37,30,0

		1111111111111111111111111
		1000000000110000000000001
		1011000001110000000000001
		1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
