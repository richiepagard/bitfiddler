#include <stdio.h>


void counter(void);

int main() {
	counter();

	return 0;
}


void counter(void) {
	int character;
	int words_num;

	while ((character = getchar()) != EOF)
	{
		putchar(character);
	}
}
