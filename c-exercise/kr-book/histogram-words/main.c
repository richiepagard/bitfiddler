#include <stdio.h>

#define IN 1
#define OUT 0
#define MAX_WORD_LENGTH_SIZE 13


void word_length(void);


int main() {
	word_length();

	return 0;
}

void word_length(void) {
	/*
	Reads a stream of characters from standard input and counts the length of each word.
	Stores the lengths in an array and prints the lengths of the words.
	Then, prints the histogram of the word lengths.

	Note:
		state (int): Tracks whether we're inside or outside a word.
		word_length (int): Counts the lengths of the current word.
		word_lengths (int[]): Stores the lengths of the words.
		word_count (int): Counts the number of words.
		MAX_WORD_LENGTH_SIZE (int): The maximum number of words to be counted.
	*/

	int character;
	int state = OUT;
	int word_length = 0, word_count = 0;

	int word_lengths[MAX_WORD_LENGTH_SIZE];

	for (int i = 0; i < MAX_WORD_LENGTH_SIZE; ++i) word_lengths[i] = 0;

	while ((character = getchar()) != EOF)
	{
		// If space/tab/newline, end of current word
		if (character == ' ' || character == '\t' || character == '\n') {
			// Save the current word's length to the array
			if (word_count < MAX_WORD_LENGTH_SIZE) {
				word_lengths[word_count] = word_length;
				++word_count;
			}

			// Reset word_length to prepare it for the next word length
			word_length = 0;
			// Update state: we're outside a word now
			state = OUT;
		}

		// Check if the current character is an ACII letter,
		// If it is, save it to the buffer
		if ( (character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z') ) ++word_length;
	}

	for (int i = 0; i < MAX_WORD_LENGTH_SIZE; ++i)
	{
		int is_duplicate = 0;

		for (int j = 0; j < i; ++j)
		{
			// Check duplicate element in the array
			if (word_lengths[i] == word_lengths[j]) {
				is_duplicate = 1;
				break;
			}
		}

		if (!is_duplicate && word_lengths[i] > 0)
		{
			printf("%d: ", word_lengths[i]);

			// Count how many times this word length appears
			for (int counter = 0; counter < MAX_WORD_LENGTH_SIZE; ++counter) {
				if (word_lengths[counter] == word_lengths[i]) printf("*");
			}
			printf("\n");
		}
	}
}
