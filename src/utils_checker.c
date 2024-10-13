#include "push_swap.h"

/* is_digit:
*   Checks if the character is a digit.
*   Return: 1 if the character is a digit, 0 if not.
*/
int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

/* is_sign:
*   Checks if the character is number sign, + or -.
*   Return: 1 if the character is a sign, 0 if not.
*/
int	is_sign(char c)
{
	return (c == '+' || c == '-');
}

/* nbstr_cmp:
*   Compares two strings of digits to check if they are the same or not.
*   If one of the strings starts with a '+' sign, it is ignored and the rest
*   of the number string is checked.
*   This is so that +123 == 123 but -123 != 123.
*   Return: 0 if the strings match, another value if they do not.
*/
int	nbstr_cmp(const char *s1, const char *s2)
{
	int	a;
	int	b;

	a = ft_atoi(s1);
	b = ft_atoi(s2);
	return (a != b);
}