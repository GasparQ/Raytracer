/*
** perlin2.c for other perlin in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtracer
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Sun Jun  7 16:27:04 2015 quentin gasparotto
** Last update Sun Jun  7 17:52:31 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

int	p[256] = {151, 160, 137, 91, 90, 15, 131, 13, 201, 95, 96,
		  53, 194, 233, 7, 225, 140, 36, 103, 30, 69, 142,
		  8, 99, 37, 240, 21, 10, 23, 190, 6, 148, 247,
		  120, 234, 75, 0, 26, 197, 62, 94, 252, 219, 203,
		  117, 35, 11, 32, 57, 177, 33, 88, 237, 149, 56,
		  87, 174, 20, 125, 136, 171, 168, 68, 175, 74, 165,
		  71, 134, 139, 48, 27, 166, 77, 146, 158, 231, 83,
		  111, 229, 122, 60, 211, 133, 230, 220, 105, 92, 41,
		  55, 46, 245, 40, 244, 102, 143, 54, 65, 25, 63, 161,
		  1, 216, 80, 73, 209, 76, 132, 187, 208, 89, 18, 169,
		  200, 196, 135, 130, 116, 188, 159, 86, 164, 100,
		  109, 198, 173, 186, 3, 64, 52, 217, 226, 250, 124,
		  123, 5, 202, 38, 147, 118, 126, 255, 82, 85, 212,
		  207, 206, 59, 227, 47, 16, 58, 17, 182, 189, 28, 42,
		  223, 183, 170, 213, 119, 248, 152, 2, 44, 154, 163,
		  70, 221, 153, 101, 155, 167, 43, 172, 9, 129, 22,
		  39, 253, 19, 98, 108, 110, 79, 113, 224, 232, 178,
		  185, 112, 104, 218, 246, 97, 228, 251, 34, 242, 193,
		  238, 210, 144, 12, 191, 179, 162, 241, 81, 51, 145,
		  235, 249, 14, 239, 107, 49, 192, 214, 31, 181, 199,
		  106, 157, 184, 84, 204, 176, 115, 121, 50, 45, 127,
		  4, 150, 254, 138, 236, 205, 93, 222, 114, 67, 29,
		  24, 72, 243, 141, 128, 195, 78, 66, 215, 61, 156,
		  180};

void	init_gradient(float gradient[8][2], float unit)
{
  gradient[0][0] = unit;
  gradient[0][1] = unit;
  gradient[1][0] = -unit;
  gradient[1][1] = unit;
  gradient[2][0] = unit;
  gradient[2][1] = -unit;
  gradient[3][0] = -unit;
  gradient[3][1] = -unit;
  gradient[4][0] = 1;
  gradient[4][1] = 0;
  gradient[5][0] = -1;
  gradient[5][1] = 0;
  gradient[6][0] = 0;
  gradient[6][1] = 1;
  gradient[7][0] = 0;
  gradient[7][1] = -1;
}

double		lets_calculate(float gradient2[8][2], t_vector2 coord,
			       int g[4])
{
  double	param[4];
  t_vector2	tmp;
  t_vector2	c_coord;
  double	val[3];

  tmp.x = coord.x - (int)coord.x;
  tmp.y = coord.y - (int)coord.y;
  param[0] = gradient2[g[0]][0] * tmp.x + gradient2[g[0]][1] * tmp.y;
  tmp.x = coord.x - ((int)coord.x + 1);
  tmp.y = coord.y - (int)coord.y;
  param[1] = gradient2[g[1]][0] * tmp.x + gradient2[g[1]][1] * tmp.y;
  tmp.x = coord.x - (int)coord.x;
  tmp.y = coord.y - ((int)coord.y + 1);
  param[2] = gradient2[g[2]][0] * tmp.x + gradient2[g[2]][1] * tmp.y;
  tmp.x = coord.x - ((int)coord.x + 1);
  tmp.y = coord.y - ((int)coord.y + 1);
  param[3] = gradient2[g[3]][0] * tmp.x + gradient2[g[3]][1] * tmp.y;
  val[2] = coord.x - (int)coord.x;
  c_coord.x = 3 * pow(val[2], 2) - 2 * pow(val[2], 3);
  val[0] = param[0] + c_coord.x * (param[1] - param[0]);
  val[1] = param[2] + c_coord.x * (param[3] - param[2]);
  val[2] = coord.y - (int)coord.y;
  c_coord.y = 3 * pow(val[2], 2) - 2 * pow(val[2], 3);
  return (val[0] + c_coord.y * (val[1] - val[0]));
}

double		noise2(t_vector2 coord)
{
  int		ii;
  int		jj;
  int		g[4];
  double	unit;
  float		gradient2[8][2];

  coord.x /= 200;
  coord.y /= 200;
  unit = 1.0 / sqrt(2);
  init_gradient(gradient2, unit);
  ii = (int)coord.x & 255;
  jj = (int)coord.y & 255;
  g[0] = p[ii + p[jj]] % 8;
  g[1] = p[ii + 1 + p[jj]] % 8;
  g[2] = p[ii + p[jj + 1]] % 8;
  g[3] = p[ii + 1 + p[jj + 1]] % 8;
  return (lets_calculate(gradient2, coord, g));
}
