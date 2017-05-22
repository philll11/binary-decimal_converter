#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void decToBin(int dec, char* bin);
int binToDec(char userInput[]);

int main(void)
{
    char input[50], output[50];
    bool numbers = true;
    bool dec = true;
    bool bin = false;
    int result = 0;
    int i;

    printf("Enter a number: ");
    gets(input);

    //  Finding the length of the string array.
    int inLgth = strlen(input);

    for(i = 0; i < inLgth; i++)
    {
        //  Checks input is contains all numbers.
        if(input[i] >= '0' && input[i] <= '9')
        {
            //  Checks if input is decimal.
            if(input[i] >= '2' && input[i] <= '9')
            {
                dec = true;
                bin = false;
            }
            //  Checks if binary but user could mean decimal one hundred and one or binary one zero one.
            if(input[i] == '0' || input[i] == '1')
            {
                bin = true;
            }
        }
        else
        {
            numbers = false;
            break;
        }
    }

    if(numbers == true)
    {
        if (inLgth <= 8)
        {
            //  Transfers char array to int value.
            sscanf(input, "%d", &result);

            if(dec == true && bin == true)
            {
                printf("\nIs this number decimal (d) or binary (b)?\n");
                char check = getchar();

                if (check == 'd')
                {
                    if(result >= 0 && result <= 255)
                    {
                        //  Convert decimal to binary.
                        decToBin(result, output);
                        printf("Converting decimal to binary. Answer is: %s", output);
                    }
                    else
                    {
                        printf("That is an invalid number!");
                    }
                }
                else if (check == 'b')
                {
                    if (inLgth <= 8)
                    {
                        //  Convert binary to decimal
                        result = binToDec(input);
                        printf("Converting binary to decimal. Answer is: %d", result);
                    }
                    else
                    {
                        printf("That is an invalid number!");
                    }
                }
                else
                {
                    printf("That is an invalid number!");
                }
            }
            else if (dec == true && bin == false)
            {
                //  Convert decimal to binary
                if(result >= 0 && result <= 255)
                {
                    //  Convert decimal to binary.
                    decToBin(result, output);
                    printf("Converting decimal to binary. Answer is: %s", output);
                }
                else
                {
                    printf("That is an invalid number!");
                }
            }
            else if (dec == false && bin == true)
            {

                if (inLgth <= 8)
                {
                    //  Convert binary to decimal
                    result = binToDec(input);
                    printf("Converting binary to decimal. Answer is: %d", result);
                }
                else
                {
                    printf("That is an invalid number!");
                }
            }

        }
        else
        {
            printf("That is an invalid number!");
        }
    }
    else
    {
        printf("That is an invalid number!");
    }
    return 0;
}

void decToBin(int dec, char* bin)
{
    bin[8] = '\0';
    int power = 128;
    int i;

    for (i = 0; i < 8; i++)
    {
        if(dec >= power)
        {
            bin[i] = '1';
            dec -= power;
        }
        else
        {
            bin[i] = '0';
        }
        power /= 2;
    }
    return;
}

int binToDec(char userInput[])
{
    int sum = 0;
    int power = 1;
    int length = strlen(userInput);
    int i;

    for (i = length - 1; i >= 0; i--)
    {
        if (userInput[i] == '1')
        {
            sum += power;
        }
        power *= 2;
    }
    return sum;
}









