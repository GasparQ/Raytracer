/*
** obj_norms.c for object norms in /home/gaspar_q/rendu/semestre_2/Igraph/MUL_2014_rtv1
** 
** Made by quentin gasparotto
** Login   <gaspar_q@epitech.net>
** 
** Started on  Fri Mar  6 16:46:42 2015 quentin gasparotto
** Last update Wed Jun  3 15:24:55 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

void	init_sphere_norm(t_vector3 *sphere_norm,
			 t_vector3 isec_point, t_object *obj)
{
  sphere_norm->x = obj->rev_norm * isec_point.x;
  sphere_norm->y = obj->rev_norm * isec_point.y;
  sphere_norm->z = obj->rev_norm * isec_point.z;
}

void	init_plan_norm(t_vector3 *plan_norm,
		       t_vector3 isec_point, t_object *obj)
{
  (void)isec_point;
  (void)obj;
  plan_norm->x = obj->mesh.plan->norm.x;
  plan_norm->y = obj->mesh.plan->norm.y;
  plan_norm->z = obj->mesh.plan->norm.z;
}

void	init_cylinder_norm(t_vector3 *cylinder_norm,
			   t_vector3 isec_point, t_object *obj)
{
  cylinder_norm->x = obj->rev_norm * isec_point.x;
  cylinder_norm->y = obj->rev_norm * isec_point.y;
  cylinder_norm->z = 0.0;
}

void	init_cone_norm(t_vector3 *cone_norm,
		       t_vector3 isec_point, t_object *obj)
{
  cone_norm->x = obj->rev_norm * isec_point.x;
  cone_norm->y = obj->rev_norm * isec_point.y;
  cone_norm->z = obj->rev_norm * (-1.0) *
    pow(tan(obj->mesh.cone->phi), 2) * isec_point.z;
}

void	init_paraboloid_norm(t_vector3 *paraboloid_norm,
			     t_vector3 isec_point, t_object *obj)
{
  (void)obj;
  paraboloid_norm->x = obj->rev_norm * isec_point.x;
  paraboloid_norm->y = obj->rev_norm * isec_point.y;
  paraboloid_norm->z = -1.0;
}
