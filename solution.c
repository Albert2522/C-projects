#include "header.h"

char	**set_grid(int size_of_grid)
{
	int i = 0;
	int j = 0;
	char **grid;
	
	grid = (char **)malloc(sizeof(char *) * size_of_grid + 1);
	while (i < size_of_grid)
	{
		grid[i] = (char *)malloc(sizeof(char) * size_of_grid + 1);
		j = 0;
		while (j < size_of_grid)
		{
			grid[i][j] = '.';
			j++;
		}
		grid[i][j] = '\0';	
		i++;
	}
	grid[i] = NULL;
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

void	print_ind_shapes(int *ind, int num_shapes)
{
	int i;

	i = 0;
	while (i < num_shapes)
	{
		printf("%d ", ind[i]);
		i++;
	}
	printf("\n");
}

char	**backtrack(char **grid, int *indices_shapes, t_shape **list_of_shapes, int number_shapes, int *pos)
{
	int k = 0;
	t_shape *current_shape;
	int size_of_grid = 0;
	int valid;
	int has_next_pos;

	while (grid[size_of_grid])
		size_of_grid++;
	print_ind_shapes(indices_shapes, number_shapes);
	printf("size of grid inside backtrack - %d , number_shapes - %d\n", size_of_grid, number_shapes);
	while (1)
	{
		if (shapes_available(indices_shapes, number_shapes) == 0)
		{
			print_grid(grid);
			return (NULL);
		}
		k = get_number_of_shape(indices_shapes, number_shapes);
		if (indices_shapes[k] == 1)
		{
			indices_shapes[k] = 0;
			current_shape = list_of_shapes[k];
			valid = put_shape(grid, current_shape, size_of_grid, pos);
			has_next_pos = find_next_pos(pos, size_of_grid, grid);
			if (valid && has_next_pos)
			{
				if (task_complete(indices_shapes, number_shapes))
					return (grid);
				backtrack(grid, indices_shapes, list_of_shapes, number_shapes, pos);
				print_grid(grid);
				remove_shape(grid, current_shape);
				indices_shapes[k] = 1;

			}
		}
	}
	return (NULL);
}

void	print_grid(char **str)
{
	int i;
	int j;

	i = 0;
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
	//check_structure(list_of_shapes, number_shapes);
    answer = NULL;
	pos[0] = 0;
	pos[1] = 0;
	int q = 0;
    grid = set_grid(size_of_grid);
    while (q < 10 && answer == NULL)
    {
		printf("\n size of grid - %d \n", size_of_grid); 
        grid = set_grid(size_of_grid);
        answer = backtrack(grid, indices_shapes, list_of_shapes, number_shapes, pos);
		pos[0] = 0;
		pos[1] = 0;
        size_of_grid++;
		q++;
    }
    //print_answer(answer);
}
