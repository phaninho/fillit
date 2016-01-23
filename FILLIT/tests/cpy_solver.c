#include "libft.h"
#include "fillit.h"

# define LIMIT 10
void	print_map(char map[LIMIT + 1][LIMIT + 1]);


void	check_insert(char map[LIMIT + 1][LIMIT + 1], t_tetris *tetris, int **step)
{
	int		i;
	int		j;
	int		k;
	int		valid[4];
	int		ref[4];
	int		col;
	int		row;
	int		save_j;
	int		flag;
	int		diff;
	char	*save[LIMIT + 1][LIMIT + 1];
	int		nb_bloc;

	i = 0;
	j = step[0][1];
	k = 0;
	col = 0;
	flag = 0;
	nb_bloc = 0;
	map[0][0] = 'A';
	map[0][1] = 'A';
	map[0][2] = 'A';
	map[1][3] = 'A';
	map[1][5] = 'A';
	map[3][2] = 'A';
	map[3][3] = 'A';
	map[3][4] = 'A';
	map[3][5] = 'A';
	map[3][6] = 'A';
	map[3][7] = 'A';
	map[3][8] = 'A';
	map[3][9] = 'A';
	map[4][0] = 'A';
	map[4][1] = 'A';
	map[5][2] = 'A';
	map[6][3] = 'A';
	map[6][4] = 'A';
	map[4][5] = 'A';
	map[4][6] = 'A';
	map[4][7] = 'A';
	map[4][8] = 'A';
	map[4][9] = 'A';
	ft_memset(valid, 0, sizeof(valid));
	ft_memset(ref, 1, sizeof(ref));
	ft_memcpy(save, map, (LIMIT + 1) * (LIMIT + 1) );
	row = 0;
	print_map(map);
	save_j = j;
	diff = 0;
	while (i < LIMIT)
	{
		flag = 0;
		if (j != 0)
			j= (j == diff + step[i % 4][1]) ? j++ : diff + step[i % 4][1];
		while (!flag && j < LIMIT)
		{
			if (k == 5)
				return ;
			if (map[i][j] == '.')
			{
				nb_bloc++;
				if (valid[0] == 0)
					diff = j - step[0][1];
				col++;
				if (valid[0] == 0)
				{
					row = i;
					save_j = j;
				}
				valid[k++] = 1;
				map[i][j] = 'o';
				if (nb_bloc == 4)
					break ;
				if (col >= step[i % 4][0])
				{
					col = 0;
					i++;
					if (valid[0] == 0)
						save_j = j;
					j= (j == diff + step[i % 4][1]) ? j++ : diff + step[i % 4][1];
					flag = 1;
				}
				else
					j++;
			}
			else
			{
				ft_memset(valid, 0, sizeof(valid));
				ft_memcpy(map, save, (LIMIT + 1)*(LIMIT + 1));
				printf("\n");
				k = 0;
				nb_bloc = 0;
				if (j < save_j)
					j = save_j ;
				j++;
				col = 0;
				i = row;
			}
		}
		if (k >= 4)
		{
			if (valid[0] == 1 && valid[1] == 1 && valid[2] == 1 && valid[3] == 1)
			{
				printf("placed !\n");
				print_map(map);\
				printf("\n");
				return ;
			}
			else
			{
				i++;
				j = 0;
			}
		}
		if (j == LIMIT)
		{
			i++;
			row = i;
			j = 0;
		}
	}
	printf("not placed !\n");
	print_map(map);
}

int		**diff_coord(t_tetris *tetris)
{
	int		i;
	int		**tab;

	if (!(tab = (int **)malloc(sizeof(int *) * 4)))
		return (NULL);
	i = 0;
	while (i < 4)
	{
		if (!(tab[i] = (int *)malloc(sizeof(int) * 2)))
			return (NULL);
		tab[i][0] = blk_in_line(tetris, i);
		tab[i][1] = (tab[i][0] == 0) ? 0 : get_minx(tetris, i);
		i++;
	}
	return (tab);
}

void	put_tetri(char map[LIMIT + 1][LIMIT + 1],t_tetris *tetris)
{
	int		**tab;
	int		i;

	i = 0;
	while (tetris)
	{
		tab = diff_coord(tetris);
		check_insert(map, tetris, tab);
		tetris = tetris->next;
	}
}

void	print_map(char map[LIMIT + 1][LIMIT + 1])
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < LIMIT )
	{
		j = 0;
		while (j < LIMIT)
		{
			printf("%c ", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	solver(t_tetris *tetris)
{
	char	map[LIMIT + 1][LIMIT + 1];

	ft_memset(map, '.', sizeof(map));
	put_tetri(map, tetris);
}
