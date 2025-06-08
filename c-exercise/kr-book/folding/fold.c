#include <stdio.h>

#define LINELIMIT 10

void folding(int line_limit);

int main()
{
    folding(LINELIMIT);

    return 0;
}


void folding(int line_limit) {
    /*
    Fold a line at the specify position.

    Read input character by character while tracking the current column position with a counter.
    When reach the line limit, check if the last character is a space or tab, insert a newline,
    and print the rest of the line in the newline, repeat this until the last line character.
    Reset `counter` when insert a newline to start tracking with `0` again.
    */
    
    char buffer[line_limit + 1];

    int character;
    int counter, last_blank;

    counter = 0;
    last_blank = -1;
    while ((character = getchar()) != EOF)
    {
        // Fill the buffer character by character
        buffer[counter] = character;
        // Update `last_blank` to the current character position if reach to a blank
        if (character == ' ' || character == '\t') {
			last_blank = counter;
		}

        // Increment `counter` to go to the next posision
        ++counter;

        if (counter == line_limit)
		{
			if (last_blank != -1)
			{
				// Print characters in the buffer until the last blank
				for (int i = 0; i < last_blank; ++i) putchar(buffer[i]);
				putchar('\n');

				// Shift the remaining chrs to start of buffer
				int j = 0;
				for (int i = last_blank + 1; i < counter; ++i) buffer[j++] = buffer[i];

				// Update counter to number of leftover chars
				counter = j;
			}
			else
			{
				for (int i = 0; i < counter; ++i) putchar(buffer[i]);
				putchar('\n');

				counter = 0;
			}

			last_blank = -1;
		}
    }

	// Print any remaining characters
	for (int i = 0; i < counter; ++i) putchar(buffer[i]);
}
