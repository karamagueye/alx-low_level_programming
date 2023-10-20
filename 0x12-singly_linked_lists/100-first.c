#include <stdio.h>
void first(void)__attribute__((constructor));
/**
 * a function that prints You're beat! and yet, 
 * you must allow,\nI bore my house upon my back!\n
 * Return: anything
 */
void first(void)
{
	printf("you're beat! and yrt, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
