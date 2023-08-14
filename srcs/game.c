#include "../includes/game.h"
#include <stdlib.h>

void game_init(t_game *game)
{
	int i = -1;
	game->rows = 6;
	game->columns = 7;
	game->grid = calloc(game->rows, sizeof(char *));
	while (++i < game->rows)
		game->grid[i] = calloc(game->columns, sizeof(char));
}

void ft_game_free(t_game *game)
{
	int i = -1;
	while (++i < game->rows)
		free(game->grid[i]);
	free(game->grid);
	free(game);
}