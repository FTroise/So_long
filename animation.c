/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroise <ftroise@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:02:29 by francescotr       #+#    #+#             */
/*   Updated: 2023/05/25 17:15:11 by ftroise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_frame(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	game->x = 0;
	while (game->map[++i] != NULL)
	{
		j = -1;
		game->y = 0;
		while (game->map[i][++j] != '\0')
		{
			if (game->map[i][j] == 'S')
				mlx_put_image_to_window(game->mlx, game->win, game->img_enemy,
					game->y, game->x);
			game->y += 64;
		}
		game->x += 64;
	}
}

int	animation_loop(t_game *game)
{
	horizontal(game);
	print_frame(game);
	return (0);
}
