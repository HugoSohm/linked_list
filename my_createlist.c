/*
** EPITECH PROJECT, 2017
** my_createlist.c
** File description:
** Made by Hugo SOHM
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

list_t	*push_back(list_t *list, char *str)
{
	list_t	*new_elem = malloc(sizeof(list_t));
	new_elem->str = str;
	new_elem->next = NULL;

	if (list == NULL) {
		new_elem->prev = NULL;
		return (new_elem);
	}

	list_t	*tmp = list;

	while (tmp->next != NULL) {
		tmp = tmp->next;
	}
	tmp->next = new_elem;
	new_elem->prev = tmp;
	return (list);
}

void	print_list(list_t *list)
{
	list_t	*tmp = list;

	while (tmp != NULL) {
		my_putstr(tmp->str);
		tmp = tmp->next;
	}
}

void	free_list(list_t *list)
{
	list_t	*tmp;

	while (list != NULL) {
		tmp = list;
		list = list->next;
		free(tmp);
	}
}

int	size_list(list_t *list)
{
	list_t	*tmp = list;
	int	len = 0;

	while (tmp != NULL) {
		tmp = tmp->next;
		len++;
	}
	return (len);
}

int main(int ac , char** av)
{
	int i = 1;
	list_t *list = NULL;
	while (i < ac)
	{
		list = push_back(list, av[i]);
		i++;
	}
	my_put_nbr(size_list(list));
	print_list(list);
	free_list(list);
	return (0);
}
