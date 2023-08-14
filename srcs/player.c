#include "../includes/player.h"
#include <stdlib.h>

void free_player(t_player *player) 
{
    free(player->name);
    free(player);
}