#include <stdio.h>

int main(void) {
	float number1, number2, number3;
	float average;

	printf("Enter 3 numbers: ");
	scanf("%f %f %f", &number1, &number2, &number3);

	average = (number1 + number2 + number3) / 3;

	printf("\nAverage is: %f", average);

	printf("\nPress the ENTER key to exit the program");

	// Flush the input buffer on the `\n` that remains
	getchar();

	// Prevent termination until user presses `ENTER` key
	while(getchar() != '\n') {};
}
