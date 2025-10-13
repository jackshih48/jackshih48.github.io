# include <stdio.h>

/* print a celsius to Fahrenheit table
	for celsius = 0, 10, ..., 100 */

int main()
{
	float celsius, fahr;
	float lower, upper, step;
	
	lower = 0; /* lower bound of celsius */
	upper = 100; /* upper bound of celsius */
	step = 10; /* step size */
	
	printf("celsius to Fahrenheit table\n");
	celsius = lower;
	while (celsius <= upper) {
		fahr = 9.0 / 5.0 * celsius + 32.0;
		printf("%3.0f %5.1f\n", celsius, fahr);
		celsius = celsius + step;
	}
	
	return 0;
}