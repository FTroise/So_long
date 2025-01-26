/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroise <ftroise@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 13:10:41 by ftroise           #+#    #+#             */
/*   Updated: 2023/06/08 13:10:45 by ftroise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_set(t_game *game)
{
	game->collect = 0;
	game->mv_count = 0;
	game->no_collect = 0;
	game->player_stats.x = 0;
	game->player_stats.y = 0;
	game->enemy_kill = 0;
	game->start = 0;
	game->enemy.mv = 0;
	game->enemy_num = 0;
	game->panel.strcd = 0;
	game->tile.c = 0;
	game->tile.e = 0;
	game->tile.empty = 0;
	game->tile.p = 0;
	game->enemy.x = 0;
	game->enemy.y = 0;
}

void	set_window(t_game *game)
{
	int	riga;
	int	colonna;

	riga = 0;
	colonna = 0;
	while (game->map[riga])
	{
		riga++;
		game->panel.strcd++;
	}
	game->width = riga * 64;
	riga = 0;
	while (game->map[0][colonna])
	{
		colonna++;
	}
	game->height = colonna * 64;
	colonna = 0;
}

static void	set_img(t_game *game)
{
	game->img_0 = mlx_xpm_file_to_image(game->mlx, "./img/espace.xpm",
			&game->width, &game->height);
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "./img/wall.xpm",
			&game->width, &game->height);
	if (game->start == 0)
		game->img_player = mlx_xpm_file_to_image(game->mlx, "./img/homer.xpm",
				&game->width, &game->height);
	if (game->collect > 0)
	{
		game->img_exit = mlx_xpm_file_to_image(game->mlx, "./img/exit.xpm",
				&game->width, &game->height);
	}
	if (game->collect == 0)
		game->img_exit = mlx_xpm_file_to_image(game->mlx, "./img/exit2.xpm",
				&game->width, &game->height);
	game->img_collect = mlx_xpm_file_to_image(game->mlx,
			"./img/donuts.xpm", &game->width, &game->height);
	game->img_enemy = mlx_xpm_file_to_image(game->mlx, "./img/burns.xpm",
			&game->width, &game->height);
}

void	check_img(t_game *game)
{
	set_img(game);
	if (!game->img_0 || !game->img_wall || !game->player_stats.idle
		|| !game->img_exit || !game->img_collect)
	{
		ft_printf("error image wasn't read correctly\n");
		exit(1);
	}
	game->start = 1;
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
}
