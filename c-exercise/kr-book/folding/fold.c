#include <stdio.h>

#define LINELIMIT 10

void folding(int line_limit);

int main()
{
    folding(LINELIMIT);

    return 0;
}


void folding(int line_limit)
{
    /*
    Fold a line at the specify position.

    Read input character by character while tracking the current column position with a counter.
    When reach the line limit, check if the last character is a space or tab, insert a newline,
    and print the rest of the line in the newline, repeat this until the last line character.
    Reset `counter` when insert a newline to start tracking with `0` again.
    */
    
    int character;
    int counter;

    counter = 0;
    while ((character = getchar()) != EOF)
    {
        if (counter >= line_limit)
        {
            if (character == ' ' || character == '\t') {
                putchar('\n');

                // Reset counter after inserting a newline
                counter = 0;

                // Skip the current space to avoid print a new folded line with a blank.
                continue;
            }
        }

        ++counter;
        putchar(character);
    }

    printf("\n");
}
