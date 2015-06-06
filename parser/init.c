/*
** init.c for  in /home/veyrie_f/rendu/MUL_2014_rtracer
**
** Made by fernand veyrier
** Login   <veyrie_f@epitech.net>
**
** Started on  Sat Jun  6 11:44:17 2015 fernand veyrier
** Last update Sat Jun  6 11:44:51 2015 fernand veyrier
*/

#include "get_next_line.h"

int		init_rules_next(regex_t *regex)
{
  if (regcomp(&regex[17], TEXTURE_REG TEXTURE_NEXT, REG_EXTENDED)
      || regcomp(&regex[18], TEXTURE_CLOSE, REG_EXTENDED)
      || regcomp(&regex[19], ROTATION POS_NEXT, REG_EXTENDED)
      || regcomp(&regex[20], POSITION POS_NEXT, REG_EXTENDED)
      || regcomp(&regex[21], COLOR_REG COLOR_NEXT, REG_EXTENDED)
      || regcomp(&regex[22], DISTANCE_REG DISTANCE_NEXT, REG_EXTENDED)
      || regcomp(&regex[23], INTENSITY NBR_REG, REG_EXTENDED)
      || regcomp(&regex[24], RENDER_METHOD, REG_EXTENDED))
    return (-1);
  return (0);
}

int		init_rules(regex_t *regex)
{
  if (regcomp(&regex[0], HEADER, REG_EXTENDED)
      || regcomp(&regex[1], OBJECT_OPEN OBJECT_NEXT, REG_EXTENDED)
      || regcomp(&regex[2], OBJECT_CLOSE, REG_EXTENDED)
      || regcomp(&regex[3], MESH_OPEN MESH_OPEN_NEXT MESH_OPEN_LAST,
		 REG_EXTENDED)
      || regcomp(&regex[4], MESH_CLOSE, REG_EXTENDED)
      || regcomp(&regex[5], COORD_OPEN, REG_EXTENDED)
      || regcomp(&regex[6], COORD_CLOSE, REG_EXTENDED)
      || regcomp(&regex[7], PHONG_OPEN, REG_EXTENDED)
      || regcomp(&regex[8], PHONG_CLOSE, REG_EXTENDED)
      || regcomp(&regex[9], LIMIT_OPEN, REG_EXTENDED)
      || regcomp(&regex[10], LIMIT_CLOSE, REG_EXTENDED)
      || regcomp(&regex[11], SPOT, REG_EXTENDED)
      || regcomp(&regex[12], SPOT_CLOSE, REG_EXTENDED)
      || regcomp(&regex[13], SCENE, REG_EXTENDED)
      || regcomp(&regex[14], SCENE_CLOSE, REG_EXTENDED)
      || regcomp(&regex[15], EYE, REG_EXTENDED)
      || regcomp(&regex[16], EYE_CLOSE, REG_EXTENDED))
    return (fprintf(stderr, "Regex error.\n"));
  if (init_rules_next(regex) == -1)
    return (fprintf(stderr, "Regex error.\n"));
  return (0);
}
