#include <stdio.h>

void digit_counter();

int main() {
	digit_counter();

	return 0;
}


void digit_counter() {
	/* Count digits in the user input.
	 * This function reads characters from the standard input until `EOF`.
	 * It counts how many times each digit (0-9) appears.
	 * Also, track spaces, digits, and other characters.
	 *
	 * Arguments:
	 *		character (int): User input :/.
	 *		number_digit (int): Numbers of digits in the input.
	 *		number_space (int): Numbers of spaces in the input.
	 *		number_others (int): Numbers of other characters in the input.
	 *		digits (integer array): Keep digits 0-9 in itself.
	 */

	int character;
	int number_digit, number_space, number_other;
	int digits[10];

	// Fill the digits array
	for (int counter = 0; counter < 10; ++counter) digits[counter] = 0;

	number_digit = number_space = number_other = 0;
	while ((character = getchar()) != EOF)
	{
		// Check if the current character is a digit between 0-9
		if (character >= '0' && character <= '9') {
			// Increse the count of the current digit in the array
			++digits[character - '0'];
			// Increment total digit count
			++number_digit;
		}
		// Check if the current character is space/tab/newline, increse the number_space quantity
		else if (character == ' ' || character == '\t' || character == '\n') ++number_space;
		// Otherwise, increse number_other quantity
		else ++number_other;
	}

	// Traverse on range 0...9 for print the digits array elements
	for (int counter = 0; counter < 10; ++counter)
	{
		// Only print digits that appeared at least once
		if (digits[counter] > 0) {
			printf("%d: ", counter);
			// Print how many times this digit appeared
			printf("%d Repetitions.", digits[counter]);
			printf("\n");
		}
	}

	// Print total counts of spaces, digits, and other characters
	printf("\nSpaces: %d\tDigits: %d\tOthers: %d\n", number_space, number_digit, number_other);
}
