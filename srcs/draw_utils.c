/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 09:21:24 by hhecquet          #+#    #+#             */
/*   Updated: 2024/12/13 13:55:42 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mlx.h"
#include "../includes/fdf.h"

void	draw_color_order(t_fdf *prog)
{
	mlx_string_put(prog->mlx, prog->win, 360, 35, 0xFFFFFF, "1: White");
	mlx_string_put(prog->mlx, prog->win, 360, 48, 0xFFFFFF, "2: Green");
	mlx_string_put(prog->mlx, prog->win, 360, 61, 0xFFFFFF, "3: Red");
	mlx_string_put(prog->mlx, prog->win, 360, 74, 0xFFFFFF, "4: Blue");
	mlx_string_put(prog->mlx, prog->win, 360, 87, 0xFFFFFF, "5: Yellow");
	mlx_string_put(prog->mlx, prog->win, 360, 100, 0xFFFFFF, "6: Pink");
	mlx_string_put(prog->mlx, prog->win, 360, 113, 0xFFFFFF, "7: Grey");
	draw_carre(prog, get_tpoint(345, 28), 9, 0xFFFFFF);
	draw_carre(prog, get_tpoint(345, 41), 9, 0x00FF00);
	draw_carre(prog, get_tpoint(345, 54), 9, 0xFF0000);
	draw_carre(prog, get_tpoint(345, 67), 9, 0x0000FF);
	draw_carre(prog, get_tpoint(345, 80), 9, 0xFFFF00);
	draw_carre(prog, get_tpoint(345, 93), 9, 0xFF00FF);
	draw_carre(prog, get_tpoint(345, 106), 9, 0x808080);
}

void	draw_order(t_fdf *prog)
{
    if (!prog || !prog->mlx || !prog->win) // Check for NULL pointers
        return;

    draw_rectangle(prog, get_tpoint(0, 0), get_tpoint(prog->width, ((t_mlx *)(prog->mlx))->pos.y), 0x151515);
    mlx_string_put(prog->mlx, prog->win, 10, 20, 0xFFFFFF, "FDF - Controls");
    mlx_string_put(prog->mlx, prog->win, 20, 35, 0xFFFFFF, "Left click: rotate");
    mlx_string_put(prog->mlx, prog->win, 20, 48, 0xFFFFFF, "Right click: rotate");
    mlx_string_put(prog->mlx, prog->win, 20, 61, 0xFFFFFF, "Mouse wheel: zoom");
    mlx_string_put(prog->mlx, prog->win, 20, 74, 0xFFFFFF, "+/-: zoom view");
    mlx_string_put(prog->mlx, prog->win, 20, 87, 0xFFFFFF, "I: isometric view");
    mlx_string_put(prog->mlx, prog->win, 20, 100, 0xFFFFFF, "T: trimetric view");
    mlx_string_put(prog->mlx, prog->win, 20, 113, 0xFFFFFF, "R: dimetric view");
    draw_color_order(prog);
}


