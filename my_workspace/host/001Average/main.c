#include <stdio.h>

int main(void) {
	float number1, number2, number3;
	float average;

	printf("Enter the first number: ");
	// We manually flush for eclipse console, but for windows terminal you don't need to
		// (depends on the console)
	// flushes `printf()` data stored in output buffer, to the console/display
	// we need to flush manually because `scanf()` waits for user input
	fflush(stdout);
	scanf("%f", &number1);

	printf("\nEnter the second number: ");
	fflush(stdout);
	scanf("%f", &number2);

	printf("\nEnter the third number: ");
	fflush(stdout);
	scanf("%f", &number3);

	average = (number1 + number2 + number3) / 3;

	printf("\nAverage is: %f", average);

	printf("\nPress the ENTER key to exit the program");

	// Flush the input buffer on the `\n` that remains
	getchar();

	// Prevent termination until user presses `ENTER` key
	while(getchar() != '\n') {};
}
