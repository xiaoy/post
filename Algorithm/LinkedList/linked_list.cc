/****************************************************************************************************
* This program just play Singly linked list
****************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

struct SingleNode
{
    int item;
    struct SingleNode* next;
};

SingleNode* create_linklist_by_array(int* arr, int len);

SingleNode* free_linklist(SingleNode* node);

SingleNode* remove_node(SingleNode* head, SingleNode* node);

SingleNode* add_node(SingleNode* head, SingleNode* node);

SingleNode* get_node_by_value(SingleNode* head, int value);

SingleNode* reverse(SingleNode* head);

void print_linklist(SingleNode* head);

int main()
{
    int arr[] = {9, 7, 6, 5, 8, 4, 3};
    unsigned int arr_len = sizeof(arr) / sizeof(int);

    printf("arr:");
    int i;
    for(i = 0; i < arr_len; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("linked list:");
    SingleNode* head = create_linklist_by_array(arr, arr_len);
    print_linklist(head);

    int remove_item = 5;
    printf("linked list, remove item:%d\n", remove_item);
    SingleNode* find_item = get_node_by_value(head, remove_item);
    head = remove_node(head, find_item);
    print_linklist(head);

    printf("linked list, reverse:");
    head = reverse(head);
    print_linklist(head);

    head = free_linklist(head);
}

SingleNode* create_linklist_by_array(int* arr, int len)
{
    unsigned int i = 0;

    SingleNode* head = NULL;
    SingleNode* next = NULL;
    for(i = 0; i < len; ++i){
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

    return head;
}

SingleNode* remove_node(SingleNode* head, SingleNode* node)
{
    if(head == NULL || head == node)
    {
        return NULL;
    }

    SingleNode* cur = head;
    while(cur)
    {
        if(cur->next == node)
        {
            cur->next = cur->next->next;
            break;
        }
        cur = cur->next;
    }

    return head;
}

SingleNode* get_node_by_value(SingleNode* head, int value)
{
    SingleNode* cur = head;
    SingleNode* find_item = NULL;
    while(cur)
    {
        if(cur->item == value)
        {
            find_item = cur;
            break;
        }
        cur = cur->next;
    }

    return find_item;
}

SingleNode* add_node(SingleNode* head, SingleNode* node)
{
    if(head == NULL)
    {
        head = node;
    }
    else
    {
        SingleNode* cur = head;
        while(cur->next)
        {
            cur = cur->next;
        }
        cur->next = node;
        node->next = NULL;
    }

    return head;
}

SingleNode* reverse(SingleNode* head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }

    SingleNode* next_node = head;
    SingleNode* cur_node = NULL;
    SingleNode* temp_node = NULL;

    while(next_node)
    {
        temp_node = next_node->next;
        next_node->next = cur_node;
        cur_node = next_node;
        next_node = temp_node;
    }

    head = cur_node;

    return head;
}

SingleNode* free_linklist(SingleNode* head)
{
    SingleNode* cur = head;
    SingleNode* target = NULL;
    while(cur)
    {
        target = cur;
        cur = cur->next;
        free(target);
    }

    return NULL;
}

void print_linklist(SingleNode* head)
{
    while(head){
        printf("%d ", head->item);
        head = head->next;
    }
    printf("\n");
}
