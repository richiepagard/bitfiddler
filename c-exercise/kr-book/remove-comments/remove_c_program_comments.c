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
	char buffer[buffer_size];

	for (int counter = 0; (counter < 500) && ((character = getchar()) != EOF); ++counter) buffer[counter] = character;

	printf("%s\n", buffer);
}
