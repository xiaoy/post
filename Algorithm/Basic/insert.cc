/******************************************************************
* Notice:This program is just for fun, it is so simpled, but in this program
* You need notice the array has over the bound, it is dangers to write
* program like this.
* Content: Just insert a item to the array
******************************************************************/
#include <stdio.h>

int main(){
    int arr[] = {8, 10, 12, 23, 4, 43, 9, 20};
    int new_arr[] = {0};
    int i = 0, n = 8;
    int k = 3, item = 55, j = n;

    printf("original arr:\n");

    for(i = 0; i < n; ++i){
        printf("arr[%d]:%d\n", i, arr[i]);
    }


    n = n + 1;
    for(i = 0; i < n; ++i){
        if(k == i){
            new_arr[i] = item;
        }
        else if(i < k){
            new_arr[i] = arr[i];
        }else{
            new_arr[i] = arr[i - 1];
        }
    }

    printf("after insert:\n");
    for(i = 0; i < n; ++i){
        printf("arr[%d]:%d\n", i, new_arr[i]);
    }
}
