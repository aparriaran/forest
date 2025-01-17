struct room {
	const int room_id;
	const char *room_name;
	const char *room_desc;
	int walk_to[4];
	const char *walk_desc[4];
	const char *search_desc;
};

static struct room locations[] = {
	{
		0,
		"Village Entrance",
		"You stand at the entrance to a quiet village. To the north, you see a row of\n"
		"houses. To the east is a large field next to a forest.",
		{1,7,-1,-1},
		{"You walk north.","You walk east.",NULL,NULL},
		NULL
	},
	{
		1,
		"Edge of the Village",
		"You are near a row of small houses on the edge of a quiet village. More houses\n"
		"are to the north, while the village entrance is to the south.",
		{2,-1,0,-1},
		{"You walk north.",NULL,"You walk south.",NULL},
		NULL
	},
	{
		2,
		"Quiet Neighborhood",
		"You are in a quiet, residential neighborhood. You see people lurking behind\n"
		"pulled curtains out of the corner of your eye - you're being watched. There\n"
		"is a row of trash bins near the street. The village stretches both north and\n"
		"south.",
		{3,-1,1,-1},
		{"You walk north.",NULL,"You walk south.",NULL},
		"You dig into the trash bins."
	},
	{
		3,
		"Shopping District",
		"You are outside of a row of shops. You can hear the banging of a hammer on an\n"
		"anvil from an blacksmith's shop to the east. Next to the shop is a pile of old\n"
		"metal junk. To the west is an inn called The Sleepy Woodsman.",
		{-1,6,2,4},
		{NULL,"You enter the blacksmith's shop.","You walk south.","You enter the inn."},
		"You rummage through the junk pile."
	},
	{
		4,
		"The Sleepy Woodsman",
		"The cozy inn has a welcome desk near the door. A staircase leads north to the\n"
		"rooms upstairs. The exit is to the east.",
		{5,3,-1,-1},
		{"You walk up the stairs.","You leave the inn.",NULL,NULL},
		NULL
	},
	{
		5,
		"Upstairs at the Inn",
		"You are in a hallway on the second floor of the inn. There are four rooms here.\n"
		"All the doors are currently closed. There are tables standing next to the doors\n"
		"with assorted object and letters. A staircase leads downstairs to the south.",
		{-1,-1,4,-1},
		{NULL,NULL,"You walk down the stairs.",NULL},
		"You stealthily inspect the items on the tables."
	},
	{
		6,
		"The Blacksmith's Shop",
		"You enter the blacksmith's shop. There are intricate works of shaped metal all\n"
		"around the room - high quality weapons, armor, and tools. It looks expensive!",
		{-1,-1,-1,3},
		{NULL,NULL,NULL,"You exit the shop."},
		"You browse around the shop, looking for merchandise."
	},
	{
		7,
		"The Field Near the Village",
		"You are in a field. There is an entrance to a village to the west. To the east\n"
		"is a path through a tall grass field that leads to a forest.",
		{-1,8,-1,0},
		{NULL,"You walk east.",NULL,"You walk west."},
		NULL
	},
	{
		8,
		"Tall Grass Field",
		"You walking on a path surrounded by dense, tall grass. There might be snakes\n"
		"lurking in the grass. A village can be seen in the distance to the west. A\n"
		"forest can be seen in the distance to the east.",
		{-1,9,-1,7},
		{NULL,"You walk east.",NULL,"You walk west."},
		"You crawl through the grass, carefully searching."

	},
	{
		9,
		"Field Near the Cave and Forest",
		"You are standing in a field. A path to the south leads into a dark cave. A path\n"
		"to the east leads to the outskirts of a forest.",
		{-1,15,10,8},
		{NULL,"You walk east.","You walk down the path into the cave.","You walk west."},
		NULL
	},
	{
		10,
		"Cave Entrance",
		"You are standing inside a dark cave. Bright light can be seen through the\n"
		"entrance to the north. The cave stretches into darkness south.",
		{9,-1,11,-1},
		{"You leave the cave.",NULL,"You walk deeper south into the cave.",NULL},
		NULL
	},
	{
		11,
		"Cave",
		"You are deep in a cave. It is dark here, but you can see light coming from the\n"
		"north. The cave stretches into darkness south.",
		{10,-1,12,-1},
		{"You walk north.",NULL,"You slowly walk deeper into the cave.",NULL},
		NULL
	},
	{
		12,
		"Cave-In",
		"You are deep in a cave. A cave-in blocks a tunnel to the south. You can hear\n"
		"running water coming somewhere from the west.", 
		{11,-1,-1,-1},
		{"You walk north.",NULL,NULL,"You climb through the passage west."},
		NULL
	},
	{
		13,
		"Underground River",
		"You are in a dark room in the cave. You feel wind and water spraying your face\n"
		"as you stand beside an underground river. You see pale, blue lights coming from\n"
		"the south, accessible if you follow the river. A small passage opens to the\n"
		"east.",
		{-1,12,14,-1},
		{NULL,"You climb through the passage east.","You follow the river south.",NULL},
		NULL
	},
	{
		14,
		"Treasure Chamber",
		"You are in a room lined with strange, pale blue torches. There are piles of\n"
		"treasure, including hundreds of shiny gold coins, lining the room. The only way\n"
		"to leave is by following the river north.",
		{13,-1,-1,-1},
		{"You follow the river north.",NULL,NULL,NULL},
		"You search through the treasure piles."
	},
	{
		15,
		"Forest Outskirts",
		"You are at the edge of the forest. There is a grassy field to the west. The\n"
		"forest gets thicker to the north and to the east, but there is a path in both\n"
		"directions.",
		{16,21,-1,9},
		{"You walk north.","You walk east.",NULL,"You walk west."},
		NULL
	},
	{
		16,
		"Forest",
		"You are on a forest path. The path stretches both north and south, and there\n"
		"are fewer trees to the south. There is a dense thicket to the east that may be\n"
		"traversable.",
		{17,23,15,-1},
		{"You walk north.",
		"You walk east into the thicket and get lost in the forest for awhile.",
		"You walk south.",NULL},
		NULL
	},
	{
		17,
		"Near the Clearing",
		"You are on a path at the edges of the forest. There is a clearing to the north\n"
		"which appears to be full of stone columns. To the south, the forest is slightly\n"
		"more dense.",
		{18,-1,16,-1},
		{"You walk north.",NULL,"You walk south.",NULL},
		NULL
	},
	{
		18,
		"Clearing in Forest",
		"You are in a clearing in the forest. There are many stone podiums and columns in\n"
		"the area. The stone structures are lined with carved symbols, but you do not\n"
		"know what they mean. There is a path south that leads back into the woods.",
		{-1,-1,17,-1},
		{"You climb down the ladder and head north through the tunnel. At the end of the\n"
		"tunnel is another ladder, which emerges into another clearing in the forest.",
		NULL,"You walk south.",NULL},
		NULL
	},
	{
		19,
		"North Clearing",
		"You are in the middle of a clearing in the forest. There are several stone\n"
		"podiums in area. Each of the podiums have intricate carvings lining them. This\n"
		"must be a truly ancient area. There is a tunnel that leads south, and a path\n"
		"that leads back into the woods to the north.",
		{20,-1,18,-1},
		{"You walk north.",NULL,
		"You climb down the ladder and head south through the tunnel. At the end of the\n"
		"tunnel is another ladder, which emerges into another clearing in the forest.",
		NULL},
		"You check all the podiums."
	},
	{
		20,
		"Deep Forest",
		"You are walking on a forest path. The path runs south into a clearing. There are\n"
		"thick, impassable thickets north and south, and a steep rocky wall to the east.",
		{-1,-1,19,-1},
		{NULL,"You climb the ladder up the rockslide.","You walk south.",NULL},
		NULL
	},
	{
		21,
		"Forest Path",
		"You are walking through the forest. Dense underbrush is all around, but you are\n"
		"on a clear footpath that runs east and west.",
		{-1,22,-1,15},
		{NULL,"You walk east.",NULL,"You walk west."},
		NULL
	},
	{
		22,
		"Curve in the Forest Path",
		"You are walking along the forest path. To the north, the forest appears to be\n"
		"more dense. To the west, the forest is less dense.",
		{23,-1,-1,21},
		{"You walk north.",NULL,NULL,"You walk west."},
		NULL
	},
	{
		23,
		"The Familiar Copse",
		"You are walking along a path in the forest. The path runs north and south. The\n"
		"path is split in the middle by a grassy patch with four trees growing closely\n"
		"together.",
		{24,-1,22,-1},
		{"You walk north.",NULL,"You walk south.",NULL},
		NULL
	},
	{
		24,
		"Dark Forest",
		"You are in a dark portion of the forest where the trees are blocking out light\n"
		"from the sky. There is dense underbrush that makes it very hard to see through\n"
		"the trees, but there is a footpath that runs south and east.",
		{-1,-1,23,-1},
		{NULL,"You walk east.","You walk south.",NULL},
		NULL
	},
	{
		25,
		"Dark Forest",
		"You are on a path through the forest that runs west and north. The trees all\n"
		"around you are thick and hard to see through, and the air feels very still. You\n"
		"can't see anything east or south, only darkness.",
		{26,-1,-1,24},
		{"You walk north.",NULL,NULL,"You walk west."},
		NULL
	},
	{
		26,
		"Thicket Dead End",
		"You are walking in the forest. The forest path from the south seems to end here,\n"
		"with dense overgrowth in all other directions.",
		{27,23,25,17},
		{"You walk into the north thicket. You get lost in the forest for awhile, but the\n"
		"thicket clears and you find a the footpath again.",
		"You walk into the east thicket. You get lost in the forest for awhile.",
		"You walk south.",
		"You walk into the west thicket. You get lost in the forest for awhile."},
		NULL
	},
	{
		27,
		"Light Forest",
		"You are walking in a light section of the forest. The trees have thinned out\n"
		"here. To the south, you see a dense thicket of trees. A path leads to the north,\n"
		"where you see a mountain rising above the trees.",
		{28,-1,26,-1},
		{"You walk north.",NULL,"You walk south.",NULL},
		NULL
	},
	{
		28,
		"Light Forest Near the Tower",
		"You are walking along a forest path, which runs south and west from here. There\n"
		"is a mountain with small, carved alcoves that blocks the way to the north. The\n"
		"path leads west to a large tower to the west which leads up to a bluff at the\n"
		"top the mountain.",
		{-1,-1,27,29},
		{NULL,NULL,"You walk south.","You walk west."},
		"You inspect the inside of the alcoves."
	},
	{
		29,
		"Base of the Tower",
		"You are standing at the base of a large tower that leads to the top of the\n"
		"mountain bluff, which you can enter to the west. There are small, carved alcoves\n"
		"in the mountains to the north. A path leads into the forest to the east.",
		{-1,28,-1,-1},
		{NULL,"You walk east.",NULL,"You enter the tower and ascend the steps."},
		"You inspect the inside of the alcoves."
	},
	{
		30,
		"Bluff Overlooking the Forest",
		"You are at the top of a bluff at the northmost point of the forest. Looking\n"
		"around, you can see the entire forest, and to the west, you can see the small\n"
		"town. There is a rocky hill to the west, a twisting stone path to the north, and\n"
		"the entrance to a tower to the east.",
		{31,-1,-1,20},
		{"You walk north.","You enter the tower and descend the steps.",NULL,
		"You try to climb down the rocky hill, but quickly lose control and slide to the\n"
		"bottom! It was a little steeper than you thought."},
		NULL
	},
	{
		31,
		"Twisting Path",
		"You are walking on a twisting, cobblestone path that runs north and south. To\n"
		"the north, you see a giant stone gate. To the south is a tower and bluff that\n"
		"overlooks the forest.",
		{32,-1,30,-1},
		{"You walk north.",NULL,"You walk south.",NULL},
		NULL
	},
	{
		32,
		"The Stone Gate",
		"You are at the northmost part of a twisting cobblestone path. There is a giant\n"
		"stone gate that leads to the north. The gate looks old, like it was built many\n"
		"centuries ago.",
		{-1,-1,31,-1},
		{"You walk through the gate.",NULL,"You walk south.",NULL},
		NULL
	},
	{
		33,
		"Hidden Temple",
		"You enter an ancient temple. Tall stone walls rise up around you on all sides,\n"
		"no ceiling. There is a two-story tall gold bird-man statue beside the north wall.",
		{-1,-1,32,-1},
		{NULL,NULL,"You exit through the gate.",NULL},
		"You walk around the temple, look behind the throne, and even crawl between the\n"
		"statue's legs, looking for treasure."
	},
};
