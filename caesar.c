/****************************************************************************
 * caesar.c
 * Date: 07/11/2018
 * Course of study: Kunstmatige Intelligentie 2018/2019
 * Name: 
 * Student number: 
 * TA: Folkert Stijnman
 *
 * What it does:
 * Asks the user for a integer and an string input. It will encrypt the string input by adding the integer with each character of the string
 * If the user enters 1 A -> B, B -> C ect
 ***************************************************************************/

#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Let the user enter extra commands in the command line
int main(int argc, string argv[])
{
    //Check whether the amount of arguments the user enterd is exactly 2, which means that it is the calling of the program name with 1 extra argument
    if (argc != 2)
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }

    //argv[1] will get the second argument in the command line, 0 would get the first
    //We need the second because the first will always be the name of the program
    int k = atoi(argv[1]);

    //This will ask the user to enter the string he/she wants to encrypt
    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");

    //This for-loop will loop through each character of the string
    //I used strlen(plaintext) to get the length of the string the user entered so it cannot iterate further then the length of the string
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        //I used int and not char because I use the index of the ASCII code and later convert it back to the character assigned to the integer
        int newcharacter;

        //This will check whether the character assigned to the integer is not a character in the alpabet, with isalpha from ctype.h lib
        //If the character is not a character in the alphabet we don't want to add the change-index k with it
        //So we just keep the newcharacter the same as the old one
        if (!isalpha(plaintext[i]))
        {
            newcharacter = plaintext[i];
        }

        //Use isupper from the ctype lib to check if the character it currently is checking is uppercase
        //I do this because the ASCII indexes of uppercase character are different from the lowercase indexes
        if (isupper(plaintext[i]))
        {
            //Make the new character by adding the integer k with the index of the unencrypted character
            newcharacter = plaintext[i] + k;

            //Since the uppercase alphabet is only from ASCII index 65 to 90 we need to check if the newcharacter is greater then 90
            //Because if it is greater then 90 we need to wrap around "Z" and go back to "A"
            //We do this by substracting the index of the new character with 90 (index of "Z") and adding that with 64 (index of "A" - 1, we use -1 because we want to start at "A" again)
            //Check http://www.asciitable.com/ for ASCII indexes
            if (newcharacter > 90)
            {
                newcharacter = 64 + (newcharacter - 90);
            }
        }

        //Here we check if the current index is assigned to a lowercase character
        //We do almost the exact same in this if statement as we did in the uppercase if statement
        //The only difference is the range of indexes from ASCII
        if (islower(plaintext[i]))
        {
            newcharacter = plaintext[i] + k;
            while (newcharacter > 122)
            {
                newcharacter = 96 + (newcharacter - 122);
            }
        }

        //As last step we print the new character
        printf("%c", newcharacter);
    }

    //We print a newline after the encrypted word has been printed
    printf("\n");
    return 0;
}
