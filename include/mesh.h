/*
** mesh.h for mesh in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtv1
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Wed Feb 11 16:03:34 2015 quentin gasparotto
** Last update Thu May 28 15:55:01 2015 quentin gasparotto
*/

#ifndef MESH_H_
# define MESH_H_

typedef struct	s_vector2
{
  double	x;
  double	y;
}		t_vector2;

typedef struct	s_vector3
{
  double	x;
  double	y;
  double	z;
}		t_vector3;

typedef struct	s_eye
{
  t_vector3	pos;
  t_vector3	dir;
  int	        distance;
}		t_eye;

typedef struct	s_streight
{
  t_vector3	dir;
  t_vector3	point;
  double	lambda;
}		t_streight;

typedef struct	s_hyperboloid
{
  double	a;
  double	b;
  double	c;
  double	d;
  double	c_factor;
}		t_hyperboloid;

typedef struct	s_moebius
{
  double	radius;
  double	nb_tors;
  double	tors_angle;
}		t_moebius;

typedef struct	s_tore
{
  double	ex_r;
  double	int_r;
}		t_tore;

typedef struct	s_paraboloid
{
  double	cte;
}		t_paraboloid;

typedef struct	s_sphere
{
  double	radius;
}		t_sphere;

typedef struct	s_plan
{
  t_vector3	norm;
  double	d;
}		t_plan;

typedef struct	s_cylinder
{
  double	radius;
  t_vector3	limit[2];
}		t_cylinder;

typedef struct	s_cone
{
  double	phi;
  t_vector3	limit[2];
}		t_cone;

typedef struct	s_holed_cube
{
  double	cote;
  double	hole_prop;
}		t_holed_cube;

typedef struct	s_mesh
{
  t_plan	*plan;
  t_sphere	*sphere;
  t_cylinder	*cylinder;
  t_cone	*cone;
  t_paraboloid	*paraboloid;
  t_holed_cube	*holed_cube;
  t_tore	*tore;
  t_moebius	*moebius;
  t_hyperboloid	*hyperboloid;
}		t_mesh;

typedef struct		s_object
{
  int			rev_norm;
  t_vector3		origin;
  t_vector3		rotation;
  int			obj_color;
  unsigned char		*disp_color;
  double		brightness;
  double		opacity;
  double		middle_ind;
  double	        reflect;
  t_mesh		mesh;
  double		(*shape_resolver)(t_streight, struct s_object *);
  void			(*free_mesh)(t_mesh);
  void			(*init)(t_vector3 *, t_vector3, struct s_object *);
  struct s_object	*limit;
  struct s_object	*next;
}			t_object;

typedef struct	s_spot
{
  t_vector3	origin;
  unsigned char	*color;
  struct s_spot	*next;
}		t_spot;

#endif /* !MESH_H_ */
