#include <stdio.h>


#define BUFFER_SIZE 500


void commentRemover(int bufer_size);

int main() {
	commentRemover(BUFFER_SIZE);

	return 0;
}


void commentRemover(int buffer_size) {
	/*
	 * Reads C source code from input and removes comments.
	 * Output is the cleaned (no comment) version of the input.
	 */
	int character;
	int counter;
	char buffer[buffer_size];
	char output[buffer_size];

	// Fill the buffer character by character with input
	for (counter = 0; (counter < buffer_size-1) && ((character = getchar()) != EOF); ++counter) buffer[counter] = character;

	// If newline is encountered, store it in the buffer
	if (character == '\n')
	{
		buffer[counter] = character;
		++counter;
	}

	// Set null-terminate to the string
	buffer[counter] = '\0';

	int i = 0, j = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '/' && buffer[i + 1] == '/')
		{
			// Skip the rest of the current line to ignore the single-line comments
			while (buffer[i] != '\n' && buffer[i] != '\0') ++i;
			// Skip the newline/tab after comment to avoid affecting the next line
			continue;
		}
		else
		{
			// Copy the character to the output buffer 
			output[j] = buffer[i];
			++j;
		}

		if (buffer[i] != '\0') ++i;
	}

	output[j] = '\0';

	printf("------------------\n");
	printf("The Cleaner Version Of The Input: \n\n```c\n");
	printf("%s", output);
	printf("```\n");
}
