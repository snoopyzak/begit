#include <stdio.h>

int	findf(int arr[], int l, int n)
{

	int index = -1;

	for(int i=0; i<l; i++)
	{
		if(arr[i] == n)
        {
			index = i;
		    break;
        }
	}
    if(index != -1)
        printf("Index of the first occurence of %d is : %d.", n, index);
    else
        printf("%d was not found in the array.", n);

	return 0;
}

int findl(int arr[], int l, int n)
{

    int index = -1;

    for(int i=l-1; i>=0; i--)
    {
        if(arr[i] == n)
        {
			index = i;
		    break;
        }
    }
    if(index != -1)
        printf("Index of the last occurence of %d is : %d.", n, index);
    else
        printf("%d was not found in the array.", n);

    return 0;
}

int findall(int arr[], int l, int n)
{
	int found = 0;

    for(int i = 0; i < l; i++)
    {
        if(arr[i] == n)
        {
            printf("%d occurred at index %d.\n", n, i);
            found = 1;
        }
    }

    if(!found)
        printf("%d was not found in the array.\n", n);

	return 0;
}