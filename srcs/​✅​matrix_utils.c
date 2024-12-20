/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 09:24:05 by hhecquet          #+#    #+#             */
/*   Updated: 2024/12/13 10:27:57 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mlx.h"
#include "../includes/fdf.h"
#include <math.h>

static t_point3D	*get_rotor_x(t_matrix matrix)
{
	t_point3D	*rotor;
	
	rotor = (t_point3D *)malloc(sizeof(t_point3D) * 3);
	if (!rotor)
		return (NULL);
	rotor[0].x = 1;
	rotor[0].y = 0;
	rotor[0].z = 0;
	rotor[1].x = 0;
	rotor[1].y = cos(matrix.rot_x);
	rotor[1].z = -sin(matrix.rot_x);
	rotor[2].x = 0;
	rotor[2].y = sin(matrix.rot_x);
	rotor[2].z = cos(matrix.rot_x);
	return (rotor);
}

static t_point3D	*get_rotor_y(t_matrix matrix)
{
	t_point3D	*rotor;
	
	rotor = (t_point3D *)malloc(sizeof(t_point3D) * 3);
	if (!rotor)
		return (NULL);
	rotor[0].x = cos(matrix.rot_y);
	rotor[0].y = 0;
	rotor[0].z = sin(matrix.rot_y);
	rotor[1].x = 0;
	rotor[1].y = 1;
	rotor[1].z = 0;
	rotor[2].x = -sin(matrix.rot_y);
	rotor[2].y = 0;
	rotor[2].z = cos(matrix.rot_y);
	return (rotor);
}

static t_point3D	*get_rotor_z(t_matrix matrix)
{
	t_point3D	*rotor;
	
	rotor = (t_point3D *)malloc(sizeof(t_point3D) * 3);
	if (!rotor)
		return (NULL);
	rotor[0].x = cos(matrix.rot_z);
	rotor[0].y = -sin(matrix.rot_z);
	rotor[0].z = 0;
	rotor[1].x = sin(matrix.rot_z);
	rotor[1].y = cos(matrix.rot_z);
	rotor[1].z = 0;
	rotor[2].x = 0;
	rotor[2].y = 0;
	rotor[2].z = 1;
	return (rotor);
}


void free_rotor_matrix(t_point3D **rotor)
{
    if (rotor)
    {
        for (int i = 0; i < 3; i++)
        {
            if (rotor[i])
                free(rotor[i]);
        }
        free(rotor);
    }
}

t_point3D	**get_rotor_matrix(t_matrix matrix)
{
	t_point3D	**rotor;
	
	rotor = (t_point3D **)malloc(sizeof(t_point3D *) * 3);
	if (!rotor)
		return (NULL);
	rotor[0] = get_rotor_x(matrix);
	rotor[1] = get_rotor_y(matrix);
	rotor[2] = get_rotor_z(matrix);
	if (!rotor[0] || !rotor[1] || !rotor[2])
		return (free_rotor_matrix(rotor), NULL);
	return (rotor);
}

