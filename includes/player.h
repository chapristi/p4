#ifndef PLAYER_H
#define PLAYER_H
typedef struct s_player
{
	char 	symbole;
	char	*name;

} t_player;

void free_player(t_player *player);
#endif