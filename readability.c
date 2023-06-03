#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

float count_letters(string text, int str_length);
float count_words(string text, int str_length);
float count_sen(string text, int str_length);

int main(void)
{
    //Propmt for user input
    string text = get_string("Text: ");

    // Find length of text
    int length = strlen(text);

    int letters = count_letters(text, length);

    int words = count_words(text, length);

    int sens = count_sen(text, length);

    // Calculate the average number of letters and sentances per 100 words
    float L = ((100.0 / words) * letters);
    float S = ((100.0 / words) * sens);

    //calculate grade
    float index = 0.0588 * L - 0.296 * S - 15.8;
    index = round(index);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if(index > 0 && index < 16)
    {
        printf("Grade %i\n", (int) index);
    }
    else {
        printf("Grade 16+\n");
    }
}

//Function to calculate letters in the text given
float count_letters(string text, int str_length)
{
    int letters = 0;

    for (int i = 0; i < str_length; i++)
    {
        if(isalpha(text[i]) != 0)
        {
            letters++;
        }
    }

 return letters;

}


float count_words(string text, int str_length)
{
    int words = 0;

    for (int i = 0; i < str_length; i++)
    {
        if(text[i] == 32)
        {
            words++;
        }
    }
    return words+1;
}

float count_sen(string text, int str_length)
{
    int sens = 0;

    for (int i = 0; i < str_length; i++)
    {
        if(text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sens++;
        }
    }
    return sens;
}
