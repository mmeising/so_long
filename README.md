# so_long - 42 Heilbronn
Simple 2D game where the player has to collect things and
leave through the exit afterwards, possibly escaping enemies.

Maps are in .ber files and consist of:
1 = walls
0 = free spaces
C = collectibles
E = exits
P = player position (or enemy position for second and third P)

The map must be rectangular, walled off and have at least one P, E and C.
Maximum 3 P's possible (player + 2 enemies).

Summary of the program:

1.	check_map:
	take input path to map (given as argument), 
	check if it's rectangular,
	check if it's walled off,
	check if it only consists of valid chars,
	check if there is the correct amount of each char,
	set the tile size

2.	colors_circular_linked_list:
	create the circular linked list of the 90 cycling colors that is used
	for the color shift of the walls, the collectibles, the player and
	the exit once all collectibles are collected

3.	init_and_fill_images:
	create the red and green squares,
	create the player, exit, collectible (and exit) transparent images,
	set the steps and slow variables to 0

4.	render_next_frame:
	put a black image on the window (cleaning the window),
	put the tiles (walls, collectibles, exits) to the image,
	put the player to the image,
	put the count of stepps to the image,
	iterate the slow variable and cycle the colors every third iteration,
	if enemies exist:
		use rand() every 24th iteration of slow to make them move,
		put enemies to the image,
		check if the enemy position is on the player position
