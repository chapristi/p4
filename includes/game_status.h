#ifndef GAME_STATUS_H
#define GAME_STATUS_H

#include "player.h"

typedef struct s_game_status
{
	t_player	*player1;
	t_player	*player2;
	t_player	*current_player;
} t_game_status;

void game_status_init(t_game_status *game_status, t_player *player1, t_player *player2);
void change_current_player(t_game_status *game_status);
void free_game_status(t_game_status *game_status);
#endif