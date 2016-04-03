#include <stdio.h>

#define MAX 10

int arr[MAX] = {10, 14, 18, 22, 25, 30, 32, 37, 40, 41};

int find(int item)
{
    int start = 0;
    int end = MAX - 1;
    int mid = -1;

    while(start <= end)
    {
        printf("start:%d arr[%d]:%d\n", start, start, arr[start]);
        printf("end:%d arr[%d]:%d\n", end, end, arr[end]);
        mid = start + (((double)(end - start)) / (arr[end] - arr[start])) * (item - arr[start]);
        printf("mid:%d, arr[%d]:%d\n", mid, mid, arr[mid]);

        if(arr[mid] == item)
        {
            return mid;
        }
        else
        {
            if(arr[mid] < item)
            {
                start = mid + 1;
            }
            else
            {
                 end = mid - 1;
            }
        }
    }

    return - 1;
}

int main()
{
     int item = 25;
     printf("find item %d at index %d\n", item, find(item));
}
