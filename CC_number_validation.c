#include <cs50.h>
#include <stdio.h>
int checksum(long n);
int length(long n);
int first_two_dizits(long n);

int main(void)
{
    long n = get_long("Number: ");
    int check = checksum(n);
    int len = length(n);
    int dizit = first_two_dizits(n);

    if (check != 0)
    {
        printf("INVALID\n");
    }
    else
    {
        if (len == 16 && (dizit >= 51 && dizit <= 55))
        {
            printf("MASTERCARD\n");
        }
        else if (len == 15 && (dizit == 34 || dizit == 37))
        {
            printf("AMEX\n");
        }
        else if ((len == 13 || len == 16) && (dizit >= 40 && dizit <= 49))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
}

// calculating the length of the credit card number
int length(long n)
{
    int len = 0;
    do
    {
        n = n / 10;
        len += 1;
    }
    while (n > 0);
    return len;
}
// checking first two dizits of the number
int first_two_dizits(long n)
{
    while (n > 100)
    {
        n = n / 10;
    }

    return (int) n;
}

// checking validity of the credit card number
int checksum(long n)
{
    int total = 0;
    int counter = 1;
    int valid = 0;

    while (n > 0)
    {
        int digit = n % 10;
        n = n / 10;

        if (counter % 2 == 0)
        {
            int mul = digit * 2;
            if (mul >= 10)
            {
                total += (mul / 10) + (mul % 10);
            }
            else
            {
                total += mul;
            }
        }
        else
        {
            total += digit;
        }

        counter++;
    }
    int check = total % 10;
    return check;
}
