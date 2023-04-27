#include "shell.h"

/**
 *_grid - Free the allocated memory used in the last excercise
 *@grid: pointer to grid
 *@altitude: heigth of the grid
 */
void _grid(char **grid, int altitude)
{

	int i = 0;

	if (grid == NULL)
		return;

	while (i < altitude)
	{
		free(grid[i]);
		i++;
	}
}
