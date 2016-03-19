#include <stdlib.h>
#include <stdio.h>

struct DoubleLinkedNode
{
    int item;
    DoubleLinkedNode* prev;
    DoubleLinkedNode* next;
};

DoubleLinkedNode* push_back(DoubleLinkedNode* head, int item);

DoubleLinkedNode* new_node();

void print_linked_list(DoubleLinkedNode* head);

int main()
{
    int arr[] = {9, 8, 6, 4, 3};
    int i;
    int arr_len = sizeof(arr) / sizeof(int);

    DoubleLinkedNode* head = NULL;

    for(i = 0; i < arr_len; ++i)
    {
        head = push_back(head, arr[i]);
    }

    print_linked_list(head);
}

DoubleLinkedNode* new_node()
{
    return (DoubleLinkedNode*)malloc(sizeof(DoubleLinkedNode));
}

DoubleLinkedNode* push_back(DoubleLinkedNode* head, int item)
{
    DoubleLinkedNode* cur = head;
    if(cur == NULL)
    {
        cur = new_node();
        cur->prev = NULL;
        cur->next = NULL;
        cur->item = item;
        return cur;
    }

    while(cur)
    {
        if(cur->next == NULL)
        {
            cur->next = new_node();
            cur->next->prev = cur;
            cur->next->next = NULL;
            cur->next->item = item;
            break;
        }

        cur = cur->next;
    }

    return head;
}

void print_linked_list(DoubleLinkedNode* head)
{
    DoubleLinkedNode* cur = head;
    while(cur)
    {
        printf("item:%d\n", cur->item);
        cur = cur->next;
    }
}
