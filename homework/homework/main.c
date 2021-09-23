#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#include <stdbool.h>
int main()
{
	int8_t zero_flag = 0; // delites all zeros at the beggining of the number
	int decimal;
	int int_size = sizeof(int) * CHAR_BIT;
	int num; // number of signs
	bool binary[sizeof(int) * CHAR_BIT];
	scanf_s("%d%n", &decimal, &num);
	if (num > 11 && int_size == 32)
	{
		printf("A lot of signs");
		exit(-1);
	}
	if (num > 20 && int_size == 64)
	{
		printf("A lot of signs");
		exit(-1);
	}
	if (decimal< 0)
	{
		decimal *= -1;
		printf("-");
	}

	for(int j = int_size - 1 ; j >= 0; j--)
	{
		binary[j] = ((decimal & (1u << j)) >> j);
		if(binary[j] == 1)
		{
			zero_flag = 1;
		}
		if (zero_flag == 1)
		{
			printf("%d", binary[j]);
		}
	}
	exit(0);
}