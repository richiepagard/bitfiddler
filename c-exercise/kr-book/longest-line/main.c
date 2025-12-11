#include <stdio.h>

#define MAX_LINE_SIZE 30

void longest_line(void);

int main() {
	longest_line();

	return 0;
}

void longest_line(void) {
	/* Reads input one line at a time, tracking each line’s full length even if it
	 * exceeds the buffer size. Prints the length of the longest line encountered
	 * and the portion of that line that fits in the buffer.
	 */

	int character;
	int auxiliary_counter, counter;
	int longest_line, line_nums;
	char buffer[MAX_LINE_SIZE], longest[MAX_LINE_SIZE];

	auxiliary_counter = counter = 0;
	longest_line = line_nums = 0;

	while ((character = getchar()) != EOF)
	{
		if (character == '\n') {
			++line_nums;

			// Check if the current amount of 'counter'
			// is bigger than 'longest-line' then, update
			// the 'longest-line' to the current 'counter' amount
			if (auxiliary_counter > longest_line) {
				longest_line = auxiliary_counter;
				// Copy characters from buffer to the longest-line array
				for (int i = 0; i < counter; ++i) {
					longest[i] = buffer[i];
				}
				longest[counter] = '\0';
			}

			buffer[counter] = '\0';
			auxiliary_counter = 0;
			counter = 0;
		}

		++auxiliary_counter;
		// Check if the current 'counter' value
		// less than 'max-line-size' to avoid
		// buffer-overfllow
		if (counter < MAX_LINE_SIZE-1) {
			buffer[counter++] = character;
		}
	}

	putchar('\n');
	printf("Longest Line: %d\nLines: %d\n\n", longest_line, line_nums);

	printf("Longest Line Content: \n- ");
	for (int i = 0; longest[i] != '\0'; ++i) putchar(longest[i]);
	putchar('\n');
}
