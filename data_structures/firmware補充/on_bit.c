#include <stdio.h>

void printBinary(int n);
int right_most(int n);
int on_bits(int n);

int main(void)
{
	int n;
	
	printf("Decimal number: ");
	scanf("%d", &n);
	printf("Binary representaion: ");
	printBinary(n);
	printf("Right most on-bit: ");
	printBinary(right_most(n));
	printf("Number of on-bits: %d\n", on_bits(n));
	
	return 0;
}

void printBinary(int n)
{
	for (int i = 7; i >= 0; i--) { // suppose n in binary not over 8 digits
		printf("%d", (n >> i) & 1);
	}
	printf("\n");
}

int right_most(int n)
{
	return n & (-n);
}

int on_bits(int n)
{
	int count = 0;
	
	while (n) {
		n = n & (n - 1); // n&(n-1) 等價於 n - n&(-n) 但左邊少一個運算
		count++;
	}
	
	return count;
}