/*
** my_essentials.c for my_essentials in /home/rinaz_a/rendu/PSU_2015_my_select
** 
** Made by 
** Login   <rinaz_a@epitech.net>
** 
** Started on  Tue Dec  8 16:22:05 2015 
** Last update Thu Jan 14 15:57:39 2016 
*/

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int	my_strmodlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i = i + 1;
  return (i);
}

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  write(1, str, my_strmodlen(str));
}

void	my_putstr_2d(char **str)
{
  int	y;

  y = 0;
  while (str[y] != NULL)
    {
      write(1, str[y], my_strmodlen(str[y]));
      y = y + 1;
    }
}

void	my_puterr(char *str)
{
  write(2, str, my_strmodlen(str));
}
