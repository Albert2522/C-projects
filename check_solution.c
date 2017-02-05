#include "header.h"

int	task_complete(int *indices, int number_shapes)
{
	int i = 0;

	while (i < number_shapes)
	{
		if (indices[i] == 1)
			return (0);
		i++;
	}
	return (1);
}

void	remove_shape(char **grid, t_shape *shape)
{
	int i = shape->pos[0];
	int j = shape->pos[1];
	int k = 1;
	int i1;
	int j1;

	grid[i][j] = '.';
	while (k < 4)
	{
		i1 = i + shape->x[k] - shape->x[0];
		j1 = j + shape->y[k] - shape->y[0];
		grid[i][j] = '.';
		k++;
	}
}

int	put_shape(char **grid, t_shape *shape, int size_of_grid, int i, int j)
{
	int k = 1;
	int i1;
	int j1;
	
	while (k < 4)
	{
		i1 = i + shape->x[k] - shape->x[0];
		j1 = j + shape->y[k] - shape->y[0];
		if (i1 >= size_of_grid || j1 >= size_of_grid || grid[i1][j1] != '.')
			return (0);
		k++;
	}
	grid[i][j] = shape->chr;
	k = 1;
	while (k < 4)
	{
		i1 = i + shape->x[k] - shape->x[0];
		j1 = j + shape->y[k] - shape->y[0];
		grid[i1][j1] = shape->chr;		
		k++;
	}
	shape->pos[0] = i;
	shape->pos[1] = j;
	return (1);
}
