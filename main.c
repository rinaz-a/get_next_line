/*
** main.c for main in /home/rinaz_a/rendu/get_next_line
** 
** Made by selim rinaz
** Login   <rinaz_a@epitech.net>
** 
** Started on  Wed Jan  6 18:49:43 2016 selim rinaz
** Last update Sun Jan 17 01:13:17 2016 
*/

#include "get_next_line.h"

int	main()
{
  char *str;

  while (str = get_next_line(0))
    printf("%s\n", str);
}
