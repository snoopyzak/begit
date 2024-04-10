#include <stdio.h>
/*
we're supposed to find an element in an array through binary search
suppose the element is in the middle, if yes print the index if not
compare if less or more than mid then look for mid of either 0 to mid or mid to array_size-1
[i;*;*;mid;*;*;size-1]
*/
int dicho(int arr[], int least, int most, int n)
{
    while (least <= most)
    {
        int mid = least + (most-least)/2;
        if (arr[mid] == n)
            return mid;
        else if (arr[mid] < n)
            least = mid + 1;
        else
            most = mid - 1;
    }
    return -1;
}
int main()
{
    int arr[] = {-4, 1, 3, 4, 5, 7, 8, 9, 23, 30};
    int size = 10;
    int x = 23;
    int result = dicho(arr, 0, size-1, x);
    if (result == -1)
        printf("Number was not found");
    else
        printf("The number %d was found at index %d.", x, result);
    return 0;
}