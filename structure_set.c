#include "header.h"

int	count_shapes(char **str)
{
	int i;
	int counter;

	i = 0;
	counter = 0;
	while (str[i])
	{
		if (strcmp(str[i], "\n") == 0)
			counter++;
		i++;
	}
	return (counter + 1);		
}

int	*set_indices_shapes(int number_shapes)
{
	int i = 0;
	int *arr;

	arr = (int *)malloc(sizeof(int) * number_shapes);
	while (i < number_shapes)
	{
		arr[i] = 1;
		i++;
	}
	return (arr);	
}

int	count_max_size(int number_shapes)
{
	int counter = number_shapes;
	int i = 2;

	counter *= 4;
	while (i * i <= counter)
		i++;
	return(i);
}

t_shape	*get_shape(char **str, int pos)
{
	int j;
	int i = 0;
	int stop_point = pos + 4;
	int k = 0;
	t_shape	*shape;

    printf("SHAPE");
	shape = (t_shape *)malloc(sizeof(t_shape));
	while (str[pos] && pos < stop_point)
	{
        printf("%s\n", str[i]);
		j = 0;
		while(j < 4)
		{
			if (str[i][j] == '#')
			{
				shape->x[k] = i;
				shape->y[k] = j;
			}
			j++;
		}
		i++;
	}
	shape->pos[0] = 0;
	shape->pos[1] = 0;
	return (shape);
}

t_shape	**set_struct(int number_shapes, char **str)
{
	t_shape **array_shapes;
	int		i;
	int pos = 0;
	char index = 'A';

	array_shapes = (t_shape **)malloc(sizeof(t_shape *) * number_shapes);
	i = 0;
	while (i < number_shapes)
	{
		array_shapes[i] = get_shape(str, pos);
		array_shapes[i]->chr = index++;
		while (str[pos] && strcmp(str[pos],"\n") != 0)
			pos++;
		pos++;
		i++;	
	}
	return (array_shapes);
}
