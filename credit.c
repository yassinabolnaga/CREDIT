#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long card_number;
    do
    {
        card_number = get_long("Enter your visa number: ");
    }
    while (card_number < 0);

    int card1, card2, card3, card4, card5, card6, card7, card8;

    card1 = ((card_number % 100)/10*2);
    card2 = ((card_number % 10000)/1000*2);
    card3 = ((card_number % 1000000)/100000*2);
    card4 = ((card_number % 100000000)/10000000*2);
    card5 = ((card_number % 10000000000)/1000000000*2);
    card6 = ((card_number % 1000000000000)/100000000000*2);
    card7 = ((card_number % 100000000000000)/10000000000000*2);
    card8 = ((card_number % 10000000000000000)/1000000000000000*2);

// add digits together for example if 12 ---> 1+2 not 12
    card1 = (card1 % 10) + (card1 % 100/10);
    card2 = (card2 % 10) + (card2 % 100/10);
    card3 = (card3 % 10) + (card3 % 100/10);
    card4 = (card4 % 10) + (card4 % 100/10);
    card5 = (card5 % 10) + (card5 % 100/10);
    card6 = (card6 % 10) + (card6 % 100/10);
    card7 = (card7 % 10) + (card7 % 100/10);
    card8 = (card8 % 10) + (card8 % 100/10);

    int sum1 = card1 + card2 + card3 + card4 + card5 + card6 + card7 + card8;

    int card9, card10, card11, card12, card13, card14, card15, card16;

    card9 = (card_number % 10);
    card10 = ((card_number % 1000)/100);
    card11 = ((card_number % 100000)/10000);
    card12 = ((card_number % 10000000)/1000000);
    card13 = ((card_number % 1000000000)/100000000);
    card14 = ((card_number % 100000000000)/10000000000);
    card15 = ((card_number % 10000000000000)/1000000000000);
    card16 = ((card_number % 1000000000000000)/100000000000000);

    int sum2 = card9 + card10 + card11 + card12 + card13 + card14 + card15 + card16;

    int sum3 = sum1 + sum2;

    int length = 0;
    long visa = card_number;
    long mastercard = card_number;
    long amex = card_number;


    if ((sum3 % 10)!=0)
    {
        printf("%s\n", "INVALID");
        return 0;
    }

    // we need to differentiate between Visa, Amex, Master Card
    // length دي بتعد الفيزا دي كام رقم
    while (card_number > 0)
    {
        card_number = card_number / 10;
        length++;
    }
    //identify visa
    while (visa >= 10)
    {
        visa /= 10;
    }
    if (visa == 4 && (length == 13 || length == 16))
    {
        printf("%s\n", "VISA");
        return 0;
    }
    //identify amex
    while (amex >= 10000000000000 )
    {
        amex /= 10000000000000;
    }
    if (length == 15 && (amex == 34 || amex == 37))
    {
         printf("%s\n", "AMEX");
         return 0;
    }
    //identify Master
    while (mastercard >= 100000000000000 )
    {
        mastercard /= 100000000000000;
    }
    if (length == 16 && (mastercard == 51 || mastercard == 52 || mastercard == 53 || mastercard == 54 || mastercard == 55))
    {
         printf("%s\n", "MASTERCARD");
         return 0;
    }
    else
    printf("%s\n", "INVALID");
    return 0;

}
