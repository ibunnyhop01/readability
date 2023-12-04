#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    float x = 0.0588;
    float y = 0.296;
    float z = 15.8;
    // Get the text from the user
    string text = get_string("Text: ");
    // printf("Text: %s\n", text);

    // count the numbers of letters used in the sentence
    int letters = count_letters(text);
    // printf("Letters:%i\n", letters);

    // count the amount of words;
    int words = count_words(text);
    // printf("Words:%i\n", words);

    // count the amount of sentences
    int sentences = count_sentences(text);
    // printf("Sentences:%i\n", sentences);

    // calculate L and S to find the grade
    float l = ((float) letters / (float) words * 100);
    float s = ((float) sentences / (float) words * 100);

    // printf("L: %f\n", l);
    // printf("S: %f\n", s);

    float grade = (x * l - y * s - z);

    // round the grade
    grade = round(grade);

    // print the grade Value
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %.lf\n", grade);
    }
}

int count_letters(string text)
{
    int letters = 0;
    // loop to count all the letters
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

int count_words(string text)
{
    // assume that the last part of the sentence has a word
    // assume that the text doesn't start with a space and does not contain multiple spaces in a row
    int words = 1;
    // loop to cound all the words
    for (int i = 0; i < strlen(text); i++)
    {
        if (isspace(text[i]))
        {
            words++;
        }
    }
    return words;
}

int count_sentences(string text)
{
    int sentences = 0;
    // loop to count sentences.
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;
}
