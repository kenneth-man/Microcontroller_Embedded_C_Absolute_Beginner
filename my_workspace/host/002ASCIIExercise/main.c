#include <stdio.h>

// takes 6 characters from user input and prints the ASCII codes of the characters
// user input characters seperated by space, tab or enter keys pressed
int main(void) {
	char c1, c2, c3, c4, c5, c6;

	printf("Enter 6 characters of your choice: ");

	scanf("%c %c %c %c %c %c", &c1, &c2, &c3, &c4, &c5, &c6);

	char chars[] = {c1, c2, c3, c4, c5, c6};

	printf("\nYour chars as ASCII codes: \n");

	for(size_t i = 0; i < sizeof(chars) / sizeof(chars[0]); ++i){
		printf("%d", chars[i]);
		printf(" ");
	}

	printf("\n\nPress the ENTER key to exit the program");

	// Flush the input buffer on the `\n` that remains and
	// Prevent termination until user presses `ENTER` key
	while(getchar() != '\n') {};
	getchar();
}
