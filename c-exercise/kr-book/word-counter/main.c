#include <stdio.h>

#define IN 1
#define OUT 0


void counter(void);

int main() {
	counter();

	return 0;
}


void counter(void) {
	/* Word counter function to count words which
	 * contain ASCII letters, it does not count words
	 * which only contain none ASCII letters.
	 *
	 * Explaination:
	 *		state = OUT: If the state is OUT, means we are outside the word
	 *			and when we are outside a word,
	 *			means we have just passed the last character of a word.
	 *		state = IN: If the state is IN, means we are inside the word
	 *			which means the current character is not a blank, tab, or newline.
	 */
	int character;
	int words_num;
	int state;

	state = IN;
	words_num = 0;
	while ((character = getchar()) != EOF)
	{
		// Check if the current character is a blank, tab, or newline
		// then update 'state' to OUT
		if (character == ' ' || character == '\t' || character == '\n') {
			state = OUT;
		}
		// Check if the state is OUT, increse the words-num
		// and upadte state to IN for counting the incoming word
		if (state == OUT) {
			++words_num;
			state = IN;
		}
	}

	printf("Words: %d\n", words_num);
}
