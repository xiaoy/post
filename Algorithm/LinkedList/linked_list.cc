/****************************************************************************************************
* This program just play Singly linked list
****************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

struct SingleNode{
    int item;
    struct SingleNode* next;
};

int main(){
    int arr[] = {9, 7, 6, 5, 8};
    unsigned int i = 0;
    unsigned int arr_len = sizeof(arr) / sizeof(int);

    SingleNode* head = NULL;
    SingleNode* next = NULL;
    for(i = 0; i < arr_len; ++i){
        SingleNode* node = (struct SingleNode*)malloc(sizeof(SingleNode));
        node->item = arr[i];
        if(head == NULL){
            head = node;
            next = head;
        }else{
            next->next = node;
            next = node;
        }
    }
    next->next = NULL;

    while(head){
        printf("item:%d\n", head->item);
        head = head->next;
    }
}
