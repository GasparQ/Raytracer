/*
** other.c for function other in /home/gaspar_q/Entrainement/Perlin
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Thu Jun  4 10:48:48 2015 quentin gasparotto
** Last update Thu Jun  4 11:37:39 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

static int p[512] = {151, 160, 137, 91, 90, 15, 131, 13, 201, 95, 96,
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
		     180,
		     151, 160, 137, 91, 90, 15, 131, 13, 201, 95, 96,
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

double	fade(double t)
{
  return (t * t * t * (t * (t * 6 - 15) + 10));
}

double	lerp(double t, double a, double b)
{
  return (a + t * (b - a));
}

double		grad(int hash, double x, double y, double z)
{
  int		h;
  double	u;
  double	v;

  h = hash & 15;
  u = (h < 8 || h == 12 || h == 13) ? x : y;
  v = (h < 4 || h == 12 || h == 13) ? y : z;
  return (((h & 1) == 0 ? u : -u) + ((h & 2) == 0 ? v : -v));
}

void	init_var(int *fl_oct, double *param, int *param_int,
		 t_vector3 *point)
{
  fl_oct[0] = (int)point->x & 255;
  fl_oct[1] = (int)point->y & 255;
  fl_oct[2] = (int)point->z & 255;
  point->x -= (int)point->x;
  point->y -= (int)point->y;
  point->z -= (int)point->z;
  param[0] = fade(point->x);
  param[1] = fade(point->y);
  param[2] = fade(point->z);
  param_int[0] = p[fl_oct[0]] + fl_oct[1];
  param_int[1] = p[param_int[0]] + fl_oct[2];
  param_int[2] = p[param_int[0] + 1] + fl_oct[2];
  param_int[3] = p[fl_oct[0] + 1] + fl_oct[1];
  param_int[4] = p[param_int[3]] + fl_oct[2];
  param_int[5] = p[param_int[3] + 1] + fl_oct[2];
}

double		noise(t_vector3 point)
{
  int		fl_oct[3];
  double	param[3];
  int		param_int[6];

  init_var(fl_oct, param, param_int, &point);
  return (lerp(param[2],
	       lerp(param[1],
		    lerp(param[0],
			 grad(p[param_int[1]], point.x, point.y, point.z),
			 grad(p[param_int[4]], point.x - 1, point.y, point.z)),
		    lerp(param[0],
			 grad(p[param_int[2]], point.x, point.y - 1, point.z),
			 grad(p[param_int[5]], point.x - 1, point.y - 1,
			      point.z))),
	       lerp(param[1],
		    lerp(param[0],
			 grad(p[param_int[1] + 1], point.x, point.y,
			      point.z - 1),
			 grad(p[param_int[4] + 1], point.x - 1, point.y,
			      point.z - 1)),
		    lerp(param[0],
			 grad(p[param_int[2] + 1], point.x, point.y - 1,
			      point.z - 1),
			 grad(p[param_int[5] + 1], point.x - 1, point.y - 1,
			      point.z - 1)))));
}
