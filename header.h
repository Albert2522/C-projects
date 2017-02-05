#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>

typedef struct	s_shape
{
	char chr;
	int x[4];
	int y[4];
	int pos[2];
}		t_shape;
int count_shapes(char **str);
int count_max_size(int number_shapes);
t_shape *get_shape(char **str, int pos);
t_shape **set_struct(int number_shapes, char **str);
void    solution(char **str);
int     task_complete(int *indices, int number_shapes);
void    remove_shape(char **grid, t_shape *shape);
int     put_shape(char **grid, t_shape *shape, int size_of_grid, int *pos);
char    **set_grid(int size_of_grid);
void    print_answer(char **str);
char    **backtrack(char **grid, int *indices_shapes, t_shape **list_of_shapes, int number_shapes, int *pos);
int     *set_indices_shapes(int number_shapes);
void	print_grid(char **str);
int		get_number_of_shape(int *ind, int num_shapes);
int		shapes_available(int *ind, int num_shapes);
int	find_next_pos(int *pos, int size_of_grid, char **grid);
void check_structure(t_shape **list, int number_shapes);
#endif
