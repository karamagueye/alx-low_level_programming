#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Description: This function prints the lowercase alphabet
 * and then prints the uppercase alphabet.
 *
 * Return: Always 0 (success)
 */
int main(void)
{
	char i;

	for (i = 'a'; i <= 'z'; i++)
	putchar(i);

	for (i = 'A'; i <= 'Z'; i++)
	putchar(i);

	putchar('\n');

	return (0);
}

