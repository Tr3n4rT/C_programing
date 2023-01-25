//Verify a credit card legitimacy for most VISA, MASTER CARD or AMERICAN EXPRESS card code.

#include <cs50.h>
#include <stdio.h>

int count_digits(long card_number);
int select_digit(long i);
int select_first_two(int digit_count, long card_number);
void card_brand(int first_two_digits);

int main(void)
{
    int digit;
    int first_digit_sum = 0;
    int second_digit_sum = 0;
    int first_two_digits;

    //Ask user for credit card number input
    long card_number = get_long("Card number:");

    //Count the number of digits entered by the user
    int digit_count = count_digits(card_number);

    //Loop that iterate on card number to remove one digit after one digit from last
    for (long i = card_number; i != 0; i = i / 100)
    {
        //Multiply by 2 every second to last digit
        digit = select_digit(i / 10) * 2;

        //Add every digit's product together
        second_digit_sum = second_digit_sum + digit / 10 + digit % 10;
    }

    //Loop that iterate on card number to remove every two last digit from last
    for (long i = card_number; i != 0; i = i / 100)
    {
        //Add every first last digit together
        first_digit_sum = select_digit(i) + first_digit_sum;
    }

    //Add two sums together
    int checksum = first_digit_sum + second_digit_sum;

    //Verify card legitimacy
    if (checksum % 10 == 0)
    {
        //Select the first two digits of card number
        first_two_digits = select_first_two(digit_count, card_number);
    }
    else
    {
        printf("INVALID\n");
        return 0;
    }
    //Print card type
    card_brand(first_two_digits);
}

int count_digits(long card_number)
{
    int i = 0;

    while (card_number != 0)
    {
        card_number = card_number / 10;
        i++;
    }
    return i;
}

int select_digit(long i)
{
    int digit;

    digit =  i % 10;
    return digit;
}

int select_first_two(int digit_count, long card_number)
{
    int first_two_digits;

    if (digit_count == 16)
    {
        first_two_digits = card_number / 100000000000000;
    }
    if (digit_count == 15)
    {
        first_two_digits = card_number / 10000000000000;
    }
    if (digit_count == 13)
    {
        first_two_digits = card_number / 100000000000;
    }
    return first_two_digits;
}

void card_brand(int first_two_digits)
{
    if (first_two_digits == 34 || first_two_digits == 37)
    {
        printf("AMEX\n");
    }
    else if (first_two_digits >= 51 && first_two_digits <= 55)
    {
        printf("MASTERCARD\n");
    }
    else if (first_two_digits >= 40 && first_two_digits <= 49)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}





