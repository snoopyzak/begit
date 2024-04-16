#include <stdio.h>

int	findf()
{
	int n;
	int arr[10];
	int index = -1;

	printf("Fill the arary with 10 elements: ");
	for(int i=0; i<10; i++)
		scanf("%d", arr[i]);
	printf("Choose the element to look for in the array: ");
	scanf("%d", n);
	for(int i=0; i<10; i++)
	{
		if(arr[i] = n)
			index = i;
		break;
	}
    if(index != -1)
        printf("Index of the first occurence of %d is : %d.", n, index);
    else
        printf("%d was not found in the array.", n);

	return 0;
}

int findl()
{
    int n;
    int arr[10];
    int index = -1;

    printf("Insert array elements: ");
    for(int i=0; i<10; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Insert element to look for: ");
    scanf("%d", &n);
    for(int i=9; i>=0; i--)
    {
        if(arr[i] == n)
            index = i;
        break;
    }
    if(index != -1)
        printf("Index of the last occurence of %d is : %d.", n, index);
    else
        printf("%d was not found in the array.", n);

    return 0;
}

int findall()
{
	int n;
	int arr[10];
	int index = -1;

	printf("Fill the arary with 10 elements: ");
	for(int i=0; i<10; i++)
		scanf("%d", arr[i]);
	printf("Choose the element to look for in the array: ");
	scanf("%d", n);
	for(int i=0; i<10; i++)
	{
		if(arr[i] = n)
        {
			index = i;
            printf("Element occured at index %d.", index);
        }
	}
    if(index == -1)
        printf("%d was not found in the array.", n);

	return 0;
}