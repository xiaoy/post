/******************************************************************
* Content: Just search a item in the array
******************************************************************/
#include <stdio.h>

int main(){
    int arr[] = {3, 5, 6, 9, -1};
    int i = 0, n = 5;
    int item = 6, j = -1;

    printf("arr is:\n");

    for(i = 0; i < n; ++i){
        printf("arr[%d]:%d\n", i, arr[i]);
    }

    for(i = 0; i < n; ++i){
        if(arr[i] == item){
            j = i;
            break;
        }
    }

    if(j >= 0){
        printf("find the item:%d at position:%d\n", item, j);
    }else{
        printf("can not find the item:%d \n", item);
    }

}
