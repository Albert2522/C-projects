#include "header.h"

char	**set_grid(int size_of_grid)
{
	int i = 0;
	int j = 0;
	char **grid;
	
	grid = (char **)malloc(sizeof(char *) * size_of_grid);
	while (i < size_of_grid)
	{
		grid[i] = (char *)malloc(sizeof(char) * size_of_grid);
		j = 0;
		while (j < size_of_grid)
		{
			grid[i][j] = '.';
			j++;
		}	
		i++;
	}
	return (grid);
}

void	print_answer(char **str)
{
	int i = 0;
	int j = 0;
	
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			printf("%c", str[i][j]);
			j++;
		}
		printf("%c", '\n');
		i++;
	}
}

char	**backtrack(char **grid, int *indices_shapes, t_shape **list_of_shapes, int number_shapes, int *pos)
{
	int k = 0;
	t_shape *current_shape;
	int i = pos[0];
	int j = pos[1];
	int size_of_grid = 0;
	int valid;

	while (grid[size_of_grid])
		size_of_grid++;
	while (k < number_shapes)
	{
		if (indices_shapes[k] == 1)
		{
			indices_shapes[k] = 0;
			current_shape = list_of_shapes[k];
			valid = put_shape(grid, current_shape, size_of_grid, i, j);
			if (valid)
			{
				if (task_complete(indices_shapes, number_shapes))
					return (grid);
				backtrack(grid, indices_shapes, list_of_shapes, number_shapes, pos);
				remove_shape(grid, current_shape);
			}
			indices_shapes[k] = 1;
		}
		k++;
	}
	return (NULL);
}

void	solution(char **str)
{
	int number_shapes;
    int size_of_grid;
	t_shape	**list_of_shapes;
    char **grid;
    char **answer;
	int *indices_shapes;
	int *pos;

	pos = (int *)malloc(sizeof(int) * 2);
	number_shapes = count_shapes(str);
	indices_shapes = set_indices_shapes(number_shapes);
	list_of_shapes = set_struct(number_shapes, str);
	size_of_grid = count_max_size(number_shapes);
    answer = NULL;
	pos[0] = 0;
	pos[1] = 0;
    while (answer == NULL)
    {
        grid = set_grid(size_of_grid);
        answer = backtrack(grid, indices_shapes, list_of_shapes, number_shapes, pos);
        size_of_grid++;
    }
    print_answer(answer);
}
