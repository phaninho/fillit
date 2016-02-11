#include "libit.h"

void	usage_error(int ac)
{
	if (ac == 1)
	{
		ft_putstr("fillit: operande de fichier manquant\nSaisissez «./fillit tetriminos_fille»\nSaisissez «./fillit --beautiful-map tetriminos_file» pour afficher la map en couleur\n");
		exit (1);
	}
}
