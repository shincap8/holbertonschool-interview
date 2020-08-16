#include "sandpiles.h"

/**
* print_sand - prints the grid
* @grid: grid to print
*/
void print_sand(int grid[3][3])
{
	int i, j;

	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}
/**
* grid_reset - reset the grid
* @grid: grid to reset
*/
void grid_reset(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid[i][j] = 0;
		}
	}
}
/**
* grid_sum - prints the grid
* @grid1: grid to print
* @grid2: grid to print
*/
void grid_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}
}
/**
* sandpiles_sum - computes the sum of two sandpiles
* @grid1: first grid
* @grid2: second grid
*/
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int unstable = 0, i = 0, j;
	int grid3[3][3] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};

	while (unstable || i < 3)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
			if (grid1[i][j] > 3)
			{
				unstable = 1;
				grid2[i][j] = -4;
				if (i > 0)
					grid3[i - 1][j] += 1;
				if (i < 2)
					grid3[i + 1][j] += 1;
				if (j > 0)
					grid3[i][j - 1] += 1;
				if (j < 2)
					grid3[i][j + 1] += 1;
			}
			else
			{
				grid2[i][j] = 0;
			}
		}
		i++;
		if (i == 3 && unstable)
		{
			print_sand(grid1);
			grid_sum(grid2, grid3);
			grid_reset(grid3);
			i = 0, unstable = 0;
		}
	}
}


