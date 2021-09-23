#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define ARRAY_LEN 64
int main()
{
    char buffer, arr[ARRAY_LEN];
    int k = 0;
    // flag to check for the presence of the first number
    uint8_t first_number_exist = 0;
    // flag to check for the presence of a vertical bar
    uint8_t second_number_check = 0;
    // flag to check for the presence of the second number
    uint8_t second_number_exist = 0;
    while (
        (buffer = getchar()) != EOF &&
        buffer != '\n' &&
        buffer != '\0')
    {
        switch (buffer)
        {
            case '-':
                if (k == 0)
                {
                    arr[k] = buffer;
                }
                else
                {
                    printf("\nInput error");
                    exit(-1);
                }
                break;

            case ' ':
                break;

            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                arr[k] = buffer;
                if (second_number_check == 0)
                {
                    first_number_exist = 1;
                }
                if (second_number_check == 1)
                {
                    second_number_exist = 1;
                }
                k++;
                break;

            case '|':
                if(second_number_check == 1)
                {
                    printf("\nInput error");
                    exit(-1);
                }
                arr[k] ='.';
                k++;
                second_number_check = 1;
                break;

            default:
                printf("\nInput error");
                exit(-1);
        }

        if (k >= ARRAY_LEN)
        {
            printf("\nInput error");
            exit(-1);
        }
    }
    arr[k] = '\0';
    if (first_number_exist == 1 &&
        second_number_exist == 1)
    {
        printf("%s", arr);
    }
    else
    {
        printf("\nmissing second number");
        exit(-1);
    }
    exit(0);
}