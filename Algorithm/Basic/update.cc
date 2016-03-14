/******************************************************************
* Content: Just update a item in the array
******************************************************************/
#include <stdio.h>

int main(){
    int arr[] = {3, 5, 6, 9, -1};
    int i = 0, n = 5;
    int item = 55, j = 4;

    printf("arr is:\n");

    for(i = 0; i < n; ++i){
        printf("arr[%d]:%d\n", i, arr[i]);
    }

    if(j < n){
        arr[j] = item;
    }

    printf("update arr is:\n");

    for(i = 0; i < n; ++i){
        printf("arr[%d]:%d\n", i, arr[i]);
    }
}
