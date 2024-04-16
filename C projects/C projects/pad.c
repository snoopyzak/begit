#include <stdio.h>

int    strlen(char *str)
{
    int count = 0;

    while(*str)
    {
        count++;
        str++;
    }
    return count;
}

void    padr(char str[], char pad, int des)
{
    int len;
    len = strlen(str);
    if (des <= len)
        return;
    else
    {
        while(len < des)
        {
            str[len] = pad;
            len++;
        }
        str[len] = '\0';
    }
}

void    padl(char str[], char pad, int des)
{
/*
    int len = strlen(str);

    if (des <= len)
        return;
    else
    {
        int padLen = des - len;
        int i;

        // Shift the string to the right to make space for padding
        for (i = len - 1; i >= 0; i--)
        {
            str[i + padLen] = str[i];
        }

        // Add padding characters
        for (i = 0; i < padLen; i++)
        {
            str[i] = pad;
        }
    }
*/
}

int main()
{
    char str[] = "hello";
    printf("Original string: %s\n", str);
    padr(str, 'X', 10);
    printf("Padded string: %s\n", str);
    return 0;
}