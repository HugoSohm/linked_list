/*
** EPITECH PROJECT, 2017
** my_putstr.c
** File description:
** my_putstr
*/

void my_putchar(char);

int my_putstr(char const *str)
{
	int i;

	for(i = 0; str[i] != '\0'; i ++) {
		my_putchar(str[i]);
	}
	my_putchar('\n');
	return (0);
}
