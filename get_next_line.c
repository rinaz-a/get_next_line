/*
** get_next_line.c for get_next_line in /home/rinaz_a/rendu/CPE_2015_getnextline
** 
** Made by selim rinaz
** Login   <rinaz_a@epitech.net>
** 
** Started on  Wed Jan 13 20:48:37 2016 selim rinaz
** Last update Sun Jan 17 01:18:18 2016 
*/

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

char		*my_alloc(char *buf, char *line, int idx, int pos)
{
  char		*new_line;
  int		i;

  i = 0;
  while ((line != NULL) && (line[i] != 0))
    i = i + 1;
  if ((new_line = malloc(i + ((idx + 1) - pos) + 1)) == NULL)
    return (NULL);
  i = 0;
  while ((line != NULL) && (line[i] != 0) && (i = i + 1))
    new_line[i - 1] = line[i - 1];
  while (pos <= idx)
    {
      if (buf[pos] == '\n')
	new_line[i] = '\0';
      else
	new_line[i] = buf[pos];
      i = i + 1;
      pos = pos + 1;
    }
  new_line[i] = '\0';
  if (line != NULL)
    free(line);
  return (new_line);
}

char			*get_next_line(const int fd)
{
  static struct	s_data	data;
  t_tmp			tmp;

  tmp.line = 0;
  tmp.kill = 0;
  tmp.pos = data.idx;
  while (tmp.kill == 0)
    {
      if ((data.idx == 0) && ((data.ret = read(fd, data.buf, READ_SIZE)) < 1))
	return (NULL);
      if (((data.buf[data.idx] == '\n') || (data.idx == (data.ret - 1)))
	  && ((tmp.line = my_alloc(data.buf, tmp.line, data.idx, tmp.pos)) == NULL))
	return (NULL);
      if ((data.buf[data.idx] == '\n')
	  || ((data.ret < READ_SIZE) && (data.idx == (data.ret - 1))))
	tmp.kill = 1;
      if (data.idx != (data.ret - 1))
	data.idx = data.idx + 1;
      else
	{
	  data.idx = 0;
	  tmp.pos = 0;
	}
    }
  return (tmp.line);
}
