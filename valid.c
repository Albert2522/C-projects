/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcornea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 18:57:36 by alcornea          #+#    #+#             */
/*   Updated: 2017/01/27 18:57:52 by alcornea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#define BUF_SIZE 1000

int        ft_array(const char *s, char c)
{
    int     count;
    int     i;
    int     g_boxes;
    
    i = 0;
    count = 0;
    while (s[i] != '\0')
    {
        if (s[i] == c)
            count++;
        i++;
    }
    printf("%d\n", count);
    return (count);
}

char    *ft_strsub(char const *s, unsigned int start, size_t len)
{
    char    *str;
    size_t    i;
    
    if (s)
    {
        i = 0;
        if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
            return (NULL);
        while (start--)
            s++;
        while (i < len && s[i] != '\0')
        {
            str[i] = s[i];
            i++;
        }
        str[i] = '\0';
        return (str);
    }
    return (NULL);
}

char    **ft_strsplit(char const *s, char c)
{
    char    **t;
    int        nb_block;
    int        i;
    
    if (s)
    {
        i = 0;
        nb_block = ft_array((const char *)s, c);
        if (!(t = (char **)malloc(sizeof(*t) * (nb_block + 1))))
            return (NULL);
        while (nb_block--)
        {
            if (!(t[i] = ft_strsub((const char *)s, 0, 21)))
                return (NULL);
            s = s + 21;
            i++;
        }
        t[i] = NULL;
        return (t);
    }
    return (0);
}

int		check_char(char *str)
{
    int i;
    int hash;
    int dot;
    int endl;
    
    i = 0;
    hash = 0;
    dot = 0;
    endl = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '#')
            hash++;
        if (str[i] == '.')
            dot++;
        if (str[i] == '\n')
            endl++;
        i++;
    }
    
    if (hash % 4 == 0 && dot % 12 == 0 && endl % 5 == 0)
        return (1);
    else
        return (0);
}

int		check_line(char *str)
{
    int i;
    int j;
    int add;
    
    i = 0;
    j = 0;
    add = 4;
    while (str[i] != '\0')
    {
        if (str[i] == '.' || str[i] == '#')
            j++;
        if (j > 4)
            return (0);
        if (str[i] == '\n' && i == add)
        {
            j = 0;
            add += 5;
        }
        i++;
    }
    return (1);
}

int count_shape(char *str)
{
    int hash;
    int i;
    int j;
    
    j = 0;
    i = 0;
    hash = 0;
    while (str[i])
    {
        if (str[i] == '#')
        {
            
            if(str[i + 1] == '#' || str[i - 1] == '#' ||\
               str[i + 5] == '#' || str[i - 5] == '#')
                hash++;
            if (hash % 4 == 0)
                return (1);
        }
        i++;
    }
    return (0);
    
}

int		width_shape(char *str)
{
    int i;
    int width;
    int line;
    
    i = 0;
    width = 0;
    line = 0;
    while (i < 4)
    {
        if (str[i] == '#' || str[i + 5] == '#' || str[i + 10] == '#' ||\
            str[i + 15] == '#')
        {
            width++;
            if (line > 0)
                return (0);
        }
        else if (width > 0)
            line++;
        i++;
    }
    return (width);
}

int		height_shape(char *str)
{
    int i;
    int height;
    int line_void;
    
    i = 0;
    height = 0;
    line_void = 0;
    while (i < 19)
    {
        if (str[i] == '#' || str[i + 1] == '#' || str[i + 2] == '#' ||\
            str[i + 3] == '#')
        {
            height++;
            if (line_void > 0)
                return (0);
        }
        else if (height > 0)
            line_void++;
        i = i + 5;
    }
    return (height);
}

int		check_shape(char *str)
{
    int height;
    int width;
    
    width = width_shape(str);
    height = height_shape(str);
    while (count_shape(str) != 0)
    {
        if (width == 0 || height == 0)
            return (0);
        if (height == 2 && width == 2)
            return (1);
        else if (height == 2 && width == 3)
            return (1);
        else if (height == 3 && width == 2)
            return (1);
        else if (height == 1 && width == 4)
            return (1);
        else if (height == 4 && width == 1)
            return (1);
        else
            return (0);
    }
    str++;
    return(0);
}


int		check(char *str)
{
    
    if (check_line(str) != 1)
    {
        printf("1 - check line%d\n", check_line(str));
        return (0);
    }
    if (check_shape(str) != 1)
    {
        printf("2 - check shape%d\n", check_shape(str));
        return (0);
    }
    if (check_char(str) != 1)
    {
        printf("3 - check char %d\n", check_char(str));
        return (0);
    }
    else
        return (1);
}

char	*get_word(char *str, int start_index, int stop_index)
{
	char *str1;
	int size;
	int i;

	size = stop_index - start_index;
	str1 = (char *)malloc(sizeof(char) * size + 1);
	i = 0;
	while (i < size)
	{
		str1[i] = str[start_index];
		start_index++;
		i++;
	}
	str1[i] = '\0';
	return (str1);
}

char	**str_split(char *str, char c)
{
	char **answer;
	int i;
	int counter;
	int j;
	int tmp;

	i = 0;
	counter = 0;
	while (str[i])
	{
		if (str[i] == c)
			counter++;
		i++;
	}
	printf("counter %d", counter);
	answer = (char **)malloc(sizeof(char *) * counter + 1);
	i = 0;
	j = 0;
	while (str[i])
	{	tmp = i;
		while (str[i] && str[i] != c)
			i++;
		/*if (i == tmp)
			i++;*/
		if (i == tmp)
			tmp--;
		answer[j] = get_word(str, tmp, i);
		j++;
		i++;
	}
	return (answer);
}

int main(int argc, char **argv)
{
    char **str;
    int fd;
    int i;
    int ret;
    char buf[BUF_SIZE + 1];
    
    i = 0;
    if (argc == 2)
    {
        fd = open(argv[1], O_RDONLY);
        if (fd == -1)
        {
            printf("open() failed\n");
            return(1);
        }
        ret = read(fd, buf, BUF_SIZE);
        buf[++ret] = '\0';
	//printf ("%s", buf);
	//printf("________________");
        if (close(fd) == -1)
        {
            printf("close() error");
            return(1);
        }
        // printf ("%s\n", buf);
        //str = (char**)malloc(sizeof(char*) + 100);
        str = str_split(buf, '\n');
        /*while (str[i])
        {
            if (check(str[i]) == 0)
            {
                printf("%d\n", i);
		return(0);
                printf("error\n");
            }
            else 
            {
                printf("%s", str[i]);
            }
            i++;
        }*/
	    i = 0;
        while (str[i])
        {
            //printf("comparing with new line %d\n", strcmp(str[i], "\n"));
            //printf("%s\n", "start");
            printf("%s\n", str[i]);
            //printf("%s\n", "end");
            i++;
        }
        printf("ASDFGFSA\n");
        solution(str);
    }
	return(0);
}
