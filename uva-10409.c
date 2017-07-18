
#include <stdio.h>

struct Dice
{
	int up, down, north, east, south, west;
};
struct Dice d;

int main()
{
	int n, i;
	char str[10];
	while (scanf("%d", &n) == 1 && n)
	{
		d.up = 1, d.down = 6, d.north = 2,
			d.east = 4, d.south = 5, d.west = 3;

		while (n--)
		{
			scanf("%s", str);
			if (strcmp(str,"south") == 0) 
				d.south = d.up, d.up = d.north,
				d.down = 7 - d.up, d.north = 7 - d.south;
			if (strcmp(str, "north") == 0) 
				d.down = d.north, d.north = d.up,
				d.up = 7 - d.down, d.south = 7 - d.north;
			if (strcmp(str, "west") == 0)
				d.down = d.west, d.west = d.up,
				d.up = 7 - d.down, d.east = 7 - d.west;
			if (strcmp(str, "east") == 0)
				d.east = d.up, d.up = d.west,
				d.down = 7 - d.up, d.west = 7 - d.east;
		}
		printf("%d\n", d.up);
	}

	return 0;
}
