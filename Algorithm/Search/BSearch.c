#include <stdio.h>


int search(int* arr, int length, int item);

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int find_arr[] = {4, 8, 7, 3, 10, 12, 3, 9};

    int i;

    int arr_len = sizeof(arr) / sizeof(int);
    int find_arr_len = sizeof(find_arr) / sizeof(int);

    printf("the source arr:");
    for(i = 0; i < arr_len; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    for(i = 0; i < find_arr_len; ++i)
    {
        int item = find_arr[i];
        printf("item:%d", item);
        int index = search(arr, arr_len, item);
        if(index != -1)
        {
            printf(" was finded at %d\n", index);
        }
        else
        {
            printf(" not exist\n");
        }
    }
}

int search(int* arr, int length, int item)
{
    int start = 0;
    int end = length - 1;

    if(start == end || arr[start] == arr[end])
    {
        return -1;
    }


    while(end >= start)
    {
        int mid = start + (end - start)/ 2;
        if(item == arr[mid])
        {
            return mid;
        }
        else
        {
            if(item < arr[mid])
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }

    }

    return -1;
}



