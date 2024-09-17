# include "Cub3D.h"

void	error_hanlder(int set)
{
	if (set > 1)
		ft_putstr_fd(RED"Error:\n", 2);
	if (set == 1)
		ft_putstr_fd(YLW"Usage: "RST"./Cub3d <filename.ber>\n", 2);
	else if (set == 2)
		ft_putstr_fd(RST"Input must have "YLW"\".cub\""RST" extension.\n", 2);
	else if (set == 3)
		ft_putstr_fd(YLW"<file>"RST" <-not found->\n", 2);
	else if (set == 4)
		ft_putstr_fd(RST"Invalid "YLW"<Map>"RST"\n", 2);
	else
		perror(RED"Error"RST);
	exit(EXIT_FAILURE);
}
