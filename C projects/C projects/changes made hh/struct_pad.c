#include <stdio.h>

struct StringPadding
{
    char value[100];
};

void padLeft(struct StringPadding *str, size_t totalLength, char padChar)
{
    size_t len = 0;
    while (str.value[len] != '\0')
    {
        len++;
    }

    if (totalLength > len)
    {
        size_t padLength = totalLength - len;
        if (padLength >= sizeof(str.value))
        {
            printf("Error: Padding exceeds maximum length\n");
            return;
        }
        for (size_t i = len; i > 0; i--)
        {
            str.value[i + padLength - 1] = str.value[i - 1];
        }
        for (size_t i = 0; i < padLength; i++)
        {
            str.value[i] = padChar;
        }
    }
}

void padRight(struct StringPadding *str, size_t totalLength, char padChar)
{
    size_t len = 0;
    while (str.value[len] != '\0')
    {
        len++;
    }

    if (totalLength > len)
    {
        size_t padLength = totalLength - len;
        if (padLength >= sizeof(str.value))
        {
            printf("Error: Padding exceeds maximum length\n");
            return;
        }
        for (size_t i = len; i < len + padLength; i++)
        {
            str.value[i] = padChar;
        }
        str.value[len + padLength] = '\0';
    }
}

int main()
{
    struct StringPadding paddedString;
    sprintf(paddedString.value, "%s", "hello");

    printf("Before padding: %s\n", paddedString.value);

    padLeft(&paddedString, 10, '-');
    printf("After left padding: %s\n", paddedString.value);

    padRight(&paddedString, 15, '-');
    printf("After right padding: %s\n", paddedString.value);

    return 0;
}
