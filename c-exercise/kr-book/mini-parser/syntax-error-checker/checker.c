#include <stdio.h>


void syntaxErrorChecker(void);

int main() {
	syntaxErrorChecker();

	return 0;
}


void syntaxErrorChecker(void) {
	int character;

	while ((character = getchar()) != EOF)
	{
		putchar(character);
	}
}

