#include "libft.h"
#include "fillit.h"

# define LIMIT 10
void	print_map(char map[LIMIT + 1][LIMIT + 1]);

static void check_position_form(int valid[4], int k, int *i, int *j)
{
	if (k >= 4)
	{
		if (valid[0] == 1 && valid[1] == 1 && valid[2] == 1 && valid[3] == 1)
		{
			printf("placed !\n");
			/* print_map(map);\ */
			printf("\n");
			return ;
		}
		else
		{
			*i = *i + 1;
			*j = 0;
		}
	}
}

static void	draw_map(char map[LIMIT + 1][LIMIT + 1])
{
	map[0][0] = 'x';
	map[0][1] = 'x';
	map[0][2] = 'x';
	map[0][4] = 'x';
	map[1][3] = 'x';
	map[1][5] = 'x';
	map[1][6] = 'x';
	map[3][2] = 'x';
	map[3][3] = 'x';
	map[3][4] = 'x';
	map[3][5] = 'x';
	map[3][6] = 'x';
	map[3][7] = 'x';
	map[3][8] = 'x';
	map[3][9] = 'x';
	map[4][0] = 'x';
	map[4][1] = 'x';
	map[5][2] = 'x';
	map[6][3] = 'x';
	map[6][4] = 'x';
	map[4][5] = 'x';
	map[4][6] = 'x';
	map[4][7] = 'x';
	map[4][8] = 'x';
	map[4][9] = 'x';
}

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
	static	char letter = 'A';

	i = 0;
	j = step[0][1];
	k = 0;
	col = 0;
	flag = 0;
	nb_bloc = 0;
	draw_map(map);
	ft_memset(valid, 0, sizeof(valid));
	ft_memset(ref, 1, sizeof(ref));
	ft_memcpy(save, map, (LIMIT + 1) * (LIMIT + 1) );
	row = 0;
	/* print_map(map); */
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
				printf("\ncol: %d\n", col);
				nb_bloc++;
				col++;
				if (valid[0] == 0)
				{
					diff = j - step[0][1];
					row = i;
					save_j = j;
				}
				valid[k++] = 1;
				map[i][j] = letter;
				if (nb_bloc == 4)
					break ;
				/* printf("j: %d []  j mod LIMIT: %d\n", j, (j % (LIMIT))); */
				if (nb_bloc <= step[i % 4][0] && j % LIMIT  == 9)
				{
					printf(RED"-- A --\n"NONE);
					print_map(map);
					ft_memset(valid, 0, sizeof(valid));
					ft_memcpy(map, save, (LIMIT + 1)*(LIMIT + 1));
					k = 0;
					nb_bloc = 0;
					j++;
					col = 0;
					/* i++; */
				}
				else if (col >= step[i % 4][0] && step[i % 4][0] != 0)
				{
					printf(GREEN"-- B --\n"NONE);
					print_map(map);
					col = 0;
					i++;
					if (valid[0] == 0)
						save_j = j;
					j= (j == diff + step[i % 4][1]) ? j++ : diff + step[i % 4][1];
					flag = 1;
				}
				else
				{
					printf(YELLOW"-- C --\n"NONE);
					print_map(map);
					j++;

				}
			}
			else
			{
				ft_memset(valid, 0, sizeof(valid));
				ft_memcpy(map, save, (LIMIT + 1)*(LIMIT + 1));
				k = 0;
				nb_bloc = 0;
				if (j < save_j)
					j = save_j ;
				j++;
				col = 0;
				i = row;
			}
		}
		// Passer la map
		check_position_form(valid, k, &i, &j);
		if (k >= 4)
		{
			if (valid[0] == 1 && valid[1] == 1 && valid[2] == 1 && valid[3] == 1)
			{
				printf("placed !\n");
				letter++;
				print_map(map);
				printf("\n");
				return ;
			}
			else
			{
				i++;
				j = 0;
				col = 0;
			}
		}
		if (j == LIMIT)
		{
			printf("HERE\n");
			if (nb_bloc != step[i % 4][0])
			{
				printf("NOOOOP\n");
				ft_memset(valid, 0, sizeof(valid));
				ft_memcpy(map, save, (LIMIT + 1)*(LIMIT + 1));
				k = 0;
				nb_bloc = 0;

			}
			i++;
			row = i;
			j = 0;
			col = 0;
		}
	}
	printf("not placed !\n");
	letter = 'A';
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
