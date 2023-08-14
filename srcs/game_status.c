#include "../includes/player.h"
#include "../includes/game_status.h"
#include <stdlib.h>

void	game_status_init(t_game_status *game_status, t_player *player1, t_player *player2)
{
	player1->symbole = 'x';
	player2->symbole = 'o';
	game_status->player1 = player1;
	game_status->player2 = player2;
	game_status->current_player = player1;
}

void	change_current_player(t_game_status *game_status)
{
	if (game_status->current_player == game_status->player1)
		game_status->current_player = game_status->player2;
	else
		game_status->current_player = game_status->player1;
}

void	free_game_status(t_game_status *game_status)
{
    free_player(game_status->player1);
    free_player(game_status->player2);
    free(game_status);
}