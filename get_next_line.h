/*
** get_next_line.h for get_next_line in /home/rinaz_a/rendu/CPE_2015_getnextline
** 
** Made by selim rinaz
** Login   <rinaz_a@epitech.net>
** 
** Started on  Wed Jan 13 20:48:57 2016 selim rinaz
** Last update Sun Jan 17 01:23:23 2016 
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

# ifndef READ_SIZE
#  define READ_SIZE (32)
# endif /* !READ_SIZE */

static struct	s_data
{
  char		buf[READ_SIZE];
  int		idx;
  int		ret;
}		t_data;

typedef struct	s_tmp
{
  char		*line;
  int		kill;
  int		pos;
}		t_tmp;

char		*get_next_line(const int fd);
char		*alloc(int idx, int pos, char *buf, char *line);

#endif /* !GET_NEXT_LINE_H_ */
