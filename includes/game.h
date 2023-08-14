#ifndef GAME_H
#define GAME_H
typedef struct s_game
{
	int rows;
    int columns;
	char **grid;
} t_game;

void ft_game_free(t_game *game);
void game_init(t_game *game);
#endif