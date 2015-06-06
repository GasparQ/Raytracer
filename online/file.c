/*
** file.c for  in /home/barrie_j/rayphp
**
** Made by Jean BARRIERE
** Login   <barrie_j@epitech.net>
**
** Started on  Wed Jun  3 17:00:54 2015 Jean BARRIERE
** Last update Sat Jun  6 12:21:43 2015 quentin gasparotto
*/

#include "../include/prototypes.h"

int	put_msg(int out, char *str, int ret)
{
  if (write(out, str, my_strlen(str)) <= 0)
    return (-1);
  return (ret);
}

void	*put_msg_ptr(int out, char *str, void *ret)
{
  if (write(out, str, my_strlen(str)) <= 0)
    return (NULL);
  return (ret);
}

char	*add_endl(char *str, int free_str)
{
  char	*ret;
  int	len;
  int	i;

  i = 0;
  len = my_strlen(str);
  if ((ret = malloc((len + 2) * sizeof(char))) == NULL)
    return (put_msg_ptr(2, ERR_MLOC, NULL));
  while (i < len)
    {
      ret[i] = str[i];
      ++i;
    }
  ret[i] = 10;
  ret[i + 1] = 0;
  if (free_str)
    free(str);
  return (ret);
}

/*
** WRITE FILE -> FILE = 'list.txt'
**            -> NAME = 'img.bmp'
**            -> APPEND = 0 SI TRUNC ET 1 SI APPEND
*/
int	write_file(char *file, char *name)
{
  int	fd;
  int	flags;

  if (name != NULL)
    {
      name = add_endl(name, 0);
      flags = O_CREAT | O_RDWR | O_APPEND;
      if ((fd = open(file, flags, 0666)) == -1)
	return (put_msg(2, ERR_OPEN, 0));
      if (write(fd, name, my_strlen(name)) <= 0)
	return (put_msg(2, ERR_OPEN, 0));
    }
  else
    {
      flags = O_CREAT | O_RDWR | O_TRUNC;
      if ((fd = open(file, flags, 0666)) == -1)
	return (put_msg(2, ERR_OPEN, 0));
    }
  close(fd);
  return (1);
}

int	put_to_server()
{
  int	spid;
  int	status;

  if ((spid = fork()) == -1)
    return (0);
  if (spid == 0)
    {
      execlp("/bin/php", "php", "./online/script.php", NULL);
      exit(1);
    }
  else
    {
      wait(&status);
      return (WIFEXITED(status));
    }
  return (0);
}
