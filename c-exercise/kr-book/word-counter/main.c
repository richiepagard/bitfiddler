#include <stdio.h>


void counter(void);

int main() {
	counter();

	return 0;
}


void counter(void) {
	/* Word counter function to count words which
	 * contain ASCII letters, it does not count words
	 * which only contain none ASCII letters.
	 */
	int character;
	int words_num;

	while ((character = getchar()) != EOF)
	{
		putchar(character);
	}
}
