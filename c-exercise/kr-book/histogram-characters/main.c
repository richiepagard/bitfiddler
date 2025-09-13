#include <stdio.h>

#define ARRAY_SIZE 26

void histogram_characters(void);


int main() {
    histogram_characters();

    return 0;
}


void histogram_characters(void) {
    int character;
    int letters[ARRAY_SIZE];

    // Fill the `letters` array
    for (int item = 0; item < ARRAY_SIZE; ++item) letters[item] = 0;

    while ((character = getchar()) != EOF)
    {
        // Check if the current character is alpha,
        // increment the place of the current character in the array (alphabet).
        if (character >= 'a' && character <= 'z') ++letters[character - 'a'];
        if (character >= 'A' && character <= 'Z') ++letters[character - 'A'];
    }

    for (int item = 0; item < ARRAY_SIZE; ++item)
    {
        // Only letters that appeared in the input
        if (letters[item] > 0) {
            // Convert the current letter to its place in alphabet
            if (letters[item] >= 'a' || letters[item] <= 'z') printf("[%c], ", item + 'a');
            if (letters[item] >= 'A' || letters[item] <= 'Z') printf("[%c]: ", item + 'A');

            // Print how many times the current letter appeared
            printf("%d", letters[item]);
            printf("\n");
        }
    }
}
