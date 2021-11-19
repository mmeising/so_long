# so_long - 42 Heilbronn
Simple 2D game where the player can collect things and
needs to leave through the exit.

player and collectible radius modulo?
map tile_size standard and maximum window size?
so_long.c lines 100 and 101 needed?

# list of images in img_create
# create exit and coll in img_fill

To do:

1.	take input path to map, create a 2d array using get_next_line, ft_concat
	and split

2.	check if the map is correct (rectangular and walls on the edges)

3.	set tile_size:
	recursive function that decreases the tile_size (standard 101(?))
	by 2 if tile_size * tiles_in_x > 1920(?) or tile_size * tiles_in_y > 1080(?)
	and calls itself, otherwise returns

4.	create linked lists of coordinate pairs where the walls, player positions,
	exits and collectibles are. Set one player position inside map struct
	EDIT: no more linked list, for every new frame just go through the 2d array
	and put 1, P, E, C at the positions where they are. ignore 0 as new image
	will have it blacked out anyway

5.	create 90(?) images of tile_size * tile_size, each fully colored in an RGB 
	setting 17(?) steps from last (change_color_rainbow function)

6.	create player (transparent concentric circles), walls (transparent squares)
	and exit (?) images

7.	create base image of tile_size * tiles_in_x width and
	tile_size * tiles_in_y height

8.	every next screen render needs to:
	-	change to next background color
	-	put it on player, walls, exits and collectibles positions
	-	put all corresponding transparent images on top of background color

9.	on WASD key presses:
	-	check if spot is movable to and change player position, count_moves++
	-	put black image of tile_size * tile_size at old player position
	-	if player position == collectible position, delete that collectible
		from re-render (list management?) and count_collected++
	-	if player position == exit position, close game - finished!
