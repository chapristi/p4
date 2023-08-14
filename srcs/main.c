/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 21:12:43 by marvin            #+#    #+#             */
/*   Updated: 2023/08/11 21:12:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "../includes/player.h"
#include "../includes/game.h"
#include "../includes/game_status.h"


void put_char(char c)
{
    write(1, &c, 1);
}

void    grid_gen(t_game *game)
{
	int i = -1;
    int j = -1;
    int z = -1;
    while (++i < game->columns)
    {
        put_char('+');
        while (++j < game->columns)
            write(1,"---+",4);
        if (i < game->rows)
        {
            write(1, "\n|", 2);
            while (++z < game->columns)
            {
                put_char(' ');
                if (!game->grid[i][z])
                    write(1, "  |", 3);
                else
                {
                	put_char(game->grid[i][z]);
                	write(1, " |" , 2);
                }
            }
           put_char('\n');
        }
        z = -1;
        j = -1;
    }
	put_char('\n');
   
}


int ft_check_win(t_game *game, t_game_status *game_status)
{
	int i = -1;
	int j = -1;
	unsigned char curr_symbole = game_status->current_player->symbole;
	while (++i < game->rows)
	{ 
		while (++j < (game->columns - 3))
		{ 
			if (game->grid[i][j] == curr_symbole && game->grid[i][j + 1] == curr_symbole
				&&game->grid[i][j + 2] == curr_symbole && game->grid[i][j + 3] == curr_symbole)
				return (1);
		}
		j = -1;
	}
	i = -1;
	while (++i < (game->rows - 3))
	{ 
		while (++j < game->columns)
		{ 
			if (game->grid[i][j] == curr_symbole && game->grid[i+1][j] == curr_symbole
				&& game->grid[i+2][j] == curr_symbole && game->grid[i+3][j] == curr_symbole)
				return (1);
		}
		j = -1;
	}
	i = -1;
	while (++i < game->rows)
	{ 
		while (++j < game->columns)
		{ 
			if (j >= 4 && i >= 4 && game->grid[i][j] == curr_symbole && game->grid[i-1][j-1] == curr_symbole
				&& game->grid[i-2][j-2] == curr_symbole && game->grid[i-3][j-3] == curr_symbole)
				return (1);
			if (j <= 4 && i <= 3 && game->grid[i][j] == curr_symbole && game->grid[i+1][j+1] == curr_symbole
				&& game->grid[i+2][j+2] == curr_symbole && game->grid[i+3][j+3] == curr_symbole)
				return (1);
		}
		j = -1;
	}
	return (0);
}


void	ft_play(unsigned int column, t_game *game, t_game_status *game_status)
{
    int i = game->rows;
	while (--i >= 0)
	{
		if (!game->grid[i][column - 1])
		{
			if (game_status->current_player == game_status->player1)
				game->grid[i][column - 1] =  game_status->current_player->symbole;
			else
				game->grid[i][column - 1] = game_status->current_player->symbole;
			return;
		}
	}
}

int	check_entries(int column)
{
	if (column >= 1 && column <= 7)
		return (1);
	return (0);
}

int main(void)
{
	int column;
	unsigned int is_finish;
  	t_game_status *game_status = malloc(sizeof(t_game_status));
	t_game *game = malloc(sizeof(t_game));
    t_player *player1 = malloc(sizeof(t_player));
    t_player *player2 = malloc(sizeof(t_player));
	game_status_init(game_status, player1, player2);
	game_init(game);	
	grid_gen(game);
	printf("vous jouerez sur cette grille :\n\n");
	while (!is_finish)
	{
		printf("entrez une colonne joueur %c", game_status->current_player->symbole);
		scanf("%d", &column);
		if (!check_entries(column))
			continue;
		ft_play(column, game, game_status);
		grid_gen(game);
		if(!ft_check_win(game, game_status))
			change_current_player(game_status);
		else
			is_finish = 1;
	}
	printf("le joueur %c a gagne", game_status->current_player->symbole);
	ft_game_free(game);
	free_game_status(game_status);	
}