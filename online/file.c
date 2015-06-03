/*
** file.c for  in /home/barrie_j/rayphp
**
** Made by Jean BARRIERE
** Login   <barrie_j@epitech.net>
**
** Started on  Wed Jun  3 17:00:54 2015 Jean BARRIERE
** Last update Wed Jun  3 17:59:23 2015 Jean BARRIERE
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>



#define ERR_OPEN	"Error: cannot open() file\n"
#define ERR_MLOC	"Error: cannot perform malloc\n"
#define USAGE		"usage : ./wr_file FILE LINE APPEND ? (0:TRUC 1:APPEND)\n"






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

/* CALL write_file for each bmp image */

/*
** WRITE FILE -> FILE = 'list.txt'
**            -> NAME = 'img.bmp'
**            -> APPEND = 0 SI TRUNC ET 1 SI APPEND
*/

int	write_file(char *file, char *name, int append)
{
  int	fd;
  int	flags;

  name = add_endl(name, 0);
  flags = O_CREAT | O_RDWR | (append == 0 ? O_TRUNC : O_APPEND);
  if ((fd = open(file, flags, 0666)) == -1)
    return (put_msg(2, ERR_OPEN, 0));
  if (write(fd, name, my_strlen(name)) <= 0)
    return (put_msg(2, ERR_OPEN, 0));
  return (1);
}






/* CALL put_to_server() to upload list.txt and its bmp to server */


int	put_to_server()
{
  int	spid;
  int	wpid;

  if ((spid = fork()) == -1)
    return (0);
  if (spid == 0)
    {
      if (execlp("/bin/php", "php", "script.php", 0) == -1)
	return (0);
    }
  else
    {
      wpid = 0;
      waitpid(spid, &wpid, WSTOPPED);
      return (1);
    }
  return (0);
}
