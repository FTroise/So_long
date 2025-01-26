/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroise <ftroise@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:51:55 by ftroise           #+#    #+#             */
/*   Updated: 2023/05/25 13:35:46 by ftroise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_printf("Error\nYou didn't put he map as an argument\n");
		exit(1);
	}
	game.map = read_map(argv[1], &game);
	game_set(&game);
	if (check_all(&game) == 1)
		return (0);
	game.mlx = mlx_init();
	set_window(&game);
	game.win = mlx_new_window(game.mlx, game.height, game.width, "So_long");
	check_img(&game);
	draw_map(&game);
	mlx_loop_hook(game.mlx, animation_loop, &game);
	mlx_key_hook(game.win, key_pressed, &game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_loop(game.mlx);
	free(game.mlx);
}
