# include <stdio.h>

/* using define to avoid magic numbers */

#define LOWER 0 /* lower bound of table */
#define UPPER 300 /* upper bound */
#define STEP 20 /* step size */

int main()
{
	float fahr;
	
	for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
		printf("%3.0f %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32.0));
	
	return 0;
}