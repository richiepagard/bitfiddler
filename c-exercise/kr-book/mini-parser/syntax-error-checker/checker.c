#include <stdio.h>


void syntax_error_checker(void);

int main() {
	syntax_error_checker();

	return 0;
}


void syntax_error_checker(void) {
	int character;

	while ((character = getchar()) != EOF)
	{
		putchar(character);
	}
}
