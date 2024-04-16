#include <stdio.h>

int    findf(int arr[], int n, int size)
{
    for(int i=0; i<size; i++)
    {
        if (n == arr[i])
            return i+1;
    }
    return -1;
}

int    findl(int arr[], int n, int size)
{
    for(int i=size-1; i>=0; i--)
        {
            if (n == arr[i])
                return i+1;
        }
        return -1;
}

void    findall(int arr[], int n, int size)
{
    int flag = 0;
    for(int i=0; i<size; i++)
    {
        if (n == arr[i])
        {
            printf("%d  ", i+1);
            flag = 1;
        }
    }
    if (!flag)
        printf("-1");
}

int main()
{
    int list[] = {3, 7, 8, 7, 34, -32, 0, 1, 3, 34, 3, 7, 8, 7, 34, -32, 0};
    // int list[] = {3, 7, 8, 7, 34, -32};
    int x = 34;
    int len = 17;

    /* int result = findl(list, x, len);
    if (result != -1)
        printf("findl for %d is at index(es): %d", x, result);
    else
        printf("%d was not found in the list", x);
    */

    printf("Indexes of %d in the list: ", x);
    findall(list, x, len);

    return 0;
}
