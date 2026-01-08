#include <stdio.h>

#define LOWER 0 /* lower bound of Fahr */
#define UPPER 300 /* upper bound of Fahr */
#define STEP 20 /* step size */

float FahrToCelsius(float fahr);

/* test FahrToCelsius */
int main(void)
{
	float fahr;
	int c;
	
	printf("Fahrenheit to Celsius table\n");
	for(fahr = LOWER; fahr <= UPPER; fahr += STEP)
		printf("%3.0f %6.1f\n", fahr, FahrToCelsius(fahr));
	
	printf("Enter a Fahreheit temperatur:");
	c = getchar();
	printf("The correspondence Celsius:%6.1f", FahrToCelsius(c));
	
	return 0;
}

/* change from Fahr to Celsius */
float FahrToCelsius(float fahr)
{
	float celsius;
	
	celsius = (5.0 / 9.0) * (fahr - 32.0);
	
	return celsius;
}